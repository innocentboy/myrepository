/*
 * oredrset.cpp
 *
 *  Created on: Feb 18, 2013
 *      Author: pandit
 */

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

const int inf	=	1000000000;

struct node
{
	node *left,*right;
	int aux,key,size,cnt;
};
typedef node* Treap;

inline void renew(Treap &root)
{
	root->size=root->cnt+root->left->size+root->right->size;
}

inline void leftRotate(Treap &root)
{
	Treap t=root->left;
	root->left=t->right;
	t->right=root;
	renew(root);
	renew(t);
	root=t;
}

inline void rightRotate(Treap &root)
{
	Treap t=root->right;
	root->right=t->left;
	t->left=root;
	renew(root);
	renew(t);
	root=t;
}
//====================================

const int maxn	=	500005;

Treap nilpoint;
node mem[maxn*2];
vector<Treap> memStack;
int nodeCnt;

inline Treap newNode()
{
	Treap ret;
	if (memStack.size()){
		ret=memStack.back();
		memStack.pop_back();
	}else{
		assert(nodeCnt<maxn*2);
		ret=&mem[nodeCnt++];
	}
	return ret;
}

inline void insert(Treap &root,int key)
{
	if (root==nilpoint){
		root=newNode();
		root->left=root->right=nilpoint;
		root->key=key;
		root->cnt=root->size=1;
		root->aux=rand()%inf;
		return;
	}
	if (key==root->key){
	    return;
		++root->cnt;
	}else if (key<root->key){
		insert(root->left,key);
		if (root->left->aux<root->aux){
			leftRotate(root);
		}
	}else if (key>root->key){
		insert(root->right,key);
		if (root->right->aux<root->aux){
			rightRotate(root);
		}
	}else{
		assert(false);
	}
	renew(root);
}

inline void erase(Treap &root,int key)
{
	if (root==nilpoint){
		//printf("error finding %d\n",key);//while (1);
		return;
	}
	if (root->key==key){
		if (root->cnt>1){
			--root->cnt;
		}else{
			if (root->left==nilpoint && root->right==nilpoint){
				memStack.push_back(root);
				root=nilpoint;
				return;
			}
			if (root->left->aux<root->right->aux){
				leftRotate(root);
				erase(root->right,key);
			}else{
				rightRotate(root);
				erase(root->left,key);
			}
		}
	}else if (key<root->key){
		erase(root->left,key);
	}else if (key>root->key){
		erase(root->right,key);
	}else{
		assert(false);
	}
	renew(root);
}

inline int query(Treap &root,int k)
{
	if (root==nilpoint) return 0;
	if (k==((root->left==nilpoint)?0:root->left->size)+1) return root->key;
	else if(k>((root->left==nilpoint)?0:root->left->size)+1) return query(root->right,k-(((root->left==nilpoint)?0:root->left->size)+1));
	else return query(root->left,k);
}

inline int query_min(Treap &root,int key)
{
    if (root==nilpoint) return 0;
	if(root->key==key) return (root->left==nilpoint)?0:(root->left->size);
	if (key<root->key) return query_min(root->left,key);
    else if(key>root->key)
    return (root->left==nilpoint)?(1+query_min(root->right,key)):(root->left->size+query_min(root->right,key)+1);

}

map<int,int> mp;

int main()
{
    nilpoint=new node;
	nilpoint->left=nilpoint->right=nilpoint;
	nilpoint->size=nilpoint->cnt=0;
	nilpoint->aux=inf;
	memStack.clear();
    Treap tre=nilpoint;

  int q,x;
  char c;
  // for(int i=0;i<1000000007;i++)
 // mp[i]=-1;

  scanf("%d",&q);

  while(q--)
  {
	  scanf("%c%d",&c,&x);
	  fflush(stdin);
	  switch(c)
	  {

	  case 'I':
              // if(mp[x]==-1)
		       insert(tre,x);
		  	  break;
	  case 'D':
               // if(mp[x]!=-1){
		  	    erase(tre,x);
		  	   // mp[x]=-1;
               // }
		  	  break;
	  case 'K':
		  	  if(tre->size<x)
		  		printf("invalid\n");
		  	 else
		  		printf("%d\n",query(tre,x));
		  	  break;
	  case	'C':
		     printf("%d\n",query_min(tre,x));
		     break;
	  }

  }
  //scanf("%d",&q);
  return 0;
}





