#include "Play_Scene.h"
#include "View/Object_Layer.h"
#include "View/Background_Layer.h"
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

	// Lệnh debug này cho phép nhìn thấy các khung body vật lý áp dụng vào các đối tượng ( đường viền đỏ bao quanh đối tượng)
	scene->getPhysicsWorld()->setDebugDrawMask(PhysicsWorld::DEBUGDRAW_ALL);
	//Thiết lập gia tốc trọng lực bằng 0, để các đối tượng của chúng ta ko rơi xuống đáy màn hình
	scene->getPhysicsWorld()->setGravity(Vect(0.0f, 0.0f));


	/*scene->getPhysicsWorld()->setSpeed(3.5f);
	scene->getPhysicsWorld()->setGravity(Vect(0, -145.0f));
	scene->getPhysicsWorld()->setUpdateRate(0.5f);
	scene->getPhysicsWorld()->setSubsteps(10);*/

	//Background layer
	auto bgLayer = Background_Layer::create_Background_Layer();
	scene->addChild(bgLayer);

	//Show Kid and Object
	auto kidLayer = Object_Layer::create_Object_Layer();
	kidLayer->SetPhysicsWorld(scene->getPhysicsWorld());
	scene->addChild(kidLayer);

	return scene;
}