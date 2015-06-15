#include "Gameover_Scene.h"
#include "Utility/Config.h"


Gameover_Scene::Gameover_Scene()
{
}

Gameover_Scene::~Gameover_Scene()
{
}

bool Gameover_Scene::init()
{
	if (!Scene::init()) return false;




	return true;
}

Scene* Gameover_Scene::create_Gameover_Scene()
{
	auto scene = Scene::create();

	//Screen Config
	Config::screenSize = Director::getInstance()->getVisibleSize();
	Size screenSize = Config::screenSize;
	Vec2 center(screenSize.width / 2, screenSize.height / 2);
	Config::centerPoint = center;

	////Start Layer
	//auto startLayer = Start_Layer::create_Start_Layer();
	//scene->addChild(startLayer);

	return scene;
}