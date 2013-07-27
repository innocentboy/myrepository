////
////  Reader_writer.h
////  practice
////
////  Created by Sanjay on 5/14/13.
////  Copyright (c) 2013 TCS. All rights reserved.
////
//
//#ifndef __practice__Reader_writer__
//#define __practice__Reader_writer__
//
//#include <iostream>
//#include <iostream>
//#include <pthread.h>
//#include <stdio.h>
//#include <unistd.h>
//#include <stdlib.h>
//
//#define QUEUESIZE1 1
//#define LOOP1 10
//
//void *writer(void *args);
//void *reader(void *args);
//
//typedef struct {
//	int buf[QUEUESIZE1];
//	long head, tail;
//	int full, empty;
//	pthread_mutex_t mut_r,mut_w;
//	pthread_cond_t cond_r, cond_w;
//} queue1;
//
//queue1 *queueInit (void);
//void queueDelete (queue1 *q);
////void queueAdd (queue *q, int in);
////void queueDel (queue *q, int *out);
//
//#endif /* defined(__practice__Reader_writer__) */
