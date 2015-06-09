/*
 * Tags.h
 *
 *  Created on: Apr 9, 2015
 *      Author: conghoang
 */

#ifndef UTILITY_TAGS_H_
#define UTILITY_TAGS_H_
#include <iostream>
using namespace std;
class Tags {
private:

public:
	static string getName(int tag)
	{
		switch (tag)
		{
		case Tags::COIN:
			return "COIN";
		case Tags::OBSTRUCTION:
			return "OBSTRUCTION";
		case Tags::SKATER:
			return "SKATER";
		case Tags::COIN_SKATER_COLLISION:
			return "COIN_SKATER_COLLISION";
		case Tags::COIN_SKATER_CATEGORY:
			return "COIN_SKATER_CATEGORY";
		case Tags::ITEM:
			return "ITEM";
		default:
			break;

		}
	}
	static const int COIN = 11;
	static const int OBSTRUCTION = 12;
	static const int SKATER = 13;
	static const int SHURIKEN = 14;
	static const int COIN_SKATER_COLLISION = 15;
	static const int COIN_SKATER_CATEGORY = 16;
	static const int ITEM = 17;
	Tags();
	~Tags();
};

#endif /* UTILITY_TAG_H_ */
