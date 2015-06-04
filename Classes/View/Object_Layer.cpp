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
	skater->setPosition(Config::centerPoint.x-250, Config::centerPoint.y-150);
	skater->setScale(1.5);
	skater->runAnimation_Run();
	this->addChild(skater);

	//taạo chướng ngại vật
	
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