//
//  main.cpp
//  practice
//
//  Created by Sanjay on 4/4/13.
//  Copyright (c) 2013 TCS. All rights reserved.
//
//
//#include <iostream>
//#include <cmath>
//using namespace std;

/**
void parent(int l,int r,char s[],int count)
{
    if(l==0&&r==0)
    {
        
        printf("%s\n",s);
    }
    else
    {
        if(l>0)
        {
            s[count]='(';
            parent(l-1,r, s, count+1);
        }
        if(r>l)
        {
            s[count]=')';
            parent(l,r-1, s, count+1);
        }
    }
}

void demo(int count)
{
    char s[2*count];
    s[2*count]='\0';
    parent(count,count,s,0);
}

*/

/**
int add(int a,int b)
{
  if(b==0)
      return a;
    int c=a^b;
    int t=(a&b)<<1;
    return add(c,t);
}
 */
/**
int greater_element(int a,int b)
{
    int c=a-b;
    int t=(c)>>31;
    if(t&1)
        return a-c;
    else
        return a;
}
*/

//void indiness()
//{
//    short int i=0x0001;
//    char *c=(char *)&i;
//    printf("first:%d  second:%d\n",*c,*(c+1));
//    if(*c&1)
//        printf("little indian\n");
//    else
//        printf("big indian\n");
//}

//int searchElement(int a[],int l,int r,int x)
//{
//    while (l<r) {
//        int m=l+(r-l+1)/2;
//        if(a[m]<=x)
//            l=m;
//        else
//            r=m-1;
//    }
//    if(a[l]==x)
//        return l;
//    else
//        return -1;
//}
/*
int main(int argc, const char * argv[])
{

    //printf("greateer element:%d",5);
//    int a[9]={1,3,4,5,6,6,7,8,11};
//    int f=searchElement(a,0,8,11);
//    if(f==-1)
//    {
//        printf("element not found..\n");
//    }
//    else
//    {
//        printf("elements index is :%d\n",f);
//    }
    
//    int a[9]={1,3,4,5,6,6,7,8,11};
//    for(int i=0;i<9;i++)
//    {
//        int t=(rand()%(9-i));
//        printf("random:%d %d  %d\n",i,t,i+t);
//    }
    
    int row=4,col=5,i,j;
 int header=row*sizeof(int *);

 int **array=(int **)malloc(header);
    //int *buf=(int *)malloc(data);
    for(int k=0;k<row;k++)
        array[k]=(int *)malloc(sizeof(int)*col);
    for(i=0;i<row;i++)
        for(j=0;j<col;j++)
            array[i][j]=j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
            printf("%d ",array[i][j]);
        printf("\n");
    }
    
    return 0;
}
*/


/*
 * LittleXor.cpp
 *
 *  Created on: Dec 6, 2012
 *      Author: indresh
 */


/*
#include <pthread.h>
#include <stdlib.h>
#include<iostream>
#include <cstdio>
#include<vector>
#include<unistd.h>
#define N 20
using namespace std;

int ret1,ret2;
pthread_t tid[4];
int buffer[N],full,empty,bIndex;
pthread_mutex_t mutex_t=PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond_empty=PTHREAD_COND_INITIALIZER;
pthread_cond_t cond_full=PTHREAD_COND_INITIALIZER;

void destruct_key(void *arg)
{
    printf("\nthis cleans the resources of key and value:%d\n",*(int *)arg);
}

void cleanup_after_malloc(void* allocated_memory)
{
    if (allocated_memory)
    {
        printf("\nmemory is freed successfully..\n");
        free(allocated_memory);
    }
}

void* doSomeThing(void *arg)
{
    //unsigned long i = 0;
    pthread_t id = pthread_self();
    
    if(pthread_equal(id,tid[0]))
    {
        pthread_key_t key;
        if(pthread_key_create(&key,&destruct_key)==0)
            printf("\nkey is created for the thread..\n");
        printf("\n First thread processing :\n");
        ret1=100;
        pthread_exit(&ret1);
        
    }
    else if(pthread_equal(id,tid[1]))
    {
        printf("\n Second thread processing\n");
        ret2=200;
        pthread_exit(&ret2);
    }
    else if(pthread_equal(id,tid[2]))
    {
        int old_cancle_type;
        int *ptr=(int *)malloc(sizeof(int));
        *ptr=400;
        //pthread_cleanup_push(cleanup_after_malloc,*ptr);
        pthread_setcanceltype(PTHREAD_CANCEL_DEFERRED, &old_cancle_type);
        printf("\n Third thread processing and it's cancelation type:%d\n",old_cancle_type);
         pthread_setcanceltype(old_cancle_type, NULL);
        pthread_exit(NULL);
    }
    else
    {
        printf("\n fourth thread processing\n");
        pthread_exit(NULL);
    }
    
    //for(i=0; i<(0xFFFFFFFF);i++);
    
    return NULL;
}
*/



