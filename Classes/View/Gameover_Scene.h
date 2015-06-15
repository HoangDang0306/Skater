#ifndef _Gameover_Scene_
#define _Gameover_Scene_
#include "cocos2d.h"
USING_NS_CC;

class Gameover_Scene : public Scene
{
public:
	Gameover_Scene();
	~Gameover_Scene();
	static Scene * create_Gameover_Scene();
	bool init();

};

#endif