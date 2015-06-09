#include "Coin.h"
#include "Other/XHelper.h"
#include "Other/Tags.h"

Coin::Coin(){}
Coin::~Coin(){}

Coin* Coin::create(string fileName)
{
	Coin* coin = new Coin();
	coin->init(fileName);
	coin->autorelease();
	return coin;
}

bool Coin::init(string fileName)
{
	if (!Node::init())
		return false;

	//-------------  Khởi tạo sprite chính -------------
	_sprite = Sprite::create(fileName);
	_sprite->setPosition(0, 0);
	this->addChild(_sprite);
	
	

	/*
	//-------------   Physic Body  --------------
	body = PhysicsBody::createCircle(_sprite->getBoundingBox().size, PhysicsMaterial(100.0f, 0.0f, 100.0f), Vec2(0, 0));
	body->setGravityEnable(false);
	body->setDynamic(true);
	body->setTag(Tags::COIN);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	
	
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(body);
	*/

	/*
	_sprite->getPhysicsBody()->setCategoryBitmask(0x03);    // 0011
	_sprite->getPhysicsBody()->setCollisionBitmask(0x03);   // 0011
	*/

	return true;
}

//Animation
void Coin::runAnimation(string name, int count, float time, bool isRepeat)
{
	XHelper::runAnimation(name, count, time, true, this->_sprite);
}