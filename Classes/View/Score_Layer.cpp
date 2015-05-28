#include "Score_Layer.h"


Score_Layer::Score_Layer()
{
}


Score_Layer::~Score_Layer()
{
}

bool Score_Layer::init()
{
	if (!Layer::init()) return false;



	return true;
}

Score_Layer * Score_Layer::create_Score_Layer()
{
	Score_Layer * layer = new Score_Layer();
	layer->init();
	layer->autorelease();
	return layer;
}