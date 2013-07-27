#include<stdio.h>
#define N 101
char str1[N];
char str2[N];
int  c[N][N];
int d[N][N];
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
   printf("enter the value of strings...\n");
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
   // printf("\nlength of longest common sequence is:%d\n",c[n][m]);
   for(i=0;i<=n;i++)
   {
     for(j=0;j<=m;j++)
     {
       if(i==0||j==0)
       {
         d[i][j]=1;              
       }
       else
       {
         d[i][j]=0;  
         if(str1[i]==str2[j])d[i][j]=d[i-1][j-1];
         else
         {
           if(c[i-1][j]==c[i][j])d[i][j]=d[i-1][j]+d[i][j];
           if(c[i][j-1]==c[i][j])d[i][j]=d[i][j-1]+d[i][j];
           if(c[i][j]==c[i-1][j-1])d[i][j]=d[i][j]-d[i-1][j-1];    
         }    
       }                 
                      
     }                 
                    
   }
    for(i=0;i<=n;i++)
    {
      for(j=0;j<=m;j++)printf("%d ",d[i][j]);printf("\n");                
    }
    printf("no of distinct LCS:%d\n",d[n][m]);          
   getch();
   return 0;    
}



