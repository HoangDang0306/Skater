#include "Object_Layer.h"
#include "Utility/Config.h"
#include "Utility/Tags.h"
#include "Model/Skater.h"
#include "Model/Coin.h"
#include "Model/Obstruction.h"
#include "Model/Coin.h"
USING_NS_CC;
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
	auto obs = Obtruction::create("Obtruction/car1.png");
	obs->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	obs->setPosition(Point(Config::screenSize.width, Config::screenSize.height/3.5));
	this->addChild(obs);
	auto moveObs = MoveBy::create(4, Vec2(-Config::screenSize.width * 3 / 2, 0));
	obs->runAction(moveObs);	
}

void Object_Layer::Spawn_Coin(float dt)
{

	/*
	int random_SoLuong = cocos2d::random(3, 7);
	for (int i = 0; i < random_SoLuong; i++)
	{
		auto coin = Coin::create("Coin/coin4.png");
		coin->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		coin->setPosition(Point(Config::screenSize.width /*+ i * coin->getContentSize().width, Config::screenSize.height / 2));
		this->addChild(coin);
		auto moveCoin = MoveBy::create(3, Vec2(-Config::screenSize.width * 3 / 2, 0));
		coin->runAction(moveCoin);
	}
*/

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
			this->addChild(obs);
			obs->runAction(moveObs);
			break;
		case 2: 
			obs->runAnimation("coin2", 7, 0.8f, true); 
			this->addChild(obs);
			obs->runAction(moveObs);
			break;
	
		}
	
	}

}
