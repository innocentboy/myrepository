/**
LINK:::http://www.geeksforgeeks.org/find-water-in-a-glass/
*/
/**

Program to find amount of water in a given glass

There are some glasses with equal capacity as 1 litre. The glasses are kept as follows:

    			   1
		         2   3
		      4    5    6
		    7    8    9   10

You can put water to only top glass. If you put more than 1 litre water to
1st glass, water overflows and fills equally in both 2nd and 3rd glasses.
Glass 5 will get water from both 2nd glass and 3rd glass and so on.
If you have X litre of water and you put that water in top glass, how much water will be
contained by jth glass in ith row?

Example. If you will put 2 litre on top.
1st – 1 litre
2nd – 1/2 litre
3rd – 1/2 litre
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iostream>

using namespace std;

/**
Function which basically calculates the core part of the algorithm
for finding the water in the glass of jth elelment of ith row.
*/
float findWater(int i, int j, float X)
{
    //since we are dealing with 0th index
    i--;j--;
  if(j>i)
  {
    printf("\nwe can't find the water..\n");
    return -1;
  }
  int row,col,index,n;
  /**
  Till  ith row total no. of glass would not exceed with this value.
  */
  n=(i*(i+1))/2;
  float dp[n+1];
  /**
  initialise the DP[] array..
  */
  for(i=0;i<=n;i++)
   dp[i]=0;
  dp[0]=X;
  index=0;
  for(row=0;row<i&&X!=0.0;row++)
  {
    for(col=0;col<=row;col++,index++)
    {
       // printf("\ninside innner loop\n");
      /**
      calculate the amount of water present in this glass.
      */
       X=dp[index];
       // Keep the amount less than or equal to
       // capacity in current glass
       dp[index] = (X >= 1.0f) ? 1.0f : X;
       /**
       Remaining X water.
       */
       X=X>=1?(X-1):0;

       /**
       Amount distributed in both waters.
       */
       dp[row+index]+=X/2;
       dp[row+index+1]+=X/2;
    }
  }

  return dp[((i-1)*i)/2+j-1];
}

int main()
{
    int i = 2, j = 2;
    float X = 2.0; // Total amount of water

    printf("Amount of water in jth glass of ith row is: %f",
            findWater(i, j, X));

    return 0;
}





