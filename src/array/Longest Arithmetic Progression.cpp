/**
http://www.geeksforgeeks.org/length-of-the-longest-arithmatic-progression-in-a-sorted-array/
*/

/**
NOTE: 1. Sort the array.
      2. Now find the Length of Longest arithmetic sequence.
*/

/**
PROBLEM:   SUPPOSE THAT WE HAVE BEEN GIVEN THE SORTED ARRAY (IF NOT, THEN FIRST SORT THE ARRAY.)
            WE NEED TO FIND THE SEQUENCE OF THREE INTEGERS , WHICH FORMS THE AP.(ARITHMETIC
            PROGRESSION).
SOLUTION:   BOOL AIRTHMETIC(INT A[])
          {
            FOR(J=1;J<N-1;J++)
            {
              I=J-1;K=J+1;
              WHILE(I>=0&&k<=N-1)
              {
                IF(A[I]+A[K]==2*A[J])
                RETURN TRUE;
                ELSE IF(A[I]+A[K]>2*A[J])  //WE CAN DO THIS BECAUSE ARRAY IS SORTED.
                    I--;
                ELSE
                    K++;
              }
            }
            RETURN FALSE;
          }
*/

#include<cstdio>
#include<iostream>
#include<set>
#include <vector>
#include <algorithm>
#define N 100000
using namespace std;

int a[N];

int lenghtOfLongestAP(int a[],int n)
{
    int i,j,k;
    int dp[n+1][n+1];
    //fill the array dp[][]
    // since we know that , all the elements of the array are sorted, then
    //group of any two elements of the array would form the AP, sequence of length 2.
    for(i=0;i<n;i++)
      for(j=i+1;j<n;j++)
        dp[i][j]=2;

    int maxlen=2;
    //now calculate for the rest of the array..
    //with the same concept as descibed above for finding the , seuence of length 3 of AP
    //sequence in the array.
    for(j=n-2;j>0;j--)
    {
        i=j-1;k=j+1;
        while(i>=0&&k<=n-1)
        {
          if(a[i]+a[k]==2*a[j])
          {
            // It will increase the size by one of already calculated sized for
            // Maximum length LAP , of dp[j][k].
            dp[i][j]=1+dp[j][k];
            if(dp[i][j]>maxlen)
                maxlen=dp[i][j];
            i--;k++;
          }
          else if(a[i]+a[k]<2*a[j])
          {
            k++;
          }
          else
          {
            i--;
          }
        }
    }
    return maxlen;
}

int main()
{
    int set1[] = {1, 7, 10, 13, 14, 19};
    int n1 = sizeof(set1)/sizeof(set1[0]);
    cout <<   lenghtOfLongestAP(set1, n1) << endl;

    int set2[] = {1, 7, 10, 15, 27, 29};
    int n2 = sizeof(set2)/sizeof(set2[0]);
    cout <<   lenghtOfLongestAP(set2, n2) << endl;

    int set3[] = {2, 4, 6, 8, 10};
    int n3 = sizeof(set3)/sizeof(set3[0]);
    cout <<   lenghtOfLongestAP(set3, n3) << endl;

    int set4[] = {5, 10, 15, 20, 25, 30};
    int n4 = sizeof(set4)/sizeof(set4[0]);
    cout <<   lenghtOfLongestAP(set4, n4) << endl;

    return 0;
}
