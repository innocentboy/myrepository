#include<stdio.h>
#include<conio.h>
#define N 10
int maxSum(int a[], int n){
int first = -1;
int second = a[0];
int third = a[1];
int i,tmp;
for(i =2;i<n;i++) 
  {

  if(first > second)
     tmp =a[i]+first;
  else
     tmp =a[i]+second;
   
   first = second;
   second = third;
   third = tmp;
 }
   return third;
}

int main()
{
    int a[]={1,5,9,8,2,2,4,1},maxsum;
    maxsum=maxSum(a,sizeof(a)/sizeof(a[0]));
    printf("max sum is: %d",maxsum);
    getch();
        
    
}


