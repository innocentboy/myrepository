#include<stdio.h>
#include<conio.h>
void swap(void *,void *,size_t);
int main()
{
      
      int a=5,b=10;
      char c=65,d=66;
      float e=15.5,f=20.8;
      float x=3.5;
      swap(&a,&b,sizeof(int));
      printf("*****value of integer*****");
      printf("\nvalue of a:%d",a);
      printf("\n value of b:%d",b);
      printf("\n***value of char****");
      swap(&c,&d,sizeof(char));
      printf("\nvalue of c:%c",c);
      printf("\n value of d:%c",d);
      
      printf("\n***value of float ****");
      swap(&e,&f,sizeof(float));
      printf("\nvalue of e:%f",e);
      printf("\n value of f:%f",f);
      printf("\n ......this is if.......");
      if(f>=20.8)
         printf("\nprinting right value");
      else 
         printf("\n printing wrong value");   
      getch(); 
}
void swap(void *a,void *b,size_t t)
{
     char *bb,*aa;
     int *aaa,*bbb;
     float *aaaa,*bbbb;
     float ccc;
     char c;
     int cc;
     switch(t)
     {
       case 1: aa=(char *)a;
               bb=(char *)b;
               c=*aa;
               *aa=*bb;
               *bb=c;
               break;
       case 4: aaa=(int *)a;
               bbb=(int *)b;
               cc=*aaa;
               *aaa=*bbb;
               *bbb=cc;
               break; 
       case 8: aaaa=(float *)a;
               bbbb=(float *)b;
               cc=*aaaa;
               *aaaa=*bbbb;
               *bbbb=ccc;
               break;                    
              
     }
     
}
