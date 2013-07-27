#include<stdio.h>
#include<conio.h>
#define N  100
int main()
{
	char s[N],t[N],f='0';
	int i,j=0,k,c=0,n;
	printf("enter the value of no of character do you want convert\n");
	scanf("%d",&n);
	printf("\n enter the value of 1-based no system");
	for(i=0;i<n;i++)
	scanf("%c",&s[i]);
	for(i=0;i<n;i++)
	{
		if(s[i]==' ')
		{
			if(c==1)
			f='1';

			else if(c==2)
			f='0';
			else
			{
				for(k=0;k<c-2;k++)
				{
					if(f=='0')
					t[j]='0';
					else
				       {
					t[j]='1';
				       }
					 j++;
					 printf("\n %s \n",t);
				}

			}
			c=0;
		    //	printf("\n %s \n",t);

		}

		c++;

	}
	t[j]='\0';
	printf("\n print the value of string : %s",t);
	getch();

}
