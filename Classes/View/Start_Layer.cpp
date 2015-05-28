#include "Start_Layer.h"

Start_Layer::Start_Layer()
{
}

Start_Layer::~Start_Layer()
{
}

bool Start_Layer::init()
{
	if (!Layer::init()) return false;



	return true;
}

Start_Layer * Start_Layer::create_Start_Layer()
{
	Start_Layer * layer = new Start_Layer();
	layer->init();
	layer->autorelease();
	return layer;
}