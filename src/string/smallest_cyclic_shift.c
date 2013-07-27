#include<stdio.h>
#define N 30000
char s[N];
void min_cyclic_shift(char *s) {
	 int i,j,k,ans,n;
	 n=strlen(s);j=0;
	 for(i=n;i<n+n;i++)
	{ 
	   *(s+i)=*(s+j);
	   j++;
   }
	   *(s+i)='\0';i=0;
	 while (i <(n+n)/2) {
		 ans = i;
		 int j = i + 1, k = i;
		 while (j<(n+n)&&s[k]<=s[j]) {
			 if (s [k] <s [j])
				 k = i;
			 else
				 ++k;
			 ++j;
		 }
		 while (i <= k) i+=j-k;
	 }
	 printf("%d\n",ans+1);
} 
 int main()
 {
     int i,j,k,t,m,n;
     scanf("%d",&t);
     while(t--)
     {
       scanf("%s",s);
       min_cyclic_shift(s);
     }
     getch();
     return 0;   
 }
