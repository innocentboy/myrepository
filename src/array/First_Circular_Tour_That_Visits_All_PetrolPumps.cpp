/**
Suppose there is a circle. There are n petrol pumps on that circle. You are given two sets of data.

1. The amount of petrol that petrol pump will give.
2. Distance from that petrol pump to the next petrol pump.

Calculate the first point from where a truck will be able to complete the circle
(The truck will stop at each petrol pump and it has infinite capacity). Expected time complexity is O(n).
Assume for 1 litre petrol, the truck can go 1 unit of distance.

For example, let there be 4 petrol pumps with amount of petrol and distance to next petrol pump value
pairs as {4, 6}, {6, 5}, {7, 3} and {4, 5}. The first point from where truck can make a circular tour is
 2nd petrol pump. Output should be “start = 1″ (index of 2nd petrol pump).
*/

#include<cstdio>
#include<iostream>
#include<queue>
#include<set>
#include<algorithm>
#include<vector>

using namespace std;

struct petrolPump
{
  int petrol;
  int distance;
};

/**
FINDS THE FIRST SUCH INDEX WHICH COMPLETES THE PETROL PUMP CIRCULAR TOUR..

DATA STRUCTURE: THIS IS USING THE QUEUE DATA STRUCTURE..
*/
int printTour(struct petrolPump arr[],int n)
{
   int i,j,k,start,end,current_petrol;
   start=0;end=1;
   current_petrol=arr[start].petrol-arr[start].distance;
   while(start!=end||current_petrol<0)
   {
       while(start!=end&&current_petrol<0)
       {
          current_petrol-=arr[start].petrol-arr[start].distance;
          start=(start+1)%n;
          /**
          NO SOLUTION EXITS FOR THIS CASE;
          */
          if(start==0)
          return -1;
       }
        current_petrol+=arr[end].petrol-arr[end].distance;
        end=(end+1)%n;
    }
    return start;
}

/**
BY USING BUILDIN QUEUE STL OF C++;
*/
int printTour_QUEUE(struct petrolPump arr[],int n)
{
   int i,j,k,front,rear,current_petrol;
   front=0;rear=1;
   queue<int> q;
   q.push(0);q.push(1);
   front=q.front();
   current_petrol=arr[front].petrol-arr[front].distance;
   while((q.front()!=q.back())||current_petrol<0)
   {
       while((q.front()!=q.back())&&current_petrol<0)
       {
          front=q.front();
          q.pop();
          current_petrol-=arr[front].petrol-arr[front].distance;
          front=(front+1)%n;
          /**
          NO SOLUTION EXITS FOR THIS CASE;
          */
          if(front==0)
          return -1;
          q.push(front);
       }

        rear=q.back();
        current_petrol+=arr[rear].petrol-arr[rear].distance;
        rear=(rear+1)%n;
        q.push(rear);
    }
    return q.front();
}

int main()
{

    struct petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};
    //struct petrolPump arr[]={{4, 6}, {6, 5}, {7, 3},{4, 5}};
    int n = sizeof(arr)/sizeof(arr[0]);
    int start = printTour(arr, n);
    (start == -1)? printf("No solution\n"): printf("Start = %d\n", start);

    /*
      Byusing Queue
    */
     start = printTour_QUEUE(arr, n);
    (start == -1)? printf("No solution\n"): printf("Using Queue Start = %d\n", start);

     return 0;
}
