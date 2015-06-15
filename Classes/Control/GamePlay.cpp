﻿#include "GamePlay.h"
#include "Model/Skater.h"
#include "View/Object_Layer.h"
#include "View/Gameover_Scene.h"
#include "Model/Obstruction.h"
#include "Utility/Tags.h"

GamePlay::GamePlay()
{
}


GamePlay::~GamePlay()
{
}


bool GamePlay::init()
{
	if (!Layer::init()) return false;
	
	//Xử lý Touch
	auto touchListener = EventListenerTouchOneByOne::create();
	touchListener->onTouchBegan = CC_CALLBACK_2(GamePlay::onTouchBegan, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(touchListener, this);


	this->schedule(schedule_selector(Object_Layer::Spawn_Obstruction), 2);
	this->schedule(schedule_selector(Object_Layer::Spawn_Coin), 5);

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
	if (object_Layer->skater->isJumping == false)
	{
		object_Layer->skater->jump_Action();
	}
	return true;
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
	}
}