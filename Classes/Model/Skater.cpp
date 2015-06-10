#include "Skater.h"
#include "Other/XHelper.h"
#include "Other/Tags.h"

Skater::Skater(){}
Skater::~Skater(){}

Skater* Skater::create(string fileName)
{
	Skater* skater = new Skater();
	skater->init(fileName);
	skater->autorelease();
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

	//-------------   Physic Body  --------------
	body = PhysicsBody::createBox(_sprite->getBoundingBox().size, PhysicsMaterial(100.0f, 0.0f, 100.0f), Vec2(0, 0));
	body->setDynamic(true);
	body->setMass(50.0f);
	body->setAngularVelocityLimit(0.0f);
	body->setRotationEnable(false);
	body->setTag(Tags::SKATER);
	body->setCollisionBitmask(1);
	body->setContactTestBitmask(1);
	this->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	this->setPhysicsBody(body);

	//contact listner
	auto contactListener = EventListenerPhysicsContact::create();
	contactListener->onContactBegin = CC_CALLBACK_1(Skater::onContactBegin, this);
	_eventDispatcher->addEventListenerWithSceneGraphPriority(contactListener, this);
	

	return true;
}

//Animation
void Skater::runAnimation(string name, int count, float time, bool isRepeat)
{
	XHelper::runAnimation(name, count, time, true, this->_sprite);
}
void Skater::runAnimation_Run()
{
	runAnimation("play", 3, 0.5f, true);
}

void Skater::runAnimation_Jump()
{
	runAnimation("jump", 5, 0.2f, false);
}
void Skater::runAnimation_Fail()
{
	runAnimation("fail", 3, 0.5f, true);
}
void Skater::runAnimation_Down()
{
	runAnimation("down", 3, 0.1f, true);
}

void Skater::jump_Action()
{
	this->body->applyImpulse(Vec2(0, 12000));
	this->runAnimation_Jump();
	this->runAction(Sequence::create(
		DelayTime::create(1),
		CallFunc::create(CC_CALLBACK_0(Skater::runAnimation_Run, this)),
		nullptr));
}

bool Skater::onContactBegin(PhysicsContact& contact)
{
	auto a = contact.getShapeA()->getBody();
	auto b = contact.getShapeB()->getBody();


	//----------------   Va chạm vơi chướng ngại vật   ---------
	if (a != NULL && b != NULL && a->getNode() != NULL && b->getNode() != NULL)
	{
		if ((a->getTag() == Tags::SKATER && b->getTag() == Tags::OBTRUCTION)
			|| (a->getTag() == Tags::OBTRUCTION && b->getTag() == Tags::SKATER))
		{
			log("Noooooooooo");
			isAlive = false;
			auto e = a->getTag() == Tags::SKATER ? a : b;
			e->getNode()->removeFromParent();
			//PhiTieuLayer::instance->matMau();
		}
	

		//----------------   Va chạm với coin   ---------
	
			if ((a->getTag() == Tags::SKATER && b->getTag() == Tags::COIN)
				|| (a->getTag() == Tags::COIN && b->getTag() == Tags::SKATER))
			{
				log("Yesssssss");
				auto e = a->getTag() == Tags::COIN ? a : b;
				e->getNode()->removeFromParent();
				//PhiTieuLayer::instance->matMau();
			
			}
	}

	return false;
}

