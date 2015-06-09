#include "Object_Layer.h"
#include "Other/Config.h"
#include "Other/XHelper.h"
#include "Model/Skater.h"
<<<<<<< HEAD
#include "Model/Coin.h"
USING_NS_CC;
=======
#include "Model/Obstruction.h"
>>>>>>> 805f9592c4a5bf8fa8e0f0f884bc6e20c323bf0c

#include <climits>
#include <cstdlib>
#include <iostream>
using namespace std;
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

<<<<<<< HEAD
	
	
=======
>>>>>>> 805f9592c4a5bf8fa8e0f0f884bc6e20c323bf0c
	//Road
	Node * road = Node::create();
	road->setPosition(Config::screenSize.width / 2, Config::screenSize.height / 10.5);
	road->setAnchorPoint(Vec2::ANCHOR_MIDDLE_TOP);
	PhysicsBody * body_Road = PhysicsBody::createBox(Size(Config::screenSize.width, Config::screenSize.height / 8), PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
	body_Road->setDynamic(false);
	road->setPhysicsBody(body_Road);
	this->addChild(road);
	/*
	//Coin
	coin = Coin::create("0.png");
	coin->setPosition(Config::centerPoint.x + 250, Config::centerPoint.y );
	coin->setScale(0.4);
	coin->runAnimation("coin",7,0.5f,true);
	this->addChild(coin);

	coin1 = Coin::create("0.png");
	coin1->setPosition(Config::centerPoint.x + 150, Config::centerPoint.y);
	coin1->setScale(0.4);
	coin1->runAnimation("coin2", 7, 0.5f, true);
	this->addChild(coin1);
	*/


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

<<<<<<< HEAD
=======
void Object_Layer::Spawn_Obstruction(float dt)
{
	auto obs = Obtruction::create("Obtruction/car1.png");
	obs->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	obs->setPosition(Point(Config::screenSize.width, Config::screenSize.height/3));
	this->addChild(obs);
	auto moveObs = MoveBy::create(3, Vec2(-Config::screenSize.width * 3 / 2, 0));
	obs->runAction(moveObs);	
}
>>>>>>> 805f9592c4a5bf8fa8e0f0f884bc6e20c323bf0c
