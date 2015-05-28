#include "Kid_Layer.h"
#include "Other/Config.h"
#include "Other/XHelper.h"
#include "Model/Skater.h"


Kid_Layer::Kid_Layer()
{
}


Kid_Layer::~Kid_Layer()
{
}

bool Kid_Layer::init()
{
	if (!Layer::init()) return false;

	//tạo animation
	Skater* skater = Skater::create("0.png");
	skater->setPosition(Config::centerPoint.x, Config::centerPoint.y);
	skater->runAnimation_Down();
	this->addChild(skater);
	return true;
}

Kid_Layer * Kid_Layer::create_Kid_Layer()
{
	Kid_Layer * layer = new Kid_Layer();
	layer->init();
	layer->autorelease();
	return layer;
}
