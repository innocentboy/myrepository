/*
   this file contains related to array..

*/
/*
this file contains code related to strings..
*/
#include<cstdio>
#include<string>
#include<algorithm>
#include<vector>
#include<map>
#include<stack>
#include<cmath>
#define N 10000
#define ESP 1e-6

using namespace std;
int a[N][N],n,m;
int dp[N][N];
stack<int> st;
struct std
{
      int s,f;
}assign[N];

struct stud
{
  int offset;
  int type;
};

vector<int> d(N,-1),d1(N),d2(N);
int getSum(int i,int j,int r,int c);

/**
Printing spiral matrix..
*/
void spiralPrint(int m, int n, int a[R][C])
{
    int i, k = 0, l = 0;

    /*  k - starting row index
        m - ending row index
        l - starting column index
        n - ending column index
        i - iterator
    */

    while (k < m && l < n)
    {
        /* Print the first row from the remaining rows */
        for (i = l; i < n; ++i)
        {
            printf("%d ", a[k][i]);
        }
        k++;

        /* Print the last column from the remaining columns */
        for (i = k; i < m; ++i)
        {
            printf("%d ", a[i][n-1]);
        }
        n--;

        /* Print the last row from the remaining rows */
        if ( k < m)
        {
            for (i = n-1; i >= l; --i)
            {
                printf("%d ", a[m-1][i]);
            }
            m--;
        }

        /* Print the first column from the remaining columns */
        if (l < n)
        {
            for (i = m-1; i >= k; --i)
            {
                printf("%d ", a[i][l]);
            }
            l++;
        }
    }
}
/**
end..
*/

/**
Maximum circular subarray sum
September 18, 2012

Given n numbers (both +ve and -ve), arranged in a circle, fnd the maximum sum of consecutive number.

Examples:

Input: a[] = {8, -8, 9, -9, 10, -11, 12}
Output: 22 (12 + 8 - 8 + 9 - 9 + 10)

Input: a[] = {10, -3, -4, 7, 6, 5, -4, -1}
Output:  23 (7 + 6 + 5 - 4 -1 + 10)

Input: a[] = {-1, 40, -14, 7, 6, 5, -4, -1}
Output: 52 (7 + 6 + 5 - 4 - 1 - 1 + 40)

*/
int maxCircularSum (int a[], int n)
{
   // Case 1: get the maximum sum using standard kadane's algorithm
   int max_kadane = kadane(a, n);

   // Case 2: Now find the maximum sum that includes corner elements.
   int max_wrap  =  0, i;
   for(i=0; i<n; i++)
   {
        max_wrap += a[i]; // Calculate array-sum
        a[i] = -a[i];  // invert the array (change sign)
   }

   // max sum with corner elements will be:
   // array-sum - (-max subarray sum of inverted array)
   max_wrap = max_wrap + kadane(a, n);

   // The maximum circular sum will be maximum of two sums
   return (max_wrap > max_kadane)? max_wrap: max_kadane;
}

/**
end..
*/
/**
Given two no's X and Y of array find the minimum distance between them..
*/
int minimumDistance(int arr[],int n,int x,int y)
{
  int i,j,k,prev=-1,mindist=99999;
  for(i=0;i<n;i++)
  {
    if(arr[i]==x||arr[i]==y)
    {
      prev=i;
      break;
    }
  }
  for(;i<n;i++)
  {
    if(arr[i]==x||arr[i]==y)
    {
      if(arr[i]!=arr[prev]&&i-prev<mindist)
      {
          mindist=i-prev;
          prev=i;
          else
          prev=i;
        }
    }
  }
   printf("Minmimum distance between the are:%d\n",mindist);
}

/**
end..
*/

/**
Given an array arr[], find the maximum j – i such that arr[j] > arr[i]
May 21, 2011

Given an array arr[], find the maximum j – i such that arr[j] > arr[i].

Examples:

  Input: {34, 8, 10, 3, 2, 80, 30, 33, 1}
  Output: 6  (j = 7, i = 1)
*/
int maxIndexDiff(int arr[], int n)
{
    int maxDiff;
    int i, j;

    int *LMin = (int *)malloc(sizeof(int)*n);
    int *RMax = (int *)malloc(sizeof(int)*n);

   /* Construct LMin[] such that LMin[i] stores the minimum value
       from (arr[0], arr[1], ... arr[i]) */
    LMin[0] = arr[0];
    for (i = 1; i < n; ++i)
        LMin[i] = min(arr[i], LMin[i-1]);

    /* Construct RMax[] such that RMax[j] stores the maximum value
       from (arr[j], arr[j+1], ..arr[n-1]) */
    RMax[n-1] = arr[n-1];
    for (j = n-2; j >= 0; --j)
        RMax[j] = max(arr[j], RMax[j+1]);

    /* Traverse both arrays from left to right to find optimum j - i
        This process is similar to merge() of MergeSort */
    i = 0, j = 0, maxDiff = -1;
    while (j < n && i < n)
    {
        if (LMin[i] < RMax[j])
        {
            maxDiff = max(maxDiff, j-i);
            j = j + 1;
        }
        else
            i = i+1;
    }

    return maxDiff;
}

