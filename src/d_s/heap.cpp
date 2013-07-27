#include<cstdio>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#define N 1000
#define M 100
using namespace std;
//vector<int> a,heap;
int n,k;

/**
this file maintains all the function related to maintaing the heap..
*/



/**
these two functions maintains the max heap...
*/
void max_heapify(vector<int> &heap,int i)
{
  int l,r,largest,size=heap.size();
  l=2*i+1;r=2*i+2;
  if(l<size||r<size){
  if(l<size&&heap[l]>heap[i])
  largest=l;
  else largest=i;
  if(r<size&&heap[r]>heap[largest])
  largest=r;
  if(largest!=i)
  {
      if(heap[i]!=heap[largest])
      heap[i]^=heap[largest]^=heap[i]^=heap[largest];
      max_heapify(heap,largest);
    }
  }
}

void build_max_heap(vector<int> &heap)
{
   int i,j,k,size=0;
   size=heap.size();
   for(i=(size/2);i>=0;i--)
   {
     max_heapify(heap,i);
   }

}

void increase_maxheap_key(vector<int> &heap)
{
   int i,j,k,p,size;
   size=heap.size();
   i=size-1;
   p=(i-1)/2;
   while(p>=0&&heap[p]<heap[i])
   {
      heap[p]^=heap[i]^=heap[p]^=heap[i];
      i=p;
      p=(i-1)/2;
    }
}

/**
end of the max heap functions..
*/


/**
these functions maintain the min heap..
*/
void min_heapify(vector<int> &heap,int i)
{
  int l,r,largest,size=heap.size();
  if(i<size-1){
  l=2*i+1;r=2*i+2;
  //printf(" %d %d %d",size,l,r);
  if(l<size||r<size){
  if(l<size&&heap[l]<heap[i])
  largest=l;
  else largest=i;
  if(r<size&&heap[r]<heap[largest])
  largest=r;
  if(largest!=i)
  {
     // printf(" max:%d ",heap[0]);
      if(heap[i]!=heap[largest])
      heap[i]^=heap[largest]^=heap[i]^=heap[largest];
      //printf(" min:%d",heap[0]);
      min_heapify(heap,largest);
    }
  }
  }
}

void build_min_heap(vector<int> &heap)
{
   int i,j,k,size=0;
   size=heap.size();
   for(i=(size/2);i>=0;i--)
   {
     min_heapify(heap,i);
   }

}

void decrease_minheap_key(vector<int> &heap)
{
   int i,j,k,p,size;
   size=heap.size();
   i=size-1;
   p=(i-1)/2;
   while(p>=0&&heap[p]>heap[i])
   {
      heap[p]^=heap[i]^=heap[p]^=heap[i];
      i=p;
      p=(i-1)/2;
    }
}

/**
end of the  min heap functions..
*/

/**
this functions calculates the SMALLEST K ELEMENTS FROM THE GIVEN N ELEMENTS.
*/
void find_k_min_element(vector<int> &a,vector<int> &heap)
{
   int i,j,k,l;
     scanf("%d%d",&n,&k);
     for(i=0;i<n;i++){
     scanf("%d",&j);
     a.push_back(j);
     }
     printf("\nprint  the element of the vector\n");
     for(i=0;i<a.size();i++)
     printf("%d ",a[i]);
     for(i=0;i<k;i++)
     heap.push_back(a[i]);
     build_max_heap(heap);
     for(i=k;i<n;i++)
     {
        if(a[i]<heap[0])
        {
          heap[0]=a[i];
          //build_heap();
          max_heapify(heap,0);
        }
        printf("\nprint the heap...\n");
          for(j=0;j<heap.size();j++)
          printf("%d ",heap[j]);
      }
     printf("\nprint the k smallest element...\n");
     for(i=0;i<heap.size();i++)
     printf("%d ",heap[i]);

}


/***

this function finds the median of elements of a stream at any point..
*/
void find_median_stream()
{
  int i,j,k,n;
  vector<int> max_heap,min_heap;
  while(scanf("%d",&n)&&n!=-1)
  {
       if(max_heap.size()){
       if(max_heap[0]<n)
       {
           min_heap.push_back(n);
           decrease_minheap_key(min_heap);
           printf("\nprint the min heap\n");
           for(i=0;i<min_heap.size();i++)
           printf("%d ",min_heap[i]);
        }
        else
        {
           max_heap.push_back(n);
           increase_maxheap_key(max_heap);
            printf("\nprint the max heap\n");
           for(i=0;i<max_heap.size();i++)
           printf("%d ",max_heap[i]);

        }
       if(max_heap.size()-min_heap.size()>=2||max_heap.size()<min_heap.size())
       {
           int max_heap_size=max_heap.size();
           int min_heap_size=min_heap.size();
           if(max_heap_size-min_heap_size>=2)
           {
              int i=max_heap[0];
              max_heap[0]=max_heap[max_heap_size-1];
              max_heap.pop_back();
              max_heapify(max_heap,0);
              min_heap.push_back(i);
              decrease_minheap_key(min_heap);
            }
            else
            {
               int i=min_heap[0];
               min_heap[0]=min_heap[min_heap_size-1];
               min_heap.pop_back();
               min_heapify(min_heap,0);
               max_heap.push_back(i);
               increase_maxheap_key(max_heap);

            }
            printf("\n print the heaps after resize..\n");
             printf("\nprint the min heap\n");
           for(i=0;i<min_heap.size();i++)
           printf("%d ",min_heap[i]);
            printf("\nprint the max heap\n");
           for(i=0;i<max_heap.size();i++)
           printf("%d ",max_heap[i]);

        }
       }
       else
       {
          max_heap.push_back(n);
        }
        printf("\nMedian of the stream is: %d\n",max_heap[0]);
   }

}

/**
start of the main function..
*/
int main()
{
      vector<int> a,heap;
      //printf("\nfind the k min elements\n");
      //find_k_min_element(a,heap);
      printf("\nfind the median of the elemnts from the stream of N elements..\n");
      find_median_stream();
      return 0;
}
