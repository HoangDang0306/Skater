#ifndef _GamePlay_
#define _GamePlay_
#include "cocos2d.h"
#include "View/Object_Layer.h"
#include "View/Background_Layer.h"
#include "View/Score_Layer.h"
#include "ui/CocosGUI.h"
using namespace ui;
USING_NS_CC;

class GamePlay : public Layer
{
public:
	GamePlay();
	~GamePlay();
	bool init();
	static GamePlay * createGamePlayLayer();

	//Store Data
	int bestScore;

	//Object
	Object_Layer * object_Layer;
	void Set_Object_Layer(Object_Layer * layer);

	//Background
	Background_Layer * background_Layer;
	void Set_Background_Layer(Background_Layer * layer);

	//Score Layer
	Score_Layer * score_Layer;
	void Set_Score_Layer(Score_Layer * layer);

	//Button
	Button * jump_Button;
	Button * lower_Button;
	Button * speed_Button;

	//Touch
	bool onTouchBegan(Touch *touch, Event *unused_event);

	//Back Button
	void onKeyReleased(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event *event);

	//Update
	void update(float dt);
};

#endif
