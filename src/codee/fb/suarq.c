#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,count=0,t,root;
    long long in;
    double x;
    scanf("%d",&t);
    printf("\n");
    while(t-->0){
   // printf("\n");
    scanf("%lld",&in);
    //printf("%d",(int)sqrt(in));
    for(i=0;i<=(int)sqrt((double)in);i++)
    {
         root=(i*i);
         if(root<(in-root))
         {   x=sqrt(in-root);
             if(x==(int)x)
             {
               /* if((i*i)==(in/2.0))
                count+=2;
                else
                count+=1; */count=1;
                 break;
             }
         }
    }
    if(count==1)
    printf("\nYES");
    else
    printf("\nNO");
    count=0;
  }
    getch();
}
