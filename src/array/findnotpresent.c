#include<stdio.h>
#include<stdlib.h>
void printRepeating(int arr[], int size)
{
     
  int i,index=0;
  printf("The repeating elements are: \n");
  for(i = 0; i < size; i++)
  {
     index=abs(arr[i])%size;
   if(arr[index] == 0)
       arr[index]=-size;
    else if(arr[index]>0 && arr[index]<size)
      arr[index] = -arr[index];
    else if(arr[index]<0)
      {
          printf(" %d ", abs(arr[i]));
          arr[index] = -arr[index];
          arr[index]+=size;
      }
  }
  //restore previous array
  printf("\n elements that are not present..\n");
  for(i=0;i<size;i++)
  {
          if(arr[i]>=0&&arr[i]<size)
          {
               printf(" %d",i);             
          }
          arr[i]=abs(arr[i])%size;
  }
}

int main()
{
  //int arr[] = {1, 1,1,1,1,1,2,2,3,0,0,0};
  int arr[] = {0,6,4,6,6,3},i;
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printRepeating(arr, arr_size);
  printf("\nprint the array..\n");
  for(i=0;i<arr_size;i++)
  {
          printf("%d  ",arr[i]);               
  }
  getch();
}  
