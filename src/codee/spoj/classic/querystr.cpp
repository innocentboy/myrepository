    #include<stdio.h>
    #include<string.h>
    #define N 1000005
    char str[N];
    int z[N];
    int main()
    {
    int i,j,k,n,t,len,l,r,n1;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%s",str);
    len=strlen(str);
    z[0]=len;l=0;r=0,i=0;
    while(i<len/2)
    {
    j=str[i];
    str[i]=str[len-i-1];
    str[len-i-1]=j;i++;
    }//printf("\n%s",str);
	
	/*
	Z-algo..
	*/
    for(i=1;i<len;i++)
    { z[i]=0;
    if(i<=r)z[i]=(z[i-l]>r-i+1)?r-i+1:z[i-l];
    while(z[i]+i<len&&str[z[i]]==str[i+z[i]])++z[i];//printf("%d ",z[i]);
    if(z[i]+i-1>r)
    {
    l=i;r=z[i]+i-1;
    }
    }
    scanf("%d",&n);
    while(n--)
    {
    scanf("%d",&n1);
    printf("%d\n",z[len-n1]);
    }
    }
    //getch();
    return 0;
    }
