#include "GamePlay.h"
#include "Model/Skater.h"
#include "View/Object_Layer.h"
#include "Model/Car.h"
#include "Utility/Tags.h"
#include "View/Start_Scene.h"
#include "View/End_Scene.h"
#include <sstream>
#include "Utility/Config.h"
using namespace std;

GamePlay::GamePlay()
{
}


GamePlay::~GamePlay()
{
}


bool GamePlay::init()
{
	if (!Layer::init()) return false;

	//Best Score
	bestScore = 0;

	//Back button
	this->setKeypadEnabled(true);
	this->setKeyboardEnabled(true);

	//Xử lý Touch
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GamePlay::onTouchBegan, this);
	//_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

	//Jump Button
	jump_Button = Button::create("Button/Jump_Button.png", "Button/Jump_Button_Selected.png", "Button/Jump_Button_Selected.png");
	jump_Button->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	jump_Button->setOpacity(128);
	jump_Button->setScale(0.6);
	jump_Button->setPosition(Point(Config::screenSize.width, jump_Button->getContentSize().width/2));
	jump_Button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			if (object_Layer->skater->isDeath == false && object_Layer->skater->isJumping == false)
				{
					object_Layer->skater->jump_Action();
				}
			else if (object_Layer->skater->isDeath == false && object_Layer->skater->isJumping == true && object_Layer->skater->isDoubleJump == true)
				{
					object_Layer->skater->jump_Action_Double();
				}
			break;
		case ui::Widget::TouchEventType::ENDED:
			break;
		default:
			break;
		}
	});
	this->addChild(jump_Button);

	//Lower Button
	lower_Button = Button::create("Button/Lower_Button.png", "Button/Lower_Button_Selected.png", "Button/Lower_Button_Selected.png");
	lower_Button->setAnchorPoint(Vec2::ANCHOR_BOTTOM_RIGHT);
	lower_Button->setOpacity(128);
	lower_Button->setScale(0.6);
	lower_Button->setPosition(Point(Config::screenSize.width - lower_Button->getContentSize().width/2, 0));
	lower_Button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			object_Layer->skater->runAnimation_Down();
			break;
		case ui::Widget::TouchEventType::MOVED:
			object_Layer->skater->runAnimation_Between_Up_And_Down();
			break;
		case ui::Widget::TouchEventType::ENDED:
			object_Layer->skater->runAnimation_Up();
			object_Layer->skater->runAnimation_Run();
			break;
		default:
			break;
		}
	});
	this->addChild(lower_Button);

	//Speed Button
	speed_Button = Button::create("Button/Speed_Button.png", "Button/Speed_Button_Selected.png", "Button/Speed_Button_Selected.png");
	speed_Button->setAnchorPoint(Vec2::ANCHOR_BOTTOM_LEFT);
	speed_Button->setOpacity(128);
	speed_Button->setScale(0.6);
	speed_Button->setPosition(Point(0, 0));
	speed_Button->addTouchEventListener([&](Ref* sender, Widget::TouchEventType type){
		switch (type)
		{
		case ui::Widget::TouchEventType::BEGAN:
			//My Code
			break;
		case ui::Widget::TouchEventType::ENDED:
			break;
		default:
			break;
		}
	});
	this->addChild(speed_Button);

	this->schedule(schedule_selector(Object_Layer::Spawn_Bonusx2), 20);
	//this->schedule(schedule_selector(GamePlay::updateBonusX2, 10));
	//this->schedule(schedule_selector(Object_Layer::Spawn_Car), 8);
	this->schedule(schedule_selector(Object_Layer::Spawn_Coin), 10);
	//this->schedule(schedule_selector(Object_Layer::Spawn_Animal), 5);
	//this->schedule(schedule_selector(Object_Layer::Spawn_Obstruction2), 16);

	this->scheduleUpdate();

	return true;
}

GamePlay * GamePlay::createGamePlayLayer()
{
	GamePlay * layer = new GamePlay();
	layer->init();
	layer->autorelease();
	return layer;
}

bool GamePlay::onTouchBegan(Touch *touch, Event *unused_event)
{
	if (object_Layer->skater->isDeath == false && object_Layer->skater->isJumping == false)
	{
		object_Layer->skater->jump_Action();
	}
	return true;
}

void GamePlay::onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event)
{
	if (keyCode == EventKeyboard::KeyCode::KEY_ESCAPE)
	{
		auto scene = Start_Scene::create_Start_Scene();
		Director::getInstance()->replaceScene(TransitionFade::create(0.5, scene, Color3B::WHITE));
	}
}

void GamePlay::Set_Object_Layer(Object_Layer * layer)
{
	this->object_Layer = layer;
}

void GamePlay::Set_Score_Layer(Score_Layer * layer)
{
	this->score_Layer = layer;
}

void GamePlay::Set_Background_Layer(Background_Layer * layer)
{
	this->background_Layer = layer;
}

void GamePlay::update(float dt)
{
	if (object_Layer->skater->isDeath == true)
	{
		//Dừng sinh Oject và cuộn background
		background_Layer->speed_Scroll = 0;
		this->unschedule(schedule_selector(Object_Layer::Spawn_Car));
		this->unschedule(schedule_selector(Object_Layer::Spawn_Coin));
		this->unschedule(schedule_selector(Object_Layer::Spawn_Animal));
		this->object_Layer->spawnObs->isGenerate = false;
		
		//Lưu Highscore
		bestScore = UserDefault::getInstance()->getIntegerForKey("BESTSCORE");
		if (this->object_Layer->skater->score > bestScore)
		{
			UserDefault::getInstance()->setIntegerForKey("BESTSCORE", this->object_Layer->skater->score);
		}

		//Chuyển scene
//		auto endScene = End_Scene::create_End_Scene(this->object_Layer->skater->score);
//		Director::getInstance()->replaceScene(TransitionFade::create(0.5, endScene));
	}


	//Tăng speed cuộn background và speed di chuyển của Obs
	if ((this->object_Layer->skater->score % 10) == 0 && this->object_Layer->skater->isIncrease == false)
	{
		background_Layer->speed_Scroll += 75;
		object_Layer->spawnObs->speed_Animal +=5;
		object_Layer->spawnObs->speed_Car +=5;
		this->object_Layer->skater->isIncrease = true;
	}

	//Coin
	stringstream ss;
	ss << this->object_Layer->skater->coin;
	this->score_Layer->coin->setString(ss.str());

	//Score
	stringstream ss1;
	ss1 << this->object_Layer->skater->score;
	this->score_Layer->current_Score->setString(ss1.str());
}



