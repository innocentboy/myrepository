#include<stdio.h>
#include<conio.h>
swap(void *a,void *b,size_t t)
{
         union a
         {
             int i;
             float f;
            // double d;
             char c;      
         }u;
        // if(t==4)
         {
                 u.i=*((int *)a);
                 *((int *)a)=*((int *)b);
                 *((int *)b)=u.i;
         }    
        /* else if(t==8)
         {
                 
                 u.i=*((float *)a);
                 *((float *)a)=*((float *)b);
                 *((float *)b)=u.i;        
         }      
          else if(t==8)
          {
                  
                 u.i=*((char *)a);
                 *((char *)a)=*((char *)b);
                 *((char *)b)=u.i;        
          } */
          
}
int main()
{
    int a=5,b=6;
    float c=3.4,d=20.5;
    char e='A',f='B';
    swap(&a,&b,sizeof(int));
    printf("%d  %d",a,b);
    printf("\n %d",sizeof(float));
    swap(&c,&d,sizeof(float));
    printf("\n %f %f",c,d);
    swap(&e,&f,sizeof(char));
    printf("\n %c %c",e,f);
    getch();
    
}
