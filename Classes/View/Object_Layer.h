#ifndef _Object_Layer_
#define _Object_Layer_
#include "cocos2d.h"
#include "Model/Skater.h"
#include "Model/Coin.h"

USING_NS_CC;

class Object_Layer : public Layer
{
	
	
public:
	Point scrollDecrement;
	//Object
	Coin  * coin;
	Coin  * coin1;
	Skater * skater;

	Object_Layer();
	~Object_Layer();
	static Object_Layer * create_Object_Layer();
	bool init();
	

	//Physics
	PhysicsWorld * physicsWorld;
	void SetPhysicsWorld(PhysicsWorld *world);
};

#endif