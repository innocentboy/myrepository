/**
This files contains the concepts related to thread.
*/

#include<stdio.h>
#include<conio.h>
#include<pthread.h>

pthread_t tid[2];

void test(void *arg)
{
   printf("\nthis is thread..\n");
   if(equal_thread(get_thread(),tid[0]))
     printf("\nthis is first\n");
     else
     printf("\nthis is second..\n");
}

int main()
{
      int i=0;
      while(i<2)
      {
        int err=create_thread(&tid[0],NULL,&test,NULL);
        if(err==0)
          printf("\nthread is created..\n");
          else
            printf("\nnot created..\n");
      }
      return 0;
}
