//
//  Producer_consumer.cpp
//  practice
//
//  Created by Sanjay on 5/14/13.
//  Copyright (c) 2013 TCS. All rights reserved.
//


/*
#include "Producer_consumer.h"
pthread_t prod[3],consum[3];


int main()
{

    queue *q=queueInit();
    for(int i=0;i<3;i++){
    pthread_create(&prod[i], NULL,producer, q);
    pthread_create(&consum[i], NULL,consumer,q);
    }
    for(int i=0;i<3;i++){
    pthread_join(prod[i], NULL);
    pthread_join(consum[i], NULL);
    }
    queueDelete(q);
    return  0;
    
}

void *producer(void *args)
{
    queue *q=(queue *)args;
    int i,producr;
    for(i=0;i<3;i++)
    {
       if(pthread_equal(prod[i], pthread_self()))
       {
           producr=i+1;
           break;
       }
    }
    for(i=0;i<LOOP;i++)
    {
        pthread_mutex_lock(&q->mut);
      if(q->full)
      {
          pthread_cond_wait(&q->notEmpty, &q->mut);
          
      }
        queueAdd(q, i);
        printf("\nProducer:%d has produced item no:%d and tail:%ld\n",producr,i,q->tail);
        pthread_mutex_unlock(&q->mut);
        pthread_cond_signal(&q->notFull);
        
    }
    return NULL;
}

void *consumer (void *args)
{
    queue *q=(queue *)args;
    int i,j,consume;
    for(i=0;i<3;i++)
    {
        if(pthread_equal(consum[i], pthread_self()))
        {
            consume=i+1;
            break;
        }
    }
    for(i=0;i<LOOP;i++)
    {
        pthread_mutex_lock(&q->mut);
        if(q->empty)
        {
            pthread_cond_wait(&q->notFull, &q->mut);
            
        }
        queueDel(q, &j);
        printf("\nConsumer:%d has consumed item no:%d and head is:%ld\n",consume,j,q->head);
        pthread_mutex_unlock(&q->mut);
        pthread_cond_signal(&q->notEmpty);
        
    }
    return  NULL;
}

queue *queueInit (void)
{
    queue *q=(queue *)malloc(sizeof(queue));
    q->head=0;
    q->tail=0;
    q->empty=1;
    q->full=0;
    for(int i=0;i<QUEUESIZE;i++)
        q->buf[i]=-1;
    q->mut=PTHREAD_MUTEX_INITIALIZER;
    q->notEmpty=PTHREAD_COND_INITIALIZER;
    q->notFull=PTHREAD_COND_INITIALIZER;
    return q;
    

}
void queueDelete (queue *q)
{
    free(q);
}
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
}

*/