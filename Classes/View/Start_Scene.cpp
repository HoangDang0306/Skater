#include "Start_Scene.h"

Start_Scene::Start_Scene()
{
}

Start_Scene::~Start_Scene()
{
}

bool Start_Scene::init()
{
	if (!Scene::init()) return false;




	return true;
}

Scene* Start_Scene::create_Start_Scene()
{
	auto scene = Scene::create();



	return scene;
}