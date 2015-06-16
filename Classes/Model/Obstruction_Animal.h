#ifndef _Animal_
#define _Animal_

#include "cocos2d.h"
#include <sstream>
#include <iostream>

USING_NS_CC;
using namespace std;

class Obstruction_Animal : public Node
{
private:
	Sprite* _sprite;
	bool init(string fileName);
	PhysicsBody *body;
public:
	Obstruction_Animal();
	~Obstruction_Animal();
	static Obstruction_Animal* create(string fileName);
	void runAnimation(string name, int count, float time, bool isRepeat);
};

#endif