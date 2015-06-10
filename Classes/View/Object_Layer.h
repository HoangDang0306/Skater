#ifndef _Object_Layer_
#define _Object_Layer_
#include "cocos2d.h"
#include "Model/Skater.h"
#include "Model/Coin.h"

USING_NS_CC;

class Object_Layer : public Layer
{
public:
	Object_Layer();
	~Object_Layer();
	static Object_Layer * create_Object_Layer();
	bool init();

	//Object
	Skater * skater;
	void Spawn_Obstruction(float dt);
	void Spawn_Coin(float dt);

	//Physics
	PhysicsWorld * physicsWorld;
	void SetPhysicsWorld(PhysicsWorld *world);
};

#endif