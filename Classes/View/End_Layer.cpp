#include "End_Layer.h"
#include "Utility/Config.h"
#include <sstream>
using namespace std;

End_Layer::End_Layer()
{
}


End_Layer::~End_Layer()
{
}

bool End_Layer::init(int score)
{
	if (!Layer::init()) return false;

	//Text current Score
	Label * text_current_Score = Label::create("Score:", "fonts/Kidfont.ttf", 45, Size::ZERO, TextHAlignment::LEFT, TextVAlignment::TOP);
	text_current_Score->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	text_current_Score->setColor(Color3B::WHITE);
	text_current_Score->setPosition(0, Config::screenSize.height);
	this->addChild(text_current_Score);

	//Current Score
	stringstream ss;
	ss << score;
	Label * current_Score = Label::create(ss.str(), "fonts/Kidfont.ttf", 45, Size::ZERO, TextHAlignment::LEFT, TextVAlignment::TOP);
	current_Score->setAnchorPoint(Vec2::ANCHOR_TOP_LEFT);
	current_Score->setColor(Color3B::WHITE);
	current_Score->setPosition(text_current_Score->getContentSize().width * 3 / 2, Config::screenSize.height);
	this->addChild(current_Score);

	return true;
}

End_Layer * End_Layer::create_End_Layer(int score)
{
	End_Layer * layer = new End_Layer();
	layer->init(score);
	layer->autorelease();
	return layer;
}