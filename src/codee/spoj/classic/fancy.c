#include<stdio.h>
#include<math.h>
#include<string.h>
#define N 10
#define N1 32
int a[N];
char no[N1]; 
int main()
{
    int i=0,j=0,k=0,t=0,length;
    long value=1;
    scanf("%d",&t);
    while(t-->0)
    {
        i=j=k=0;
        value=1;        
        scanf("%s",no);            
        length=strlen(no);
        for(i=0;i<10;i++)
        a[i]=0;
        for(i=0;i<length;i++)
        {
           a[no[i]-'0']+=1;                     
        }
        for(i=0;i<10;i++)
        {
            if(a[i]!=0)
            {
               k=pow(2,a[i]-1); 
               value*=k;      
            }
                         
        }printf("%ld\n",value);        
    }getch();
}
