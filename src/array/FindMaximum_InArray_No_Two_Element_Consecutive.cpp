/**

*/

#include <cstdio>
#include <algorithm>
#include<iostream>
#include <vector>

using namespace std;

/**
Function for finding the maximum element when no two consecutive elements are selected.
*/
int FindMaxSum(int arr[], int n)
{
  int incl=0,excl=0,i;
  incl=arr[0];
  for(i=1;i<n;i++)
  {
    int new_excl=incl>excl?incl:excl;
    incl=arr[i]+excl;
    excl=new_excl;
  }
  return incl>excl?incl:excl;
}

int main()
{
  //int arr[] = {5, 5, 10, 100, 10, 5};
  int arr[] = {5,  5, 10, 40, 50, 35};

  printf("%d \n", FindMaxSum(arr, sizeof(arr)/sizeof(arr[0])));
  return 0;
}
