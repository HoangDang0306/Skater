#include "Play_Scene.h"
#include "View/Kid_Layer.h"
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

	//Show Kid and Object
	auto kidLayer = Kid_Layer::create_Kid_Layer();
	scene->addChild(kidLayer);

	return scene;
}