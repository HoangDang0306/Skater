#include "Object_Layer.h"
#include "Other/Config.h"
#include "Other/XHelper.h"
#include "Model/Skater.h"


Object_Layer::Object_Layer()
{
}


Object_Layer::~Object_Layer()
{
}

bool Object_Layer::init()
{
	if (!Layer::init()) return false;

	//tạo animation
	Skater* skater = Skater::create("0.png");
	skater->setPosition(Config::centerPoint.x, Config::centerPoint.y);
	skater->runAnimation_Down();
	PhysicsBody * body = PhysicsBody::createBox(skater->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
	body->setDynamic(false);
	skater->setPhysicsBody(body);
	this->addChild(skater);

	Sprite * sp = Sprite::create("0.png");
	sp->setPosition(300, 200);
	PhysicsBody * body1 = PhysicsBody::createBox(sp->getContentSize(), PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
	body1->setDynamic(false);
	sp->setPhysicsBody(body1);
	this->addChild(sp);


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