/**
LINK:::http://www.geeksforgeeks.org/dynamic-programming-set-18-word-wrap/

Dynamic Programming | Set 19 (Word Wrap Problem)
*/

#include<cstdio>
#include<iostream>
#include<algorithm>
#define INF 999999999

using namespace std;

int printSolution (int p[], int n)
{
    int k;
    if (p[n] == 1)
        k = 1;
    else
        k = printSolution (p, p[n]-1) + 1;
    printf ("Line number %d: From word no. %d to %d \n", k, p[n], n);
    return k;
}

/**
This is the main function for calculating the wordWrap problem.
*/
void solveWordWrap(int l[],int n,int M)
{
    int i,j,k;
    int extra[n+1][n+1];
    int lc[n+1][n+1];
    int c[n+1];
    /**
    extra[][] array will contain the possible Blank spaces between the ith and jth word..
    */
    for(i=1;i<=n;i++)
    {
        extra[i][i]=M-l[i-1];
      for(j=i+1;j<=n;j++)
      {
         extra[i][j]=extra[i][j-1]-l[j-1]-1;
         //-1 is because we are considering the sigle space betwenn the words.

      }
    }

    /**
    l[][] array contains the cost of putting the ith to jth word in a single line
    */
    for(i=1;i<=n;i++)
    {
      for(j=i;j<=n;j++)
      {
        if(extra[i][j]<0)
           lc[i][j]=INF;
        else if(j==n && extra[i][j]>=0)
           lc[i][j]=0;
        else
           lc[i][j]=extra[i][j]*extra[i][j];
           //We have sppose that cost is equal to the square of the space required
           //in putting the words from ith to jth word in a line.
      }
    }

    /**
    Now c[] array calculate the least possible cost of putting the all words
    */
    int p[n+1];
    c[0]=0;
    for(i=1;i<=n;i++)
    {
      c[i]=INF;
      for(j=1;j<=i;j++)
      {
        if(c[j-1]!=INF&&lc[j][i]!=INF&&(c[j-1]+lc[j][i]<c[i]))
          c[i]=c[j-1]+lc[j][i];
          p[i]=j;
      }
    }
    /**
    c[0] = 0;
    for (j = 1; j <= n; j++)
    {
        c[j] = INF;
        for (i = 1; i <= j; i++)
        {
            if (c[i-1] != INF && lc[i][j] != INF && (c[i-1] + lc[i][j] < c[j]))
            {
                c[j] = c[i-1] + lc[i][j];
                p[j] = i;
            }
        }
    }
    */

    printSolution(p,n);
}


// Driver program to test above functions
int main()
{
    int l[] = {3, 2, 2, 5};
    int n = sizeof(l)/sizeof(l[0]);
    int M = 6;
    solveWordWrap (l, n, M);
    return 0;
}