/**
end..
*/

/**

Rotate matrix by 90 degree..
for(r = 0; r < m; r++)
{
   for(c = 0; c < n; c++)
   {
      // Hint: Map each source element indices into
      // indices of destination matrix element.
       dest_buffer [ c ] [ m - r - 1 ] = source_buffer [ r ] [ c ];
   }
}
*/
void rotate(unsigned int *pS, unsigned int *pD, unsigned int row, unsigned int col)
{
    unsigned int r, c;
    for(r = 0; r < row; r++)
    {
        for(c = 0; c < col; c++)
        {
            *(pD + c * row + (row - r - 1)) = *(pS + r * col + c);
        }
    }
}

/**
end..
*/

/**
Given an array of integers where each element represents the max number of steps
that can be made forward from that element. Write a function to return the minimum number of jumps
to reach the end of the array (starting from the first element). If an element is 0, then cannot move through
that element.

Example:

Input: arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9}
Output: 3 (1-> 3 -> 8 ->9)

*/
int minJumps(int arr[], int n)
{
    int *jumps = new int[n];  // jumps[n-1] will hold the result
    int i, j;

    if (n == 0 || arr[0] == 0)
        return INT_MAX;

    jumps[0] = 0;

    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++)
    {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++)
        {
            if (i <= j + arr[j] && jumps[j] != INT_MAX)
            {
                 jumps[i] = jumps[j] + 1;
                 break;
            }
        }
    }
    return jumps[n-1];
}

/**
end..
*/

/**

Given an unsorted array of nonnegative integers, find a continous subarray which adds to a given number.

Examples:

Input: arr[] = {1, 4, 20, 3, 10, 5}, sum = 33
Ouptut: Sum found between indexes 2 and 4


*/
int subArraySum(int arr[], int n, int sum)
{
    /* Initialize curr_sum as value of first element
       and starting point as 0 */
    int curr_sum = arr[0], start = 0, i;

    /* Add elements one by one to curr_sum and if the curr_sum exceeds the
       sum, then remove starting element */
    for (i = 1; i <= n; i++)
    {
        // If curr_sum exceeds the sum, then remove the starting elements
        while (curr_sum > sum && start < i-1)
        {
            curr_sum = curr_sum - arr[start];
            start++;
        }

        // If curr_sum becomes equal to sum, then return true
        if (curr_sum == sum)
        {
            printf ("Sum found between indexes %d and %d", start, i-1);
            return 1;
        }

        // Add this element to curr_sum
        if (i < n)
          curr_sum = curr_sum + arr[i];
    }

    // If we reach here, then no subarray
    printf("No subarray found");
    return 0;
}

/**
end..
*/

/**

Given an array that contains both positive and negative integers, find the product of
the maximum product subarray. Expected Time complexity is O(n) and only O(1) extra space can be used.

Examples:

Input: arr[] = {6, -3, -10, 0, 2}
Output:   180  // The subarray is {6, -3, -10}
*/
int maxSubarrayProduct(int arr[], int n)
{
    // max positive product ending at the current position
    int max_ending_here = 1;

    // min negative product ending at the current position
    int min_ending_here = 1;

    // Initialize overall max product
    int max_so_far = 1;

    /* Traverse throught the array. Following values are maintained after the ith iteration:
       max_ending_here is always 1 or some positive product ending with arr[i]
       min_ending_here is always 1 or some negative product ending with arr[i] */
    for (int i = 0; i < n; i++)
    {
        /* If this element is positive, update max_ending_here. Update
           min_ending_here only if min_ending_here is negative */
        if (arr[i] > 0)
        {
            max_ending_here = max_ending_here*arr[i];
            min_ending_here = min (min_ending_here * arr[i], 1);
        }

        /* If this element is 0, then the maximum product cannot
           end here, make both max_ending_here and min_ending_here 0
           Assumption: Output is alway greater than or equal to 1. */
        else if (arr[i] == 0)
        {
            max_ending_here = 1;
            min_ending_here = 1;
        }

        /* If element is negative. This is tricky
           max_ending_here can either be 1 or positive. min_ending_here can either be 1
           or negative.
           next min_ending_here will always be prev. max_ending_here * arr[i]
           next max_ending_here will be 1 if prev min_ending_here is 1, otherwise
           next max_ending_here will be prev min_ending_here * arr[i] */
        else
        {
            int temp = max_ending_here;
            max_ending_here = max (min_ending_here * arr[i], 1);
            min_ending_here = temp * arr[i];
        }

        // update max_so_far, if needed
        if (max_so_far <  max_ending_here)
          max_so_far  =  max_ending_here;
    }

    return max_so_far;
}

