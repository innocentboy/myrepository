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
#include<map>
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
		printf("error finding %d\n",key);while (1);
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

inline int query(Treap &root,int key)
{
	if (root==nilpoint) return 0;
	if (key>=root->key) return query(root->right,key);
	int f=0;
	return root->right->size+1+query(root->left,key);
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
  int i,j,k,n;
  nilpoint=new node;
	nilpoint->left=nilpoint->right=nilpoint;
	nilpoint->size=nilpoint->cnt=0;
	nilpoint->aux=inf;
	memStack.clear();
    Treap tre=nilpoint;

  scanf("%d",&n);
  for(i=0;i<n;i++)
  scanf("%d",&a[i]);
  insert(tre,a[n-1]);
  l[n-1]=0;
  for(i=n-2;i>=0;i--)
  {
    j=query(tre,a[i]);
    l[i]=j;
    insert(tre,a[i]);
  }

    nilpoint=new node;
	nilpoint->left=nilpoint->right=nilpoint;
	nilpoint->size=nilpoint->cnt=0;
	nilpoint->aux=inf;
	memStack.clear();
	tre=nilpoint;

  insert(tre,a[0]);

  s[0]=0;
  for(i=1;i<n;i++)
  {

      j=query_min(tre,a[i]);
      s[i]=j;
       insert(tre,a[i]);

    }

    for(i=0;i<n;i++)
    mp[a[i]]=-1;

    long long ans=0;

    for(i=n-2;i>0;i--)
    {

      if(mp[a[i]]==-1)
      {
        mp[a[i]]=l[i];
        ans+=((long long)l[i])*s[i];
      }
      else
      {
         ans+=((long long)(l[i]-mp[a[i]]))*s[i];
       }
    }
    printf("%lld\n",ans);

  return 0;
}





