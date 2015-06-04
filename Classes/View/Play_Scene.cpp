#include "Play_Scene.h"
#include "View/Object_Layer.h"
#include "Utility/Config.h"

Play_Scene::Play_Scene()
{
}

Play_Scene::~Play_Scene()
{
}

bool Play_Scene::init()
{
	if (!Play_Scene::init()) return false;




	return true;
}

Scene * Play_Scene::create_Play_Scene()
{
	auto scene = Scene::createWithPhysics();
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);

	//Show Kid and Object
	auto object_Layer = Object_Layer::create_Object_Layer();
	object_Layer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(object_Layer);

	return scene;
}