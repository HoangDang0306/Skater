#include "Play_Scene.h"

Play_Scene::Play_Scene()
{
}

Play_Scene::~Play_Scene()
{
}

bool Play_Scene::init()
{
	if (!Scene::init()) return false;




	return true;
}

Scene * Start_Scene::create_Start_Scene()
{
	auto scene = Scene::createWithPhysics();



	return scene;
}