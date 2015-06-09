﻿#include "Object_Layer.h"
#include "Utility/Config.h"
#include "Model/Skater.h"
#include "Model/Obstruction.h"
#include "Model/Coin.h"

Object_Layer::Object_Layer()
{
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
	body_Road->setDynamic(false);
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
	auto obs = Obtruction::create("Obtruction/car1.png");
	obs->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	obs->setPosition(Point(Config::screenSize.width, Config::screenSize.height/3.5));
	this->addChild(obs);
	auto moveObs = MoveBy::create(3, Vec2(-Config::screenSize.width * 3 / 2, 0));
	obs->runAction(moveObs);	
}

void Object_Layer::Spawn_Coin(float dt)
{
	int random_SoLuong = cocos2d::random(3, 7);
	/*for (int i = 0; i < random_SoLuong; i++)
	{*/
		auto coin = Coin::create("Coin/coin4.png");
		coin->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		coin->setPosition(Point(Config::screenSize.width /*+ i * coin->getContentSize().width*/, Config::screenSize.height / 2));
		this->addChild(coin);
		auto moveCoin = MoveBy::create(3, Vec2(-Config::screenSize.width * 3 / 2, 0));
		coin->runAction(moveCoin);
	//}
}