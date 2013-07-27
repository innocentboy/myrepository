//
//  Dinning_philosphoer.cpp
//  practice
//
//  Created by Sanjay on 5/15/13.
//  Copyright (c) 2013 TCS. All rights reserved.
//


/*
#include "Dinning_philosphoer.h"

void take_fork(int i)
{
    pthread_mutex_lock(&mutex);
    state[i]=HUNGRY;
    pthread_mutex_unlock(&mutex);
    test(i);
    if(state[i]!=EATING)
     pthread_mutex_lock(&p_mutex[i]);

}

void put_fork(int i)
{
     pthread_mutex_lock(&mutex);
     state[i]=THINKING;
     pthread_mutex_unlock(&mutex);
    test(LEFT(i));
    test(RIGHT(i));
}

void test(int i)
{
    if(state[i]==HUNGRY&&state[LEFT(i)]!=EATING&&state[RIGHT(i)]!=EATING){
        state[i]=EATING;
        pthread_mutex_unlock(&p_mutex[i]);
    }

}

void eat(int i)
{
    printf("\nPhilosphoor:%d is eating right now.   status:",i);
    for(int j=0;j<N;j++)
        printf("%d ",state[j]);
    printf("\n");
}

void think(int i)
{
    printf("\nPhilosphor:%d is thinking right now.\n",i);
}

void* philosphor(void *arg)
{
    int i=*(int *)arg;
    for(int j=0;j<LOOP;j++) {
          think(i);
          take_fork(i);
          if(state[i]==EATING)
          eat(i);
          put_fork(i);
       
    }
    return NULL;
}

int main()
{
    int i;
    for(i=0;i<N;i++){
        state[i]=THINKING;
        p_mutex[i]=PTHREAD_MUTEX_INITIALIZER;
    }
    for(i=0;i<N;i++)
    {
        int j=i;
        pthread_create(&tid[i], NULL, philosphor,&j);
    }
    for(i=0;i<N;i++)
        pthread_join(tid[i], NULL);
    return 0;

} */