/**
http://www.codechef.com/problems/LEALCO
*/

/**
NOTE : JUST CHECK THE ALL POSSIBLE SUBSETS OF THE ARRAY, AND BY INCREMENTING THE EACH ELEMENT OF SUBSET OF ARRAY, KEEP CJECKING IT
		WHETHER IT'S , BAD ARRAY OR NOT. IF IT'S NOT RESULTING TO BAD ARRAY THEN COUNT THE NO. OF ELEMENTS IN THE SUBSET AND
		UPDATE THE ANSWER IF THE CURRENT SUBSET SIZE IS SMALLER THAN THE ANSWER.
		WE WOULD KEEP THE DIFFERENT SUBSET OF ARRAY, BY MASKING.
		IF AFTER APPLYING ALL THE SUBSET , WE ARE NOT GETTING THE GOOD ARRAY FOR ANY ONE , THEN THE ANSWER WOULD BE -1.
*/

/**
Input:
4
5 3 2
1 3 1 2 1
5 3 3
7 7 7 7 7
5 3 3
7 7 7 8 8
4 3 1
1 3 1 2

Output:
0
1
1
-1

*/

#include<cstdio>
#include<cmath>
#include<cstring>
#include <iostream>
using namespace std;
//int main()
void driver()
{

	
	//return 0;
}