/**
end..
*/

/**
claculates the sqrt of number..
*/
double sqrt(double x)
{
  double x1,x2;
  x1=x;x2=x-0.1;
  while(fabs(x2-x1)>ESP)
  {
     x1=x2;
     x2=x1-(((x1*x1)-x)/2*x1);
   }
   return x2;
}

/**
end of function..
*/

/**
this is Marzullo's algorithm..
this method finds the MAXIMUM OVERLAPPING INTERVALS.
START..
*/

inline bool cmp_interval(struct stud a,struct stud b)
{
    if(a.offset<b.offset) return true;
    return false;
}

void maximum_overlap_interval()
{
    printf("\n**** maximum interval overlap. *****\n");
    struct stud interval[2*N];
    int i,j,k,l=0,best=0,cnt=0,best_start=-1,best_end=-1,len=0;
    scanf("%d",&n);
    len=2*n;
    for(i=0;i<n;i++){
    scanf("%d%d",&j,&k);
    interval[l].offset=j;interval[l++].type=-1;
    interval[l].offset=k;interval[l++].type=+1;
    }
    sort(interval,interval+l,&cmp_interval);
    printf("print intervals in sorted order\n");
    for(i=0;i<l;i++)
    printf("%d %d\n",interval[i].offset,interval[i].type);
    for(i=0;i<l;i++)
    {
      cnt=cnt-interval[i].type;
      if(cnt>best)
      {
         best=cnt;
         best_start=interval[i].offset;
         best_end=interval[i+1].offset;
       }
    }
    printf("\nlength of overlapping intervals:%d\n",best);
    printf("\nmaximum inteval value:[%d %d]\n",best_start,best_end);
}

/**
end of the function..
*/


/**
this method by appling the greedy approach calculates the length of longest assignment  in an interval
given starting and finishing time of activities.
start...
*/

inline bool comp(struct std a,struct std b)
{
  if(a.f<=b.f) return true;
  else return false;
}


int max_assignment_length()
{
   int s[N],f[N],temp[N],k=0,i,j,l;
   scanf("%d",&n);
   for(i=0;i<n;i++)
   scanf("%d%d",&assign[i].s,&assign[i].f);
   sort(assign,assign+n,comp);
   printf("\n");
 //  for(i=0;i<n;i++)
  // printf("%d ",f[i]);
   k=0,l=1;temp[0]=0;
   for(i=1;i<n;i++)
   {
      if(assign[i].s>=assign[k].f)
      {
          temp[l++]=i;
          k=i;
        }
    }
    printf("\n**** elements invovlved in assignment. ***\n");
    for(i=0;i<l;i++)
    printf("%d ",temp[i]);
    scanf("%d",&i);
}
/**
end of the method
*/


/**
  inplace transform function begins.
*/
void array_transform_inplace()
{
    int i,j,k;
    printf("\n arry before transform.\n");
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {

          printf("%d ",a[i][j]);
        }

        printf("\n");
    }

    for(i=0;i<n;i++)
    {
       for(j=i;j<n;j++)
       {
          if(i==j)
          continue;
          else
          {
              if(a[i][j]==a[j][i]);

              else
              {
                a[i][j]^=a[j][i]^=a[i][j]^=a[j][i];
             }
           }
       }
    }
    printf("\n array after transform..\n");
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {

          printf("%d ",a[i][j]);
        }

        printf("\n");
    }

}
/**
  inplace transform function of array ends.
*/


/**
this function calculates the maximum sum rectangle in 2D array.
start of the function.
tag:DP
*/
void max_sum_array()
{
   int i,j,r,c,max_sum=-1,ans=0;
   dp[0][0]=a[0][0];
   for(i=1;i<n;i++){
   dp[i][0]+=dp[i-1][0]+a[i][0];
   dp[0][i]+=dp[0][i-1]+a[0][i];
   }
   for(i=1;i<n;i++)
   {
      for(j=1;j<n;j++)
      {
        dp[i][j]+=a[i][j]+dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1];
      }
   }
    printf("\n ************* \n");
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      printf("%2d ",dp[i][j]);
      printf("\n");
    }
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        for(r=i;r<n;r++)
          for(c=j;c<n;c++)
          {
             ans=getSum(i,j,r,c);
             max_sum=max(max_sum,ans);
          }
    printf("\n\********\n");
    printf("maximum sum:%d",max_sum);
}

