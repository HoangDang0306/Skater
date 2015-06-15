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
	this->addChild(_sprite);

	
	//-------------   Physic Body  --------------
	body = PhysicsBody::createBox(_sprite->getBoundingBox().size, PhysicsMaterial(100.0f, 0.0f, 100.0f), Vec2::ZERO);
	body->setDynamic(true);
	body->setTag(Tags::OBSTRUCTION);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(body);

	return true;
}
//Animation
void Obtruction::runAnimation(string name, int count, float time, bool isRepeat)
{
	XHelper::runAnimation(name, count, time, true, this->_sprite);
}