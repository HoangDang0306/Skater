﻿#include "Object_Layer.h"
#include "Utility/Config.h"
#include "Utility/Tags.h"
#include "Model/Skater.h"
#include "Model/Coin.h"
#include "Model/Obstruction.h"
#include "Model/Obstruction_Animal.h"
#include "Model/Coin.h"
#include <iostream>
using namespace std;
USING_NS_CC;
Object_Layer::Object_Layer()
{
	//Speed
	speed_Obs = 3.5f;
}


Object_Layer::~Object_Layer()
{
}

bool Object_Layer::init()
{
	if (!Layer::init()) return false;

	//SkaterKid
	skater = Skater::create("0.png");
	skater->setPosition(Config::centerPoint.x-250, Config::centerPoint.y-150);
	skater->runAnimation_Run();
	this->addChild(skater);

	//Road
	Node * road = Node::create();
	road->setPosition(Config::screenSize.width / 2, Config::screenSize.height / 10.5);
	road->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	PhysicsBody * body_Road = PhysicsBody::createBox(Size(Config::screenSize.width, Config::screenSize.height / 8), PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
	body_Road->setTag(Tags::ROAD);
	body_Road->setDynamic(false);
	body_Road->setContactTestBitmask(1);
	body_Road->setCollisionBitmask(1);
	road->setPhysicsBody(body_Road);
	this->addChild(road);

	return true;
}

Object_Layer * Object_Layer::create_Object_Layer()
{
	Object_Layer * layer = new Object_Layer();
	layer->init();
	layer->autorelease();
	return layer;
}

void Object_Layer::SetPhysicsWorld(PhysicsWorld * world)
{
	this->physicsWorld = world;
}

	
void Object_Layer::Spawn_Obstruction(float dt)
{
	int i = random(1, 3);
	char name[100];
	sprintf(name, "Obtruction/car%i.png", i);
	Obtruction * obs = Obtruction::create(name);
	obs->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	auto randomDis = random(0.5, 2.0);
	obs->MoveObs(randomDis*5, randomDis);
	obs->setPosition(Point(Config::screenSize.width + randomDis*Config::screenSize.width, Config::screenSize.height / 10.5 + Config::screenSize.height / 9));
	this->addChild(obs);
}

void Object_Layer::Spawn_Animal(float dt)
{
	auto ani = Obstruction_Animal::create("0.png");
	ani->setScale(0.7);
	int k = cocos2d::random(1, 4);
	switch (k)
	{
	case 1:
		ani->runAnimation("dog", 4, 0.5f, true);
		break;
	case 2:
		ani->runAnimation("chick", 4, 0.5f, true);
		break;
	case 3:
		ani->runAnimation("cat", 4, 0.5f, true);
		break;
	case 4:
		ani->runAnimation("hour", 4, 0.5f, true);
		break;
	}
	ani->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	ani->setPosition(Point(Config::screenSize.width, Config::screenSize.height / 10.5 + Config::screenSize.height / 9));
	auto moveAni = MoveBy::create(6, Vec2(-Config::screenSize.width * 3 / 2, 0));
	this->addChild(ani);
	ani->runAction(moveAni);
}

void Object_Layer::Spawn_Coin(float dt)
{

	int min = 5.0;
	int max = 10.0;
	int rangeDuration = max - min;
	int randomDuration = (rand() % rangeDuration) + min;

	int k = cocos2d::random(1, 2);

	for (int i = 0; i < randomDuration; i++)
	{
		auto obs = Coin::create("0.png");
		obs->setScale(0.3);
		obs->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		obs->setPosition(Point(Config::screenSize.width + 40 * i, Config::screenSize.height / 2));
		auto moveObs = MoveBy::create(6, Vec2(-Config::screenSize.width * 3 / 2, 0));
		switch (k)
		{
		case 1:
			obs->runAnimation("coin", 7, 0.8f, true);
			break;
		case 2: 
			obs->runAnimation("coin2", 7, 0.8f, true); 
			break;
		}

		this->addChild(obs);
		obs->runAction(moveObs);
	}
	
}
