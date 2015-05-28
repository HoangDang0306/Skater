#include "Kid_Layer.h"


Kid_Layer::Kid_Layer()
{
}


Kid_Layer::~Kid_Layer()
{
}

bool Kid_Layer::init()
{
	if (!Layer::init()) return false;



	return true;
}

Kid_Layer * Kid_Layer::create_Kid_Layer()
{
	Kid_Layer * layer = new Kid_Layer();
	layer->init();
	layer->autorelease();
	return layer;
}
