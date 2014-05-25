/*
 * heap.h
 *
 *  Created on: Oct 29, 2013
 *      Author: Sanjay Pandey
 */

#ifndef HEAP_H_
#define HEAP_H_

typedef int compare_fn (const void * , const void *);

typedef struct heap{
	size_t capacity ;
	size_t size ;
	void **array ;
	compare_fn *cmp;

}Heap;

void HeapInit (Heap * , size_t ,compare_fn *);
void HeapInsert (Heap * , void *);
void * HeapDelete (Heap *);
void * HeapTop (Heap *);
#endif /* HEAP_H_ */
