////
////  Dinning_philosphoer.h
////  practice
////
////  Created by Sanjay on 5/15/13.
////  Copyright (c) 2013 TCS. All rights reserved.
////
//
//#ifndef __practice__Dinning_philosphoer__
//#define __practice__Dinning_philosphoer__
//
//#include <iostream>
//#include <pthread.h>
//
//#define N               5
//#define LOOP            10
//#define LEFT(i)         (i+N-1)%N
//#define RIGHT(i)        (i+1)%N
//#define THINKING        0
//#define HUNGRY          1
//#define EATING          2
//
//int state[N];
//pthread_t tid[N];
//pthread_mutex_t p_mutex[N];
//pthread_mutex_t mutex=PTHREAD_MUTEX_INITIALIZER;
//pthread_cond_t cond=PTHREAD_COND_INITIALIZER;
//
//void take_fork(int);
//void put_fork(int);
//void test(int);
//void eat(int);
//void think(int);
//void* philosphor(void *);
//
//#endif /* defined(__practice__Dinning_philosphoer__) */
