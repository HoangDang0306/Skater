#ifndef _GamePlay_
#define _GamePlay_
#include "cocos2d.h"
#include "View/Object_Layer.h"
#include "View/Background_Layer.h"
USING_NS_CC;

class GamePlay : public Layer
{
public:
	GamePlay();
	~GamePlay();
	bool init();
	static GamePlay * createGamePlayLayer();

	//Object
	Object_Layer * object_Layer;
	void Set_Object_Layer(Object_Layer * layer);
	//Background
	Background_Layer * background_Layer;
	void Set_Background_Layer(Background_Layer * layer);

	//Touch
	bool onTouchBegan(Touch *touch, Event *unused_event);
};

#endif