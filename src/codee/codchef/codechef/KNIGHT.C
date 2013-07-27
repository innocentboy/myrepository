#include<stdio.h>
#include<conio.h>
int main()
{
	int n,m,i,j,k=0,t;
	printf("enter the value of row and coloum..\n");
	scanf("%d %d",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{

			if(((j+2)<=m&&(i+1)<=n))
			k++;
			if((j+2)<=m&&(i-1)>=1)
			k++;
			if((j-2)>=1&&(i+1)<=n)
			k++;
			if((j-2)>=1&&(i-1)>=1)
			k++;
			if((i+2)<=n&&(j+1)<=m)
			k++;
			if((i+2)<=n&&(j-1)>=1)
			k++;
			if((i-2)>=1&&(j+1)<=m)
			k++;
			if((i-2)>=1&&(j-1)>=1)
			k++;
		   }


		}

		printf("no of combination is: %d",((n*m)*(n*m-1))-k);
		getch();

}
