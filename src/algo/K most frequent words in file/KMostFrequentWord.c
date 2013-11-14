/*
 * kMostFrequentWord.c
 *
 *  Created on: Oct 29, 2013
 *      Author: Indresh Gahoi
 */
#include<stdio.h>
#include<limits.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>

/* Question :-
 * Given a book of words. Assume you have enough main memory to accommodate all words. design a data structure
 * to find top K maximum occurring words. The data structure should be dynamic so that new words can be
 * added .
 *
 */

/*
 * Following are the advantages of Trie over hash table. From Wiki page of Trie.

Tries support ordered iteration, whereas iteration over a hash table will result in a pseudorandom order
 given by the hash function (and further affected by the order of hash collisions, which is determined by the
 implementation).

Tries facilitate longest-prefix matching, but hashing does not, as a consequence of the above.
 Performing such a "closest fit" find can, depending on implementation, be as quick as an exact find.

Tries tend to be faster on average at insertion than hash tables because hash tables must rebuild their index when it becomes full - a very expensive operation. Tries therefore have much better bounded worst-case time costs, which is important for latency-sensitive programs.
Since no hash function is used, tries are generally faster than hash tables for small keys
 */

#define MAX_NO_CHAR 256

typedef struct trie_node{
    int isEnd ;
    unsigned frequency ;
    int indexMinHeap;
	struct trie_node* child[MAX_NO_CHAR] ;
}trie_node;


typedef struct heap_node{
    unsigned frequency ;
    trie_node *root ;
	char *word;
}heap_node;


/*
 *  Heap code
*/
typedef int compare (const heap_node * , const heap_node *);

typedef struct heap{
	size_t capacity ;
	size_t size ;
	heap_node **array ;
	compare *cmp;

}Heap;
static void HeapIFY (Heap *heap ,size_t index);

void HeapInit(Heap *heap , size_t capacity ,compare *cmp){

	heap->capacity = capacity ;
	heap->cmp = cmp ;
	heap->array = malloc(sizeof(heap_node *) * capacity) ;
	heap->size = 0 ;
}



static void HeapIFY(Heap *heap , size_t index){
	size_t left , right , up;
	heap_node *temp ;
	left = (index << 1 )+ 1 ;
	right = (index << 1 )+ 2 ;
	up = index ;

	if(left < heap->size && heap->cmp(heap->array[left],heap->array[up])){
		up = left ;
	}
	if(right < heap->size && heap->cmp(heap->array[right],heap->array[up])){
		up = right ;
	}

	if(up != index){

	  heap->array[up]->root->indexMinHeap = index ;
	  heap->array[index]->root->indexMinHeap = up ;
	  // swap the array data
	   temp = heap->array[up];
       heap->array[up] = heap->array[index];
       heap->array[index] = temp ;
       HeapIFY(heap,up);
	}
}

void HeapInsert(Heap *heap , heap_node *dataPtr){

	size_t now;
	heap->array[heap->size] = dataPtr ;
	now = heap->size ;
	heap->size++;
	while(now > 0 && heap->cmp(dataPtr,heap->array[now>>1])){

		heap->array[now] = heap->array[now>>1] ;
		heap->array[now]->root->indexMinHeap = now ;
		now >>= 1;
	}
	heap->array[now] = dataPtr ;
	heap->array[now]->root->indexMinHeap = now ;
}

void * HeapDelete( Heap *heap ){

	heap_node *lastDataPtr , *topDataPtr ;

	if(heap->size == 0){
		printf("Heap is Empty");
		exit(0) ;
	}

	topDataPtr = heap->array[0];

	lastDataPtr = heap->array[heap->size-1];
	heap->size--;
	heap->array[0] = lastDataPtr ;
	heap->array[0]->root->indexMinHeap = 0 ;
	HeapIFY(heap , 0);
	topDataPtr->root->indexMinHeap = -1 ;
   return topDataPtr ;
}

void DisplayHeap(Heap *heap){
	size_t iter ;
	heap_node *curr ;
	for( iter = 0 ; iter < heap->size ; ++iter){
		curr = heap->array[iter];
		printf("%d :- fre=%u %s \n",iter,curr->frequency,curr->word);
	}

}

/*
 *  Trie Code
 */
trie_node* CreateTrieNode(){
	trie_node *node;
	int iter ;
	node = (trie_node *) malloc(sizeof(*node));
	node->isEnd = 0;
	node ->frequency = 0 ;
	node ->indexMinHeap = -1;
	for(iter = 0 ; iter < MAX_NO_CHAR ; ++iter){
      node->child[iter] = (trie_node *)NULL ;
	}
	return node ;
}

/*
 *  we need to implement bound heap
 */
void ModifiedInserMinHeap(Heap *minHeap ,trie_node *root, const char *word){

	/* Case 1 : word is Already in heap
	 * Case 2 : word is not in heap and heap is not full
	 * Case 3 : word is not in heap and heap is full
	 *
	 */
	 //case 1
	 heap_node *hnode;
     if(root->indexMinHeap!= -1){
    	 minHeap->array[root->indexMinHeap]->frequency = root->frequency ;
    	 HeapIFY(minHeap , root -> indexMinHeap) ;
     }
     else if(minHeap->size < minHeap->capacity) // case 2
     {
    	 hnode = (heap_node *) malloc(sizeof(*hnode));
    	 hnode->word = (char *) malloc(sizeof(char)*(strlen(word)+1));
         strcpy(hnode->word,word);
         hnode->frequency = 1;
         hnode->root = root ;
         HeapInsert(minHeap,hnode);
     }
     else if((minHeap->array[0]->frequency) < (root->frequency))  //case 3
     {
    	 minHeap->array[0]->root->indexMinHeap = -1;
    	 minHeap->array[0]->root = root ;
    	 minHeap->array[0]->frequency = root->frequency ;
    	 minHeap->array[0]->root->indexMinHeap = 0;
    	 free(minHeap->array[0]->word);
    	 minHeap->array[0]->word =(char *) malloc(sizeof(char)*(strlen(word)+1));
         strcpy(minHeap->array[0]->word,word);
         HeapIFY(minHeap , 0) ;

     }
}

void addWordInTrie(trie_node **root ,Heap *minHeap , const char *word ,const char *dupword){

	if((*root)==NULL){
		*root = CreateTrieNode();
	}

	if((*word)!='\0'){
         addWordInTrie( &(*root)->child[tolower(*word)-97] , minHeap , word+1,dupword );
	}
	else
	{
		if((*root)->isEnd)
		{
			(*root)->frequency++;
		}
		else
		{
			(*root)->isEnd = 1 ;
			(*root) -> frequency = 1 ;
		}
		ModifiedInserMinHeap(minHeap,*root,dupword);
	}
}

int compare_heap_node(const heap_node *a ,const heap_node *b){
	return a->frequency < b->frequency ;
}

void solve(FILE *fp , int n){
   Heap minHeap ;
   trie_node *root = NULL ;
   char buffer[1000] ;
   HeapInit(&minHeap , n , compare_heap_node) ;
   while(fscanf(fp ,"%s",buffer)!=EOF){
         addWordInTrie(&root ,&minHeap,buffer,buffer);
         DisplayHeap(&minHeap);
         printf("\n\n") ;
   }

}


int main(){
 int c = 5 ;
 FILE *fp;

 fp = fopen("input.txt","r");
 if(fp==NULL){
	 perror("file does not exist \n");
 }
  solve(fp,c);
 return 0;
}
