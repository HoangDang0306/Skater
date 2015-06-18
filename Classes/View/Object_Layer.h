#ifndef _Object_Layer_
#define _Object_Layer_
#include "cocos2d.h"
#include "Model/Skater.h"
#include "Model/Coin.h"
#include "Model/SpawnObs.h"

USING_NS_CC;

class Object_Layer : public Layer
{
public:
	Object_Layer();
	~Object_Layer();
	static Object_Layer * create_Object_Layer();
	bool init();

	//Generation
	SpawnObs * spawnObs;

	//Object
	Skater * skater;
	void Spawn_Car(float dt);
	void Spawn_Coin(float dt);
	void Spawn_Animal(float dt);
	void Spawn_Obstruction2(float dt);
	float speed_Obs;


	//Physics
	PhysicsWorld * physicsWorld;
	void SetPhysicsWorld(PhysicsWorld *world);
};

#endif
