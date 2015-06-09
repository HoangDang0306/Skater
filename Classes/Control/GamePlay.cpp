﻿#include "GamePlay.h"
#include "Model/Skater.h"
#include "View/Object_Layer.h"
#include "Model/Obstruction.h"

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
<<<<<<< HEAD
	object_Layer->skater->jump_Action(2);
	object_Layer->scrollDecrement.x+=0.05;
	background_Layer->speed_Scroll += 5;
=======
	object_Layer->skater->jump_Action();
>>>>>>> 805f9592c4a5bf8fa8e0f0f884bc6e20c323bf0c
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