/*
 * SpawnObs.h
 *
 *  Created on: Jun 17, 2015
 *      Author: Dang
 */

#ifndef MODEL_SPAWNOBS_H_
#define MODEL_SPAWNOBS_H_
#include "cocos2d.h"
USING_NS_CC;

class SpawnObs : public Node
{
public:
	SpawnObs();
	virtual ~SpawnObs();
	static SpawnObs * createSpawnObs();

	//Speed
	float speed_Car;
	float speed_Animal;
	float speed_Bird;

	bool isGenerate;
	void SinhCar();
	void SinhAni();
	void SinhObs();
	void SinhBird();
};

#endif /* MODEL_SPAWNOBS_H_ */
