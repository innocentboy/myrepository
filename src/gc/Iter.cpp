/*
 * Iter.cpp
 *
 *  Created on: Jun 16, 2013
 *      Author: pandit
 */

#include <cstdio>
template<class T>
class Iter {
public:
	Iter()
	{
		printf("inside the iter constructor.");
	}
	virtual ~Iter()
	{
		printf("\ninside the destructor..\n");
	}
};



