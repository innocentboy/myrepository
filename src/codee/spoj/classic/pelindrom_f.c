#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 1000001
char pelindrm[N];
char nextpelindrm[N];
int main()
{
  int length,i,j,f=0,no=0,t=0,k=0;
  //printf("enter the value of pelindrom number\n");
  scanf("%d",&t);
  printf("\n");
  while(t-->0){f=0;
  scanf("%s",pelindrm);
  printf("\n");
  length=strlen(pelindrm);
  strcpy(nextpelindrm,pelindrm);
  j=length/2; 
  k=j;
  if(length%2==0)
  {
      f=1;           
      j--;
      for(i=j+1;i<length;i++)
      {
         nextpelindrm[i]=pelindrm[j];
         j--;                       
      }               
  }
  else
  {
       for(i=j;i<length;i++)
      {
         nextpelindrm[i]=pelindrm[j];
         j--;                       
      }  
      
  }
  if(f==1)
  {f=0;
      for(i=k;i<length;i++)
      {
         if(nextpelindrm[i]==pelindrm[i])
         continue;
         else if(nextpelindrm[i]>pelindrm[i])
         {
             f=1;
             break; 
         } 
         else
         break;                                  
      }        
      if(f==1)
      {
         printf("\n%s",nextpelindrm);        
      }
      else
      {
          j=k-1;
         if(nextpelindrm[j]<'9')
         {
            nextpelindrm[j]=nextpelindrm[k]=nextpelindrm[j]+1; 
            printf("\n%s",nextpelindrm);                    
         }    
         else
         {
           i=j;
           while(i>=0)
           {
               if(nextpelindrm[j]=='9')
               {
                  nextpelindrm[j]=nextpelindrm[k]='0';
                  j--;
                  k++;                   
               }
               else
               {  
                  if(nextpelindrm[j]<='8') 
                  {no=nextpelindrm[j]+1;
                   nextpelindrm[j]=no;
                   nextpelindrm[k]=no;
                  break; }
                  else
                  {
                       nextpelindrm[j]='0';
                       nextpelindrm[k]='0';
                       j--;
                       k++;   
                  }  
               }i--;              
           } 
           if(i<=-1)
           {
                  length=strlen(nextpelindrm);
                  for(i=1;i<length;i++)
                  {
                     pelindrm[i]='0';                      
                  } pelindrm[i]='1';
                  pelindrm[++i]='\0';
                  pelindrm[0]='1';
                  printf("\n%s",pelindrm);
           }else  printf("\n%s",nextpelindrm); 
         } 
      } 
  }
  else
  {   f=0;
      for(i=k+1;i<length;i++)
      {
         if(nextpelindrm[i]==pelindrm[i])
         continue;
         else if(nextpelindrm[i]>pelindrm[i])
         {
             f=1;
             break; 
         } 
         else
         break;                                  
      }        
      if(f==1)
      {
         printf("\n%s",nextpelindrm);        
      }
      else
      {
          j=k;
         if(nextpelindrm[j]<'9')
         {
            no=nextpelindrm[j]+1;                    
            nextpelindrm[j]=no;
            nextpelindrm[k]=no; 
            printf("\n%s",nextpelindrm);                    
         }    
         else
         {   i=j;
           
           while(i>=0)
           {
               if(nextpelindrm[j]=='9')
               {
                  nextpelindrm[j]='0';
                  nextpelindrm[k]='0';
                  j--;
                  k++;                   
               }
               else
               {  
                  if(nextpelindrm[j]<='8') 
                  {no=nextpelindrm[j]+1;
                   nextpelindrm[j]=no;
                   nextpelindrm[k]=no;
                  break; }
                  else
                  {
                       nextpelindrm[j]='0';
                       nextpelindrm[k]='0';
                       j--;
                       k++;   
                  }  
               }i--;           
           } 
           if(i<=-1)
           {
                  //length=strlen(nextpelindrm);
                //  printf("\nlength:%d",length);
                  for(i=1;i<length;i++)
                  {
                     pelindrm[i]='0';                      
                  } 
                  pelindrm[i]='1';
                  pelindrm[++i]='\0';
                  pelindrm[0]='1';
                  printf("\n%s",pelindrm);
           } else printf("\n%s",nextpelindrm); 
         } 
      } 
  }
 } getch();  
  return 0;  
}

