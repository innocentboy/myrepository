#include<stdio.h>
#include<conio.h>
#define N 5
void permutation(char *,int,int);
void swap(char *,int ,int);
int main()
{
   char in[N]="aac";
  // char s[N]="";
  // int i=0;
  // i=strlen(in);
 //  printf("%s\n",in);
  // printf("\n %d",i-1);
   permutation(in,0,strlen(in));
   //printf("\n%s",in);
   getch();
}

void permutation(char *s,int i,int j)
{
  if(i!=j)
  {
     int k=0;
     if(i==j-1)
          printf("%s\n",s);
     for(k=i;k<j;k++)
     {
         if(i!=k&&(s[i]==s[k]))
            continue;
         swap(s,i,k);
         permutation(s,i+1,j);
         swap(s,i,k);
     }

  }
}
void swap(char *s,int i,int k)
{
    char c;
    c=*(s+i);
    *(s+i)=*(s+k);
    *(s+k)=c;
}


