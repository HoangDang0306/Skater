#include "GamePlay.h"
#include "Model/Skater.h"
#include "View/Object_Layer.h"
#include "Model/Obstruction.h"
#include "Utility/Tags.h"
#include "View/Start_Scene.h"
#include "View/End_Scene.h"
#include <sstream>
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
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);


	this->schedule(schedule_selector(Object_Layer::Spawn_Obstruction), 10);
	this->schedule(schedule_selector(Object_Layer::Spawn_Coin), 6);
	this->schedule(schedule_selector(Object_Layer::Spawn_Animal), 5);
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

void GamePlay::Set_Background_Layer(Background_Layer * layer)
{
	this->background_Layer = layer;
}

void GamePlay::Set_Score_Layer(Score_Layer * layer)
{
	this->score_Layer = layer;
}

void GamePlay::update(float dt)
{
	if (object_Layer->skater->isDeath == true)
	{
		//Dừng sinh Oject và cuộn background
		background_Layer->speed_Scroll = 0;
		this->unschedule(schedule_selector(Object_Layer::Spawn_Obstruction));
		this->unschedule(schedule_selector(Object_Layer::Spawn_Coin));
		
		//Lưu Highscore
		bestScore = UserDefault::getInstance()->getIntegerForKey("BESTSCORE");
		if (this->object_Layer->skater->score > bestScore)
		{
			UserDefault::getInstance()->setIntegerForKey("BESTSCORE", this->object_Layer->skater->score);
		}

		//Chuyển scene
		auto endScene = End_Scene::create_End_Scene(this->object_Layer->skater->score);
		Director::getInstance()->replaceScene(TransitionFade::create(0.5, endScene));

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