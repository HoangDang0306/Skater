#include "Skater.h"
#include "Other/XHelper.h"

Skater::Skater(){}
Skater::~Skater(){}

Skater* Skater::create(string fileName)
{
	Skater* skater = new Skater();
	skater->init(fileName);
	skater->autorelease();
	//Skater::Instance = skater;
	return skater;
}

bool Skater::init(string fileName)
{
	if (!Node::init())
		return false;
	isAlive = true;
	//Skater::Instance = this;

	//-------------  Khởi tạo sprite chính -------------
	_sprite = Sprite::create(fileName);
	_sprite->setPosition(0, 0);
	this->addChild(_sprite);


	/*
	//-------------   Physic Body  --------------
	_body = PhysicsBody::createBox(_sprite->getBoundingBox().size, PhysicsMaterial(_ninjaModel.density, _ninjaModel.restitution, _ninjaModel.friction));
	_body->setGravityEnable(false);
	_body->setDynamic(true);
	_body->setTag(Tags::NINJA);
	_body->setCollisionBitmask(1);
	_body->setContactTestBitmask(1);

	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(_body);


	//contact listner
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Ninja::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	*/

	return true;
}

void Skater::runAnimation(string name, int count, float time, bool isRepeat)
{
	XHelper::runAnimation(name, count, time, true, this->_sprite);
}
void Skater::runAnimation_Run()
{
	//runAnimation("DungYen", 2, 0.5f, true);
}

void Skater::runAnimation_Jump()
{
	//runAnimation("ninja_nhay", 2, 0.5f, true);
}
void Skater::runAnimation_Fail()
{
	//runAnimation("ninja_nhay", 2, 0.5f, true);
}
void Skater::runAnimation_Down()
{
	runAnimation("down", 3, 0.1f, true);
}
