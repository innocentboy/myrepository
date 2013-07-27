#include<stdio.h>
#define N 101
char str1[N];
char str2[N];
int  c[N][N];
char path[N][N];
int max(int i,int j)
{
  return (i>j?i:j);    
}
void print_path(int i,int j)
{
   if(i==0||j==0)return;
   else if(path[i][j]=='d')
   {
        print_path(i-1,j-1);
        printf("%c ",str1[i]);
   }
   else if(path[i][j]=='D')print_path(i,j-1);
   else print_path(i-1,j);      
}
int main()
{
   int i,j,k,n,m,t;
   scanf("enter the value of strings...\n");
   scanf("%s%s",str1+1,str2+1); 
   n=strlen(str1+1);m=strlen(str2+1);
   for(i=1;i<=n;i++)
   {
     for(j=1;j<=m;j++)
     {
        if(str1[i]==str2[j])
        {
              c[i][j]=c[i-1][j-1]+1;
              path[i][j]='d';
        }
        else
        {
             if(c[i-1][j]>c[i][j-1])
             {
                c[i][j]=c[i-1][j];
                path[i][j]='R';                      
             }
             else 
            {
                  
                c[i][j]=c[i][j-1];
                path[i][j]='D';  
            }
             
        }                
     }
   }
    printf("\nlength of longest common sequence is:%d\n",c[n][m]);
    print_path(n,m);
    /*for(i=1;i<=n;i++)
    {
      for(j=1;j<=m;j++)
      {
        if(path[i][j]=='d'&&path[j][i]!='1')
        {
          path[i][j]='1';
          printf("%c ",str1[i]); 
        }                
      }                 
    }*/               
   getch();
   return 0;    
}


