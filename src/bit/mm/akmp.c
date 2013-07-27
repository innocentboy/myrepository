#include<stdio.h>
#include<conio.h>
#define N1 16
#define N2 9
void matcher(char *t,char *p,int *);
void prefix(char *p,int *);
int main()
{
    char t[N1]=" ",p[N2]=" ";
    char *x,*y;
    int a[N2],i=0,j=0;
    x=t;
    y=p;
    printf("enter the value of string..\n");
    scanf("%s",t);
    fflush(stdin);
 //  gets(t);
    printf("\n enter the value of string to be matched..\n");
    scanf("%s",p);
    fflush(stdin);
 //  gets(p);
    printf("\n%s : %s",t,p);
    matcher(x,y,a);        
    getch();
}
void matcher(char *t,char *p,int *a)
{
    int q=0,l=0,i,m=0;
    l=strlen(t);
    prefix(p,a);    
    for(i=0;i<strlen(p);i++)
    {
       printf("%d:::",*(a+i));                        
    } 
    for(i=0;i<strlen(t);i++)
    {
        
        while(q!=0&&(*(t+i)!=*(p+q))) 
        {               
                 q=*(a+q);
               
                 }
        if(*(t+i)==*(p+q))
           {
                        
                          q+=1;
                          printf("\n%d:::",q);
                          }
                         
        if(q==strlen(p))
        {
                   printf("\nthere is a matching position at position :::%d",(i-q)+1);
                   q=*(a+q-1);               
        }
                      
    } 
   
} 
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
