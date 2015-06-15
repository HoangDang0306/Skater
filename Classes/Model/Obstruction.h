#ifndef _Obstruction_
#define _Obstruction_

#include "cocos2d.h"
#include <sstream>
#include <iostream>

USING_NS_CC;
using namespace std;

class Obtruction : public Node
{
private:
	Sprite* _sprite;
	bool init(string fileName);
	PhysicsBody *body;
public:
	Obtruction();
	~Obtruction();
	static Obtruction* create(string fileName);
	void runAnimation(string name, int count, float time, bool isRepeat);
};




#endif