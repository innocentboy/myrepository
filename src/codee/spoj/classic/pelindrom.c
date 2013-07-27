#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 2000000
char pelindrm[N];
int main()
{
  int length,i,j,f=0,no,t;
  //printf("enter the value of pelindrom number\n");
  scanf("%d",&t);
  while(t-->0){
  scanf("%s",pelindrm);
  length=strlen(pelindrm); 
  while(f==0)
  {
          j=0;   
          length=strlen(pelindrm);    
          no=atoi(pelindrm);
          no++;      
          sprintf(pelindrm,"%d",no);
          for(i=0;i<(length+1)/2;i++)
          {  //printf("\n%c  %c",pelindrm[i],pelindrm[length-i-1]);
              if(pelindrm[i]==pelindrm[length-i-1])
              {
                  j++;                                   
              } 
              else
              {
                break;    
              }                     
          }
          if(j==(length+1)/2)
          f=1; 
            
  } 
  if(f==1)
  {
          printf("\n%s",pelindrm);        
  }f=0;
 } 
  getch();  
  return 0;  
}
