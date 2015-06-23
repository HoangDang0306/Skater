/*
 * SpawnObs.cpp
 *
 *  Created on: Jun 17, 2015
 *      Author: Dang
 */

#include "SpawnObs.h"
#include "Model/Car.h"
#include "Model/Bird.h"
#include "Model/Animal.h"
#include "Utility/Config.h"
#include <iostream>
using namespace std;

SpawnObs::SpawnObs() {
	// TODO Auto-generated constructor stub
	this->isGenerate = true;
	this->speed_Animal = 12.5f;
	this->speed_Car = 16.0f;
	this->speed_Bird = 14.0f;
}

SpawnObs::~SpawnObs() {
	// TODO Auto-generated destructor stub
}

SpawnObs * SpawnObs::createSpawnObs()
{
	SpawnObs * sObs = new SpawnObs();
	sObs->init();
	sObs->autorelease();
	return sObs;
}

void SpawnObs::SinhCar()
{
	if (this->isGenerate)
	{
		int i = random(1, 3);
		char name[100];
		sprintf(name, "Obtruction/car%i.png", i);
		Car * car = Car::create(name);
		car->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		car->MoveCar(this->speed_Car);
		this->addChild(car);

		auto sinh = CallFunc::create(CC_CALLBACK_0(SpawnObs::SinhCar, this));
		auto delay = DelayTime::create(random(10, 16));
		this->runAction(Sequence::createWithTwoActions(delay, sinh));
	}
}

void SpawnObs::SinhAni()
{
	if (isGenerate)
	{
		auto ani = Animal::create("0.png");
		ani->setScale(0.7);
		int k = cocos2d::random(1, 4);
		switch (k) {
		case 1:
			ani->runAnimation("dog", 4, 0.5f, true);
			break;
		case 2:
			ani->runAnimation("chick", 4, 0.5f, true);
			break;
		case 3:
			ani->runAnimation("cat", 4, 0.5f, true);
			break;
		case 4:
			ani->runAnimation("hour", 4, 0.5f, true);
			break;
		}
		ani->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		ani->MoveAnimal(this->speed_Animal);
		this->addChild(ani);

		auto sinh = CallFunc::create(CC_CALLBACK_0(SpawnObs::SinhAni, this));
		auto delay = DelayTime::create(random(4, 15));
		this->runAction(Sequence::createWithTwoActions(delay, sinh));
	}
}

void SpawnObs::SinhBird()
{
	if (this->isGenerate)
	{
		Bird * bird = Bird::create("bird.png");
		bird->setAnchorPoint(Vec2::ANCHOR_MIDDLE);
		bird->MoveBird(this->speed_Bird);
		bird->setScale(0.3);
		bird->runAnimation("bird", 4, 0.1f, true);
		this->addChild(bird);

		auto sinh = CallFunc::create(CC_CALLBACK_0(SpawnObs::SinhBird, this));
		auto delay = DelayTime::create(random(8, 12));
		this->runAction(Sequence::createWithTwoActions(delay, sinh));
	}
}
