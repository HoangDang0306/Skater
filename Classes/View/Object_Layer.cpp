#include "Object_Layer.h"
#include "Other/Config.h"
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
	skater->setPosition(Config::centerPoint.x-200, Config::centerPoint.y-200);
	skater->runAnimation_Run();
	this->addChild(skater);

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