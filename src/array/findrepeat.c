#include<stdio.h>
#include<stdlib.h>
void printRepeating(int arr[], int size)
{
     
  int i,index=0;
  printf("The repeating elements are: \n");
  for(i = 0; i < size; i++)
  {
     index=abs(arr[i]);
   if(arr[index] == 0)
       arr[index]=-size;
    else if(arr[index]>0 && arr[index]<size)
      arr[index] = -arr[index];
    else if(arr[index]<0)
      {
      printf(" %d ", abs(arr[i]));
      arr[index]=-arr[index];
      arr[index]+=size;
     }
  }
  printf("\n");
  //restore previous array
  for(i=0;i<size;i++)
  {
      arr[i]=abs(arr[i])%size;
      printf("%d ",arr[i]);
   }   
}

int main()
{
  //int arr[] = {1, 1,1,1,1,1,2,2,3,0,0,0};
  int arr[] = {1,3,0,1,1,2,1,0,1,0,3};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printRepeating(arr, arr_size);
  getchar();
  getch();
  return 0;
}  
/*void printRepeating(int arr[], int size)
{
  int i;
  printf("The repeating elements are: \n");
  for(i = 0; i < size; i++)
  {
    if(arr[abs(arr[i])] >= 0)
    {
      if(arr[i] == 0)
        arr[0] = -size; //put some negative value, could be anything negative
      else
        arr[abs(arr[i])] = -arr[abs(arr[i])];
    }
    else
      printf(" %d ", abs(arr[i]));
  }
}

int main()
{
  int arr[] ={1, 1,1,1,1,1,2,2,3,0,0,0};
  int arr_size = sizeof(arr)/sizeof(arr[0]);
  printRepeating(arr, arr_size);
 // getchar();
  getch();
  return 0;
} */