int getSum(int i,int j,int r,int c)
{
   if(i==0&&j==0) return dp[r][c];
   if(i==0) return dp[r][c]-dp[r][j-1];
   if(j==0) return dp[r][c]-dp[i-1][c];
   return dp[r][c]+dp[i-1][j-1]-dp[i-1][c]-dp[r][j-1] ;
}
/**
end of the function.
*/



/**
this is start of the function checking largest square in an 0 and 1s'array ,whose border is covered with the 1's.
irrespective of no of 0's aand 1's inside that square.
start of the function.
tag: brute force.
*/

int isSuqare(int row,int col,int size)
{
  int i,j,k;
  for (int j = 0; j < size; j++){
      if (a[row][col+j]==0) {
        return 0;
      }
      if (a[row+size-1][col+j]==0){
        return 0;
      }
    }

    // Check left and right border.
    for (int i = 1; i < size - 1; i++){
      if (a[row+i][col]==0){
        return 0;
      }
      if (a[row+i][col+size-1]==0){
        return 0;
       }
    }
   return 1;
}



int max_square_with_border()
{
   int r=-1,c=-1,max_size=0,col=0,row;
   while(N-col>=max_size)
   {
       for(row=0;row<n;row++)
       {
         int size=n-max(row,col);
         while(size>max_size)
         {
            if(isSuqare(row,col,size))
            {
              max_size=size;
              r=row;c=col;
              break;
            }
            size--;
          }
        }
        col++;
    }
    printf("\n\***** Maximum size suqare *****\n");
    printf("row:%d\ncol:%d\nsize:%d",r,c,max_size);
}



/**
end of the function.
*/

/**
this function calculates the the largest size square containing all 1's.
tag:dp
start of the function.
*/

void maximum_size_square()
{
   int i,j,k,maxsize=-1;
   for(i=0;i<n;i++)
   {
     for(j=0;j<n;j++)
     {
        if(a[i][j]==0)
        dp[i][j]=0;
        else
        {
          if(i==0||j==0)
          dp[i][j]=1;
          else
          dp[i][j]=min(min(dp[i-1][j-1],dp[i-1][j]),dp[i][j-1])+1;
        }
      }
    }
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        maxsize=max(maxsize,dp[i][j]);
    printf("\n*** largest size square ****\n size:%d",maxsize);
}


/**
end of the function
*/


/**
this function calculates the largest size rectangle containing all 1's (or 0's).
start of the function.
*/

void largest_size_rectangle()
{

      int i,j,k,ans=-1;
      printf("\ncompute maximun size rectangle.\n");
      scanf("%d%d",&n,&m);
      for(i=0;i<n;i++)
      {
          for(j=0;j<m;j++)
          scanf("%d",&a[i][j]);
        }

      for(i=0;i<n;i++)
      {
         for(j=0;j<m;j++)
         {
            if(a[i][j]==0)
            d[j]=i;
          }
          while(!st.empty()) st.pop();
         for(j=0;j<m;j++)
         {
            while(!st.empty()&&d[j]>=d[st.top()])st.pop();
            d1[j]=st.empty()?-1:st.top();
            st.push(j);
          }
          while(!st.empty()) st.pop();
          for(j=m-1;j>=0;j--)
          {
              while(!st.empty()&&d[j]>=d[st.top()]) st.pop();
              d2[j]=st.empty()?m:st.top();
              st.push(j);
            }
          for(j=0;j<m;j++)
          {
              ans=max(ans,(i-d[j])*(d2[j]-d1[j]-1));
            }
      }
      printf("\n***** Length of largest rectangle *******\n");
      printf("max area:%d",ans);
}

/**
end of the function.
*/


/**
   start of MAIN function
*/
int main()
{

   int i,j;
  // scanf("%d",&n);
   for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {

          //scanf("%d",&a[i][j]);
        }
    }
   // array_transform_inplace();
   // max_sum_array();
   // max_square_with_border();
   // maximum_size_square();
   //largest_size_rectangle();
    //max_assignment_length();
   // maximum_overlap_interval();
   printf("sqrt root of no is:%f\n",sqrt(16));
   return 0;
}



