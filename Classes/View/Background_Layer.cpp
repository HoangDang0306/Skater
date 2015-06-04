#include "Background_Layer.h"
#include "Other/Config.h"

Sprite* _oddBackground;
Sprite* _evenBackground;

Background_Layer::Background_Layer()
{
}


Background_Layer::~Background_Layer()
{
}

bool Background_Layer::init()
{
	if (!Layer::init()) return false;
	/*Sprite* background = Sprite::create("Background/Background_3.png");
	background->setPosition(Config::centerPoint);
	background->setScale(Config::getScale(background));
	this->addChild(background, -1);*/
	endlessBackground();



	return true;
}

Background_Layer * Background_Layer::create_Background_Layer()
{
	Background_Layer * layer = new Background_Layer();
	layer->init();
	layer->autorelease();
	return layer;
}
void Background_Layer::endlessBackground() {

	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	// Create the two background sprites which will alternate
	_oddBackground = Sprite::create("Background/Background_3.png");
	_evenBackground = Sprite::create("Background/Background_3.png");
	_oddBackground->setScale(Config::getScale(_oddBackground));
	_evenBackground->setScale(Config::getScale(_evenBackground));
	// One starts dead centre and one starts exactly one screen height above
	_oddBackground->setPosition(winSize.width / 2, winSize.height / 2);
	_evenBackground->setPosition(winSize.width / 2 + (winSize.width), winSize.height/2);

	this->addChild(_oddBackground);
	this->addChild(_evenBackground);
	// Schedule the scrolling action
	this->scheduleUpdate();
	// Add sprites to the layer
	
}

void Background_Layer::update(float dt) {
	CCSize winSize = CCDirector::sharedDirector()->getWinSize();

	// move them 100*dt pixels down

	_oddBackground->setPosition(_oddBackground->getPosition().x - 150 * dt, _oddBackground->getPosition().y);
	_evenBackground->setPosition(_evenBackground->getPosition().x - 150 * dt, _evenBackground->getPosition().y);

	// reset position when they are off from view.
	if (_oddBackground->getPosition().x<-winSize.width / 2)
	{
		_oddBackground->setPosition(winSize / 2);
		_evenBackground->setPosition(winSize.width / 2 + winSize.width, winSize.height/2);
	}
}