#include<stdio.h> 
#define MAX_LEN  1002
char a[MAX_LEN],b[MAX_LEN];
int H[MAX_LEN][MAX_LEN];
int aLen, bLen;
int min(int a,int b)
{
   return a<b?a:b;    
} 
void readStrings(){
   scanf("%s %s",a,b);
   aLen=strlen(a);
   bLen=strlen(b);
}
void dld() {
   int INF = aLen + bLen,d,j1,i1,c,DB,DA[27],i,j,k;
   H[0][0] =0;
   for (i=1;i<=aLen;++i) {
      H[i][0] = i;
   }
   for (j=1;j<=bLen;++j) {
      H[0][j]=j;
   }
   //C = 'z'+1;
   for (d=0;d<26; ++d)DA[d]=0;
   for (i=1; i<=aLen; ++i) {
      DB = 0;
      for (j = 1; j <= bLen; ++j) {
         i1 = DA[b[j-1]];
         j1 = DB;
         d =((a[i-1]==b[j-1])?0:1);
         if (d==0) DB=j;H[i][j]=INF;
         H[i][j] = min(H[i-1][j-1]+d, H[i][j]);
         H[i][j] = min(H[i][j], H[i-1][j]+1);
         H[i][j] = min(H[i][j], H[i][j-1]+1);
         H[i][j] = min(H[i][j], H[i1][j1] + (i-i1-1) + 1 + (j-j1-1));
      }
      DA[a[i]-'a'] = i;
   }
   printf("%d\n",H[aLen][bLen]);
}
 
int main() {
   for (; ;) {
      readStrings();
      if (a[0]=='*') break;
      dld();
   }
   getch();
   return 0;
}
