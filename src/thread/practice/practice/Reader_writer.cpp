//
//  Reader_writer.cpp
//  practice
//
//  Created by Sanjay on 5/14/13.
//  Copyright (c) 2013 TCS. All rights reserved.
//

/*

#include "Reader_writer.h"
pthread_t wrtr[3],readr[3];
int readers;

int main()
{
    //pthread_t wrter;
    readers=0;
    queue1 *q=queueInit();
    for(int i=0;i<3;i++){
       
        //if(i==0)
        pthread_create(&wrtr[i], NULL,writer, q);
        pthread_create(&readr[i], NULL,reader,q);
    }
    for(int i=0;i<3;i++){
        //if(i==0)
        pthread_join(wrtr[i], NULL);
        pthread_join(readr[i], NULL);
    }
    queueDelete(q);
    return  0;
    
}


void *writer(void *args)
{
    queue1 *q=(queue1 *)args;
    int i,producr;
    for(i=0;i<3;i++)
    {
        if(pthread_equal(wrtr[i], pthread_self()))
        {
            producr=i+1;
            break;
        }
    }
    for(i=0;i<LOOP1;i++)
    {
        pthread_mutex_lock(&q->mut_w);
        printf("\nwriter:%d is writing  something in the file..\n",producr);
       
        
        pthread_mutex_unlock(&q->mut_w);
        
    }
    return NULL;
}

void *reader(void *args)
{
    queue1 *q=(queue1 *)args;
    int i,consume;
    for(i=0;i<3;i++)
    {
        if(pthread_equal(readr[i], pthread_self()))
        {
            consume=i+1;
            break;
        }
    }
    
    for(i=0;i<LOOP1;i++)
    {
        pthread_mutex_lock(&q->mut_r);
        readers++;
        if(readers==1) pthread_mutex_lock(&q->mut_w);
        pthread_mutex_unlock(&q->mut_r);
        
        printf("\nReader:%d is reading the file read value:%d\n",consume,readers);
       
        
        pthread_mutex_lock(&q->mut_r);
        printf("\nReader:%d is leaving the file and read value:%d\n",consume,readers);
        readers--;
        if(readers==0)
            pthread_mutex_unlock(&q->mut_w);
        pthread_mutex_unlock(&q->mut_r);
        
    }
    return  NULL;
}

queue1 *queueInit (void)
{
    queue1 *q=(queue1 *)malloc(sizeof(queue1));
    q->head=0;
    q->tail=0;
    q->empty=1;
    q->full=0;
    for(int i=0;i<QUEUESIZE1;i++)
        q->buf[i]=-1;
    q->mut_r=PTHREAD_MUTEX_INITIALIZER;
    q->mut_w=PTHREAD_MUTEX_INITIALIZER;
    q->cond_r=PTHREAD_COND_INITIALIZER;
    q->cond_w=PTHREAD_COND_INITIALIZER;
    return q;
    
    
}
void queueDelete (queue1 *q)
{
    free(q);
}

*/

/*
void queueAdd (queue *q, int in)
{
    q->buf[q->tail++]=in;
    if(q->tail==QUEUESIZE)
    {
        q->tail=0;
    }
    if(q->tail==q->head)
        q->full=1;
    q->empty=0;
    
}
void queueDel (queue *q, int *out)
{
    *out=q->buf[q->head++];
    if(q->head==QUEUESIZE)
        q->head=0;
    if(q->tail==q->head)
        q->empty=1;
    q->full=0;
}*/