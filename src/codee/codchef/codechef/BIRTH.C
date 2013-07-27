#include<stdio.h>
#include<conio.h>
int a[10],b[10];
int main()
{
//	int b[10];
	int i=1,j=0,k=0,flag=0,no=0,t=0;
	scanf("%d",&t);
while(t-->0)
{
    i=0;j=0;k=0;flag=0;no=0;         
    for(j=0;j<10;j++)
    scanf("%d",&a[j]);        
    while(1)
	{
	    for(k=0;k<10;k++)
	    b[k]=a[k];
	    j=i;
	    do
	    {
		 k=j%10;
		 j=j/10;
		if(b[k]==0)
		{    no=i;
		     flag=1;
		     break;
        }
		else
			b[k]=b[k]-1;
	    } while(j);
		if(flag)
		{
			printf("%d\n",no);
			break;
		}

	     i++;
   }
}   
   getch();
   return 0;
}
