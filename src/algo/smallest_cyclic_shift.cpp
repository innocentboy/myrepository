#include<stdio.h>
#define N 50
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
	 printf("%d %d %d",i,j,k+1);
} 
 int main()
 {
     int i,j,k,t,m,n;
     scanf("%s",s);
     min_cyclic_shift(s);
    /* while (i <n) {
	    j = i + 1; k = i;
	    while (j <n &&s[k]<=s[j]) {
		 if (s[k]<s[j])
			 k = i;
		 else
			 ++k;
		 + + j;
	 }
	    while (i <= k) {
		 //cout << s. substr (i, j - k) << '';
		 i + = j - k;
	   }
    }*/ 
    printf("\n%d  %d  %d",i,j,k);
     getch();
     return 0;   
 }
