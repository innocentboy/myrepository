/*
  this is  a programm for finding the length of the maximum non-repeatable substring in a given string..
*/
#include<stdio.h>
#define N 27
#define len 100000
int arr[N];
char str[len];
int main()
{
  int i,j,max_len,cur_len,pre_indx,length;
  char *s=str;
  printf("enter the value of the string\n");
  scanf("%s",str);
  length=strlen(str);
  for(i=0;i<N;i++)
  arr[i]=-1;
  arr[str[0]-'A']=0;
  cur_len=max_len=1;
  for(i=1;i<length;i++)
  {
    pre_indx=arr[str[i]-'A'];
    if(pre_indx==-1||i-cur_len>pre_indx)
    cur_len++;
    else
    {
      if(cur_len>max_len)
      max_len=cur_len;
      cur_len=i-pre_indx;    
    }
    arr[str[i]-'A']=i;                     
  }  
  if(cur_len>max_len)max_len=cur_len;
  printf("\nmaximum lenght is :%d",max_len);
  getch();  
  return 0;    
}
