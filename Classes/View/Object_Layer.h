#ifndef _Object_Layer_
#define _Object_Layer_
#include "cocos2d.h"
USING_NS_CC;

class Object_Layer : public Layer
{
public:
	Object_Layer();
	~Object_Layer();
	static Object_Layer * create_Object_Layer();
	bool init();

	//Physics
	PhysicsWorld * physicsWorld;
	void SetPhysicsWorld(PhysicsWorld *world);
};

#endif