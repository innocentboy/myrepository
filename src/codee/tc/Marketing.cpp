/**
http://community.topcoder.com/stat?c=problem_statement&pm=1524&rd=4472
SOL: Since we need to divide the market component into TWO COMPETETER. We can apply the concept of 2-Coloring
	in graph, for finding the all possible components in the graph. And that we could easily calculate
	the No of ways for dividing the graph into competers such that competeter, would not be in the same list.
	At the same time, if I am getting the Cycle, then devision is not possible.

*/
/**
INPUT:


OUTPUT:
*/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;
#define N 100

void driver()
{
	printf("\ndriver of marketing is running..\n");
}
