#include "Obstruction.h"
#include "Utility/XHelper.h"
#include "Utility/Tags.h"

Obtruction::Obtruction(){}
Obtruction::~Obtruction(){}

Obtruction* Obtruction::create(string fileName)
{
	Obtruction* obtruction = new Obtruction();
	obtruction->init(fileName);
	obtruction->autorelease();
	return obtruction;
}

bool Obtruction::init(string fileName)
{
	if (!Node::init())
		return false;

	//-------------  Khởi tạo sprite chính -------------
	_sprite = Sprite::create(fileName);
	_sprite->setPosition(0, 0);
	_sprite->setAnchorPoint(Vec2(0.5, 0.25));
	this->addChild(_sprite);

	//-------------   Physic Body  --------------
	body = PhysicsBody::createBox(Size(_sprite->getContentSize().width, _sprite->getContentSize().height/2), PhysicsMaterial(100.0f, 0.0f, 100.0f), Vec2::ZERO);
	body->setDynamic(true);
	body->setTag(Tags::OBSTRUCTION);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(body);

	//node
	auto nodeCar = Node::create();
	nodeCar->setPosition(0, _sprite->getContentSize().height / 16);
	nodeCar->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->addChild(nodeCar);
	PhysicsBody * bodyNodeCar = PhysicsBody::createBox(Size(_sprite->getContentSize().width * 3 / 5, _sprite->getContentSize().height / 2), PhysicsMaterial(100.0f, 0.0f, 100.0f), Vec2::ZERO);
	bodyNodeCar->setTag(Tags::MAIXE);
	bodyNodeCar->setDynamic(false);
	bodyNodeCar->setContactTestBitmask(1);
	bodyNodeCar->setCollisionBitmask(1);
	nodeCar->setPhysicsBody(bodyNodeCar);

	
	return true;
}
