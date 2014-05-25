/*
 * heap.c
 *
 *  Created on: Oct 29, 2013
 *      Author: Sanjay Pandey
 */

#include<stdio.h>
#include "heap.h"

static void HeapIFY (Heap *heap ,size_t index);


void HeapInit(Heap *heap , size_t capacity ,compare *cmp){

	heap->capacity = capacity ;
	heap->cmp = cmp ;
	heap->array = malloc(sizeof(void *) * capacity) ;
	heap->size = 0 ;
}



static void HeapIFY(Heap *heap , size_t index){
	size_t left , right , up;
	left = index << 1 + 1 ;
	right = index << 1 + 2 ;
	up = index ;

	if(left < heap->size && heap->cmp(heap->array[left],heap->array[up])){
		up = left ;
	}
	if(right < heap->size && heap->cmp(heap->array[right],heap->array[up])){
		up = right ;
	}

	if(up != index){
	// swap the array data
       void *temp = heap->array[up];
       heap->array[up] = heap->array[index];
       heap->array[index] = temp ;
       HeapIFY(heap,up);
	}
}

void HeapInsert(Heap *heap , void *dataPtr){

	size_t now;
	heap->array[heap->size] = dataPtr ;
	now = heap->size ;
	heap->size++;
	while(now > 0 && heap->cmp(dataPtr,heap->array[now>>1])){

		heap->array[now] = heap->array[now>>1] ;
		now >>= 1;
	}
	heap[now] = dataPtr ;
}

void * HeapDelete( Heap *heap ){

	void *lastDataPtr , *topDataPtr ;

	if(heap->size == 0){
		printf("Heap is Empty");
		exit(0) ;
	}

	topDataPtr = heap->array[0];
	lastDataPtr = heap->array[heap->size-1];
	heap->size--;
	heap[0] = lastDataPtr ;
	HeapIFY(heap , 0);
   return topDataPtr ;
}
