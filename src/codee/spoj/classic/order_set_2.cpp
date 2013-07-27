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
		//printf("error finding %d\n",key);while (1);
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
	else if(k>((root->left==nilpoint)?0:root->left->size)+1)
	return query(root->right,k-(((root->left==nilpoint)?0:root->left->size)+1));
	else return query(root->left,k-1);
}

inline int query_min(Treap &root,int key)
{
    if (root==nilpoint) return 0;
	if(root->key==key) return (root->left==nilpoint)?0:(root->left->size);
	if (key<root->key) return query_min(root->left,key);
    else if(key>root->key)
    return (root->left==nilpoint)?(1+query_min(root->right,key)):(root->left->size+query_min(root->right,key)+1);

}


#define N 100005
unsigned int a[N],s[N],l[N];
//set< unsigned int> sm,lr;
map< unsigned int,unsigned int> mp;

int main()
{
    nilpoint=new node;
	nilpoint->left=nilpoint->right=nilpoint;
	nilpoint->size=nilpoint->cnt=0;
	nilpoint->aux=inf;
	memStack.clear();
    Treap tre=nilpoint;

  int q,x;
  char c[2];
  scanf("%d",&q);
  while(q--)
  {
	  scanf("%s%d",c,&x);
	  //fflush(stdin);
	  switch(c[0])
	  {

	  case 'I':
		      insert(tre,x);
		  	  break;
	  case 'D':
		  	  erase(tre,x);
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
  return 0;
}



/**

#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>
#include<time.h>
#include<assert.h>

#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define FOR(i,n) for(int i=0;i<(n);++i)
#define REP(i,a,b) for(int i=(a);i<=(b);++i)
#define CLR(a,x) memset(a,(x),sizeof(a))

#define INF (1<<30)

typedef long long LL;
typedef pair<int,int> pii;

struct Node {
    int key;
    int cnt;
    int priority;

    Node *left, *right;

    Node(){cnt = 0; priority = 0; left = right = NULL;}
    Node(int _key){cnt = 1; key = _key; priority = rand(); left = right = NULL;}
    Node(int _key, int pr){cnt = 1; key = _key; priority = pr; left = right = NULL;}
};

struct Treap {
    Node* root;

    Treap(){root = NULL; srand(time(NULL));}

    int TreeSize(Node* T)
    {
        return T==NULL?0:T->cnt;
    }

    void UpdateCnt(Node* &T)
    {
        if(T)
        {
            T->cnt = 1 + TreeSize(T->left) + TreeSize(T->right);
        }
    }

    void LeftRotate(Node* &T)
    {
        Node* temp = T->left;
        T->left = temp->right;
        temp->right = T;
        T = temp;

        UpdateCnt(T->right);
        UpdateCnt(T);
    }

    void RightRotate(Node* &T)
    {
        Node* temp = T->right;
        T->right = temp->left;
        temp->left = T;
        T = temp;

        UpdateCnt(T->left);
        UpdateCnt(T);
    }

    void Insert(Node* &T, int _key)
    {
        if(T == NULL)
        {
            T = new Node(_key);
            return;
        }

        if(T->key > _key)
        {
            Insert(T->left, _key);

            if(T->priority < T->left->priority)
                LeftRotate(T);
        }
        else if(T->key < _key)
        {
            Insert(T->right, _key);

            if(T->priority < T->right->priority)
                RightRotate(T);
        }

        UpdateCnt(T);
    }

    void Insert(int _key)
    {
        Insert(root, _key);
    }

    void Delete(Node* &T, int _key)
    {
        if(T == NULL)
            return;

        if(T->key > _key)
            Delete(T->left, _key);
        else if(T->key < _key)
            Delete(T->right, _key);
        else
        {
            if(T->left && T->right)
            {
                if(T->left->priority > T->right->priority)
                    LeftRotate(T);
                else
                    RightRotate(T);

                Delete(T, _key);
            }
            else
            {
                Node* temp = T;

                if(T->left)
                    T = T->left;
                else
                    T = T->right;

                delete temp;
            }
        }


        UpdateCnt(T);
    }

    void Delete(int _key)
    {
        Delete(root, _key);
    }

    int Count(Node* T, int bound)
    {
        if(T == NULL)
            return 0;

        if(T->key < bound)
            return 1 + TreeSize(T->left) + Count(T->right, bound);

        return Count(T->left, bound);
    }

    int Count(int bound)
    {
        return Count(root,bound);
    }

    int FindKth(Node* T, int k)
    {
        if(TreeSize(T) < k)
            return -INF;

        int sz = 1 + TreeSize(T->left);

        if(sz == k)
            return T->key;

        if(sz < k)
            return FindKth(T->right, k-sz);

        return FindKth(T->left,k);
    }

    int FindKth(int k)
    {
        return FindKth(root, k);
    }
};

int main()
{
    // freopen("in.txt","r",stdin);

    int Q; scanf("%d",&Q);

    Treap oTreap;

    while(Q--)
    {
        char t[5];
        int p;
        scanf("%s%d",t,&p);

        if(t[0]=='I')
        {
            oTreap.Insert(p);
        }
        else if(t[0]=='D')
        {
            oTreap.Delete(p);
        }
        else if(t[0]=='K')
        {
            int v = oTreap.FindKth(p);

            if(v > -INF)
            {
                printf("%d\n",v);
            }
            else
                puts("invalid");
        }
        else
        {
            int v = oTreap.Count(p);

            printf("%d\n",v);
        }

    }

    return 0;
}

*/



