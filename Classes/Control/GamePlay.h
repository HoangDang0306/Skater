#ifndef _GamePlay_
#define _GamePlay_
#include "cocos2d.h"
#include "View/Object_Layer.h"
USING_NS_CC;

class GamePlay : public Layer
{
public:
	GamePlay();
	~GamePlay();
	bool init();
	static GamePlay * createGamePlayLayer();

	Object_Layer * object_Layer;
	void Set_Object_Layer(Object_Layer * layer);

	bool onTouchBegan(Touch *touch, Event *unused_event);
};

#endif