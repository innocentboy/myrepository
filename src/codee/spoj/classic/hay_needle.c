#include<stdio.h>
#define N 100000
int lp,lt;
void prefix(char *p,int *a)
{
     int l,k=0,i;
     *(a)=k;
     l=strlen(p);
     for(i=1;i<l;i++)
     {
           while(k!=0&&(*(p+i)!=*(p+k))) 
               k=*(a+k);
            if(*(p+i)==*(p+k))
              k=k+1;
            *(a+i)=k;                  
     }     
}
void matcher(char *t,char *p)
{
    int q=0,l=0,i,m=0;
    int a[N];
    prefix(p,a);    
    for(i=0;i<lt;i++)
    {
        
        while(q!=0&&(*(t+i)!=*(p+q))) 
        {               
                 q=*(a+q);
               
        }
        if(*(t+i)==*(p+q))
        {
                        
                          q+=1;
        }
                         
        if(q==strlen(p))
        {
                   printf("%d\n",(i-q)+1);
                   q=*(a+q-1);               
        }
                      
    } 
}
int main()
{
      int i,j,k,tt;
      char p[N],t[N];
      while(scanf("%d",&lp)&&lp!=-1)
      {
         scanf("%s%s",p,t);                              
         lt=strlen(t);
         if(lp>lt)printf("\n");
         else matcher(t,p);printf("\n");                           
      }    
      getch();
      return 0;    
}
