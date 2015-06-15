#include "GamePlay.h"
#include "Model/Skater.h"
#include "View/Object_Layer.h"
#include "View/Gameover_Scene.h"
#include "Model/Obstruction.h"
<<<<<<< HEAD
#include "Utility/Tags.h"
=======
#include "View/Start_Scene.h"
#include "View/End_Scene.h"
#include <sstream>
using namespace std;
>>>>>>> 664e331fdb443eb6227717c9e5104fced57e0746

GamePlay::GamePlay()
{
}


GamePlay::~GamePlay()
{
}


bool GamePlay::init()
{
	if (!Layer::init()) return false;
	
	//Back button
	this->setKeypadEnabled(true);
	this->setKeyboardEnabled(true);

	//Xử lý Touch
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GamePlay::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);

<<<<<<< HEAD

	this->schedule(schedule_selector(Object_Layer::Spawn_Obstruction), 2);
	this->schedule(schedule_selector(Object_Layer::Spawn_Coin), 5);

=======
	this->schedule(schedule_selector(Object_Layer::Spawn_Obstruction), 2);
	this->schedule(schedule_selector(Object_Layer::Spawn_Coin), 5);
>>>>>>> 664e331fdb443eb6227717c9e5104fced57e0746
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
<<<<<<< HEAD
	if (object_Layer->skater->isAlive == false)
	{
		/*
		CCLOG("Game over");
		background_Layer->speed_Scroll = 0;
		this->unschedule(schedule_selector(Object_Layer::Spawn_Obstruction));
		this->unschedule(schedule_selector(Object_Layer::Spawn_Coin));
		object_Layer->stopAllActionsByTag(Tags::COIN);
		object_Layer->stopAllActionsByTag(Tags::OBSTRUCTION);
		*/
		//Director::getInstance()->replaceScene(TransitionFade::create(0.5, Gameover_Scene::create_Gameover_Scene(), Color3B::WHITE));
=======
	
	if (object_Layer->skater->isDeath == true)
	{
		background_Layer->speed_Scroll = 0;
		this->unschedule(schedule_selector(Object_Layer::Spawn_Obstruction));
		this->unschedule(schedule_selector(Object_Layer::Spawn_Coin));
		
		auto endScene = End_Scene::create_End_Scene(this->object_Layer->skater->score);
		Director::getInstance()->replaceScene(TransitionFade::create(0.5, endScene));
>>>>>>> 664e331fdb443eb6227717c9e5104fced57e0746
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