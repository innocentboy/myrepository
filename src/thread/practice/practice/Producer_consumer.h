////
////  Producer_consumer.h
////  practice
////
////  Created by Sanjay on 5/14/13.
////  Copyright (c) 2013 TCS. All rights reserved.
////
//
//#ifndef __practice__Producer_consumer__
//#define __practice__Producer_consumer__
//
//#include <iostream>
//#include "Producer_consumer.h"
//#include <pthread.h>
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//
//#define QUEUESIZE 10
//#define LOOP 20
//
//void *producer (void *args);
//void *consumer (void *args);
//
//typedef struct {
//	int buf[QUEUESIZE];
//	long head, tail;
//	int full, empty;
//	pthread_mutex_t mut;
//	pthread_cond_t notFull, notEmpty;
//} queue;
//
//queue *queueInit (void);
//void queueDelete (queue *q);
//void queueAdd (queue *q, int in);
//void queueDel (queue *q, int *out);
//
//#endif /* defined(__practice__Producer_consumer__) */
