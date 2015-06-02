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
		case Tags::GROUND:
			return "GROUND";
		case Tags::SKATER:
			return "SKATER";
		case Tags::OBTRUCTION:
			return "OBTRUCTION";
		default:
			break;

		}
	}
	static const int GROUND = 11;
	static const int SKATER = 12;
	static const int OBTRUCTION = 13;
	Tags();
	~Tags();
};

#endif /* UTILITY_TAG_H_ */
