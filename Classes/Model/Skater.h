#ifndef _Skater_
#define _Skater_

#include "cocos2d.h"
#include <sstream>
#include <iostream>

USING_NS_CC;
using namespace std;

class Skater : public Node
{
private:
	Sprite * _sprite;
	bool init(string fileName);
	PhysicsBody * body;
	
public:
	Skater();
	~Skater();
	bool isAlive;
	bool isJumping;
	bool isContactWithObs;
	static Skater* create(string fileName);

	void runAnimation(string name, int count, float time, bool isRepeat);
	void runAnimation_Run();
	void runAnimation_Jump();
	void runAnimation_Fail();
	void runAnimation_Down();

	void jump_Action();
	bool onContactBegin(PhysicsContact &contact);
};




#endif