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

	void SinhCar();
	void SinhAni();
	void SinhObs();
};

#endif /* MODEL_SPAWNOBS_H_ */
