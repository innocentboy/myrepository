#include<stdio.h>
#include<conio.h>
int minDiff(int arr[], int arr_size)
{
     int a,b;
     int min_diff = abs(arr[1] - arr[0]);
     int max_element = arr[0];
     int min_element=arr[0];
     int i;
     for(i = 1; i < arr_size; i++)
     {




           if(abs(arr[i] - max_element) < min_diff)
           {
                min_diff = abs(arr[i] - max_element);
                a=arr[i];
                b=max_element;
                if(arr[i] > max_element)
                max_element = arr[i];
           }

          if(abs(arr[i] - min_element) < min_diff)
          {
                min_diff = abs(arr[i] - min_element);
                a=arr[i];
                b=min_element;
                if(arr[i] < min_element)
                min_element = arr[i];
          }



      }
      printf("value of no.. %d %d\n",a,b);
      return min_diff;
}
int main()
{
    int arr[] = {5, 13, 27, 0,1, 10, 21, 3, 15, 28, 20};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Minimum difference is %d\n", minDiff(arr, size));
    getchar();
    return 0;
}
