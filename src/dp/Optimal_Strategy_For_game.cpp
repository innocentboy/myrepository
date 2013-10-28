/**
Problem statement: Consider a row of n coins of values v1 . . . vn, where n is even. We play a game against an
opponent by alternating turns. In each turn, a player selects either the first or last coin from the row, removes
it from the row permanently, and receives the value of the coin. Determine the maximum possible amount of money we
can definitely win if we move first.

Note: The opponent is as clever as the user.

Let us understand the problem with few examples:

    1. 5, 3, 7, 10 : The user collects maximum value as 15(10 + 5)

    2. 8, 15, 3, 7 : The user collects maximum value as 22(7 + 15)

Does choosing the best at each move give an optimal solution?

No. In the second example, this is how the game can finish:
*/

#import<iostream>
#import<cstdio>
using namespace std;

int max(int a, int b)  {    return a > b ? a : b;  }
int min(int a, int b)  {    return a < b ? a : b;  }

/**
Function for caculating the best value.
*/
int optimalStrategyOfGame(int* arr, int n)
{
    // Create a table to store solutions of subproblems
    int table[n][n], gap, i, j, x, y, z;

    // Fill table using above recursive formula. Note that the table
    // is filled in diagonal fashion (similar to http://goo.gl/PQqoS),
    // from diagonal elements to table[0][n-1] which is the result.
    for (gap = 0; gap < n; ++gap)
    {
        for (i = 0, j = gap; j < n; ++i, ++j)
        {
            // Here x is value of F(i+2, j), y is F(i+1, j-1) and
            // z is F(i, j-2) in above recursive formula
            x = ((i+2) <= j) ? table[i+2][j] : 0;
            y = ((i+1) <= (j-1)) ? table[i+1][j-1] : 0;
            z = (i <= (j-2))? table[i][j-2]: 0;
            table[i][j] = max(arr[i] + min(x, y), arr[j] + min(y, z));
           // printf("\n%d %d\n",arr[i],table[i][j]);
        }
    }
       //printf("\nvalue:%d\n",table[0][n-1]);
       return table[0][n-1];
}


/**
start of main function.
*/
int main()
{
    int arr1[]={1,5,10,9};
   // calculateOptimum(arr,sizeof(arr)/sizeof(arr[0]));
   //optimalStrategyOfGame(arr,4);

    //int arr1[] = {8, 15, 3, 7};
    int n = sizeof(arr1)/sizeof(arr1[0]);
    printf("%d\n", optimalStrategyOfGame(arr1, n));

    int arr2[] = {2, 2, 2, 2};
    n = sizeof(arr2)/sizeof(arr2[0]);
    printf("%d\n", optimalStrategyOfGame(arr2, n));

    int arr3[] = {20, 30, 2, 2, 2, 10};
    n = sizeof(arr3)/sizeof(arr3[0]);
    printf("%d\n", optimalStrategyOfGame(arr3, n));

    return 0;
}

