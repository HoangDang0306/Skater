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

	//SkaterKid
	skater = Skater::create("0.png");
	skater->setPosition(Config::centerPoint.x-250, Config::centerPoint.y-150);
	skater->runAnimation_Run();
	this->addChild(skater);

<<<<<<< HEAD
	//taạo chướng ngại vật
	
=======
	//Road
	Node * road = Node::create();
	road->setPosition(Config::screenSize.width / 2, Config::screenSize.height / 9);
	road->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
	PhysicsBody * body_Road = PhysicsBody::createBox(Size(Config::screenSize.width, Config::screenSize.height / 8), PHYSICSBODY_MATERIAL_DEFAULT, Vec2::ZERO);
	body_Road->setDynamic(false);
	road->setPhysicsBody(body_Road);
	this->addChild(road);

>>>>>>> 37d04d520f985c23e3011c17a61feb06816080fe
	return true;
}

Object_Layer * Object_Layer::create_Object_Layer()
{
	Object_Layer * layer = new Object_Layer();
	layer->init();
	layer->autorelease();
	return layer;
}

void Object_Layer::SetPhysicsWorld(PhysicsWorld *world)
{
	this->physicsWorld = world;
}