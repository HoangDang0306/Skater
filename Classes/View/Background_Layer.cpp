#include "Background_Layer.h"


Background_Layer::Background_Layer()
{
}


Background_Layer::~Background_Layer()
{
}

bool Background_Layer::init()
{
	if (!Layer::init()) return false;



	return true;
}

Background_Layer * Background_Layer::create_Start_Layer()
{
	Background_Layer * layer = new Background_Layer();
	layer->init();
	layer->autorelease();
	return layer;
}