//int main()
//{
//	   
//    int i = 0,j=5;//,k=90;
//    int err;
//    int *ptr[2];
//    pthread_attr_t art;
//   
//    pthread_attr_init(&art);
//    pthread_attr_setdetachstate(&art, PTHREAD_CREATE_DETACHED);
//    
//    #if _POSIX_THREADS
//    while(i <4)
//    {
//        err = pthread_create(&(tid[i]),NULL, &doSomeThing,&j);
//        if (err != 0)
//            printf("\ncan't create thread :[%s]", strerror(err));
//        else
//            //printf("\n Thread created successfully\n");
//            ;
//        
//        i++;
//    }
//   // pthread_attr_destroy(&art);
//    pthread_join(tid[0],(void **)&(ptr[0]));
//    pthread_join(tid[1],(void **)&(ptr[1]));
//    pthread_detach(pthread_self());
//    pthread_join(tid[2],NULL);
//    pthread_join(tid[3],NULL);
//    
//    //sleep(5);
//    //printf("\nreturn values: %d  %d\n",*(ptr[0]),*(ptr[1]));
//    #endif
//    return 0;
//}


/*
void* producer_fun(void *arg)
{
    while(1){
        pthread_mutex_lock(&mutex_t);
        if(bIndex>=N){
              printf("\nBuffer is full no items can be produced..\n");
              pthread_cond_wait(&cond_empty, &mutex_t);
        }
        bIndex++;
        buffer[bIndex]=bIndex;
        printf("\nproducer has produced the item no:%d consume that..\n",bIndex);
        pthread_mutex_unlock(&mutex_t);
        pthread_cond_signal(&cond_full);
  }
      return  NULL;
}

void* consumer_fun(void *arg)
{
    while(1){
          pthread_mutex_lock(&mutex_t);
        if(bIndex<0)
        {
            printf("\nNo items are there to be consumed..\n");
            pthread_cond_wait(&cond_full, &mutex_t);
            //full=0,empty=N-1;
        }
        printf("\nconsumer has consumed the produced irtem:%d\n",buffer[bIndex]);
        bIndex--;
        pthread_mutex_unlock(&mutex_t);
        pthread_cond_signal(&cond_empty);
    }
    return NULL;
}

 */
 
//int main()
//{
//    pthread_t producer,consumer;
//    int i;
//    full=0;empty=N-1,bIndex=-1;
//    for(i=0;i<N;i++)
//        buffer[i]=-1;
//    for(i=0;i<2;i++)
//    {
//       if(i==0)
//           pthread_create(&producer,NULL, producer_fun, NULL);
//        else
//            pthread_create(&consumer, NULL, consumer_fun, NULL);
//    }
//    
//    for(i=0;i<2;i++)
//    {
//      if(i==0)
//          pthread_join(producer, NULL);
//        else 
//            pthread_join(consumer, NULL);
//    }
//    printf("\n checking the integrity..\n");
//    return 0;
//}


#include <cstdio>
#include <stdlib.h>

/*
 this is sizeof operator..
 */
#define sizeoff(val) (int)((char *)(&val+1)-(char *)&val)

/**
 This is the memcpy function.
 
 */
void memcopy(void *src,void *des,int size)
{


}

/**
 This is Memset function.
 */
void memsetvalue(void *src,char value,int size)
{
   
    unsigned char *ptr=(unsigned char *)src;
    for(int i=0;i<size;i++)
    {
        ptr[i]=value;
    }

}
void memsett(void *dest, char val, size_t count)
{
    unsigned char *temp = (unsigned char *)dest;
	for( ; count != 0; count--, temp[count] = val);
}

int main()
{

    short int i;
//    struct stud {
//        
//        int i;
//        char k[1];
//        double d;
//        int j;
//        //short int m;
//    }s;
//    char j;
    
//    double k;
//    printf("\n use our implemented sizeof.. int:%d  char:%d double:%d structure:%d  :%u\n",sizeoff(i),sizeoff(j),sizeoff(k),sizeoff(s),sizeoff(a));

    
    int a[]={1,2,3,4,5};

    printf("\nsetting the value by memeset...\n");
    memsett(a,1,sizeoff(a));
    for(i=0;i<sizeoff(a)/sizeoff(a[0]);i++)
        printf("%d ",a[i]);
    
    return 0;
}


//#include  <pthread.h>
//#include   <cstdio>
//#include   <stdlib.h>
//int i;
//
//void* test(void *arg)
//{
//  
//    printf("\nexecuting the test thread..\n");
//    int *ptr=(int *)malloc(sizeof(int));
//    *ptr=100;
//    pthread_exit(ptr);
//
//}
//
//int main()
//{
//  
//    pthread_t tid;
//    int *p=NULL;
//    pthread_create(&tid, NULL, test, NULL);
//    pthread_join(tid,(void **)&p);
//    if(p!=NULL)
//    printf("\nreceived dat=a from test:%d\n",*(p));
//    else
//        printf("\nNo data received..\n");
//    return  0;
//}



































