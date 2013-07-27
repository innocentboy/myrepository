#include<stdio.h>
#define N 50
char s[N];
int z[N];
int main(){
int L = 0, R = 0,n,k,i,j,maxz=0,res=0;
scanf("%s",s);
n=strlen(s);
for (i = 1; i < n; i++) {
  if (i > R) {
    L = R = i;
    while (R < n && s[R-L] == s[R]) R++;
    z[i] = R-L; R--;
  } else {
    k = i-L;
    if (z[k] < R-i+1) z[i] = z[k];
    else {
      L = i;
      while (R < n && s[R-L] == s[R]) R++;
      z[i] = R-L; R--;
    }
  }
}
// int maxz = 0, res = 0;
 for (i= 1; i < n; i++) {
  if (z[i] == n-i && maxz >= n-i) { res = n-i; break; }
  maxz =(maxz>z[i])?maxz:z[i];
}
 //printf("%s\n",s);
 for(i=1;i<n;i++)
 printf("%d ",z[i]);
 printf("%s  maxz:%d\n",s,maxz);
 for(i=0;i<maxz;i++)printf("%c",s[i]);
 getch();
 return 0;
}
