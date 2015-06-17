#include "Skater.h"
#include "Utility/XHelper.h"
#include "Utility/Tags.h"
#include "SimpleAudioEngine.h"
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
	this->isAlive = true;
	this->isDeath = false;
	this->isJumping = false;
	this->isIncrease = false;
	this->coin = 0;
	this->score = 0;

	//-------------  Khởi tạo sprite chính -------------
	_sprite = Sprite::create(fileName);
	_sprite->setPosition(0, 0);
	this->addChild(_sprite);

	//-------------   Physic Body  --------------
	body = PhysicsBody::createBox(_sprite->getBoundingBox().size, PhysicsMaterial(100.0f, 0.0f, 100.0f), Vec2(0, 0));
	body->setDynamic(true);
	body->setMass(48.0f);
	body->setAngularVelocityLimit(0.0f);
	body->setRotationEnable(false);
	body->setTag(Tags::SKATER);
	body->setCollisionBitmask(0x02);
	body->setContactTestBitmask(1);
	body->setCategoryBitmask(0x01);
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
	this->isJumping = true;
	this->runAnimation_Jump();
	this->runAction(Sequence::create(
		DelayTime::create(1),
		CallFunc::create(CC_CALLBACK_0(Skater::runAnimation_Run, this)),
		nullptr));

	//tạo music
	CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sound/Jump11.wav");
	CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound/Jump11.wav");
}

bool Skater::onContactBegin(PhysicsContact& contact)
{
	auto a = contact.getShapeA()->getBody();
	auto b = contact.getShapeB()->getBody();

	//----------------   Va chạm vơi chướng ngại vật   ---------
	if ((a->getTag() == Tags::SKATER && b->getTag() == Tags::OBSTRUCTION)
		|| (a->getTag() == Tags::OBSTRUCTION && b->getTag() == Tags::SKATER))
	{

			this->isDeath = true;
	}

	if ((a->getTag() == Tags::SKATER && b->getTag() == Tags::MAIXE)
		|| (a->getTag() == Tags::MAIXE && b->getTag() == Tags::SKATER))
	{
		this->isJumping = false;
	}
	
	//Va cham voi ROAD
	if ((a->getTag() == Tags::SKATER && b->getTag() == Tags::ROAD) || (a->getTag() == Tags::ROAD && b->getTag() == Tags::SKATER))
	{
		this->isJumping = false;
	}

	//Va chạm với COIN
	if ((a->getCategoryBitmask() & b->getCollisionBitmask()) == 0 || (b->getCategoryBitmask() & a->getCollisionBitmask()) == 0)
	{
		if (a != NULL && b != NULL && a->getNode() != NULL && b->getNode() != NULL)
		{
			if (a->getTag() == Tags::SKATER && b->getTag() == Tags::COIN)
			{
				b->getNode()->removeFromParent();
				this->coin++;

				CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sound/Pickup_Coin3.wav");
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound/Pickup_Coin3.wav");
			}
		}

		if (a != NULL && b != NULL && a->getNode() != NULL && b->getNode() != NULL)
		{
			if (b->getTag() == Tags::SKATER && a->getTag() == Tags::COIN)
			{
				a->getNode()->removeFromParent();
				this->coin++;

				CocosDenshion::SimpleAudioEngine::getInstance()->preloadEffect("Sound/Pickup_Coin3.wav");
				CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("Sound/Pickup_Coin3.wav");
			}
		}

		if ((a->getTag() == Tags::SKATER && b->getTag() == Tags::NODE_SCORE) || (b->getTag() == Tags::SKATER && a->getTag() == Tags::NODE_SCORE))
		{
			this->score++;
			this->isIncrease = false;
		}
	}
	return true;
}