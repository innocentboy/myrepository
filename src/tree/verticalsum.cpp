/*
* VerticleSumInBinaryTree.cpp
* run command
* g++ /Algorithm/src/InterviewPreparation/binary_tree/VerticleSumInBinaryTree.cpp -o /usr/build/Main.o
*
* Created on: Nov 7, 2013
* Author: Indresh Gahoi
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>


#define trv(V,it) for(typeof((V).begin()) it = (V).begin() ; it != (V).end();++it)
#define contains(v,k) ((v).find(k)!=(v).end())
using namespace std;

struct TreeNode {
int val ;
struct TreeNode *left ;
struct TreeNode *right ;
TreeNode(int x):val(x),left(NULL),right(NULL)
{

}
};

/* Question :-
* Link :- http://www.geeksforgeeks.org/vertical-sum-in-a-given-binary-tree/
*
Vertical Sum in a given Binary Tree
February 29, 2012

Given a Binary Tree, find vertical sum of the nodes that are in same vertical line. Print all sums through different vertical lines.

Examples:

1
/ \
2 3
/ \ / \
4 5 6 7

The tree has 5 vertical lines

Vertical-Line-1 has only one node 4 => vertical sum is 4
Vertical-Line-2: has only one node 2=> vertical sum is 2
Vertical-Line-3: has three nodes: 1,5,6 => vertical sum is 1+5+6 = 12
Vertical-Line-4: has only one node 3 => vertical sum is 3
Vertical-Line-5: has only one node 7 => vertical sum is 7

So expected output is 4, 2, 12, 3 and 7
*
*/

#define MAXWIDTH 10

void VerticleSumUtil(TreeNode *root ,vector<vector<int> > &map,int vlineno)
{
if(root==NULL)
{
return ;
}
VerticleSumUtil(root->left,map,vlineno-1);

if(vlineno >=0 )
{
map[0][vlineno]+=root->val;
}
else
{
map[1][MAXWIDTH+vlineno]+=root->val;
}
VerticleSumUtil(root->right,map,vlineno+1);
}

void VerticleSumUtilV2(TreeNode *root ,vector<vector<int> > &map,int vlineno)
{
if(root==NULL)
{
return ;
}


if(vlineno >=0 )
{
if(map[0].size()<=vlineno)
{
map[0].push_back(0);
}
cout<<"map 0 size "<<map[0].size()<<" vlineno="<<vlineno<<"root val= "<<root->val<<"\n";
map[0][vlineno]+=root->val;
}
else
{

if(map[1].size()<(-vlineno))
{
map[1].push_back(0);
}
cout<<"map 1 size "<<map[1].size()<<" vlineno="<<vlineno<<"root->val= "<<root->val<<"\n";
map[1][-vlineno-1]+=root->val;
}
VerticleSumUtilV2(root->left,map,vlineno-1);
VerticleSumUtilV2(root->right,map,vlineno+1);
}

/*
* Verticle Sum By Dll
*
*
*/
struct DLLNode
{
int val ;
struct DLLNode *left;
struct DLLNode *right ;
DLLNode(int val):val(val),left(NULL),right(NULL)
{

}


};

ostream& operator<<(ostream &out,DLLNode *ptr)
{
DLLNode *dlliter = ptr ;
while(dlliter!=NULL)
{
out<<" ["<<dlliter->val<<"]";
dlliter=dlliter->right ;
}
out<<"\n";
return out ;
}
void VerticleSumUtilV3(TreeNode *root ,DLLNode *preSumNode)
{
if(root==NULL)
{
return ;
}
preSumNode->val+=root->val ;

if(root->left)
{
if(!preSumNode->left)
{

preSumNode->left = new DLLNode(0);
preSumNode->left->right = preSumNode;
}
VerticleSumUtilV3(root->left,preSumNode->left);
}
if(root->right)
{
if(!preSumNode->right)
{
preSumNode->right = new DLLNode(0);
preSumNode->right->left = preSumNode;
}
VerticleSumUtilV3(root->right,preSumNode->right);
}



}
struct node
{
TreeNode *tptr ;
int level ;
};

void VerticleSumUsingLevelOrderTraversal(TreeNode *root)
{
if(root==NULL)
{
return ;
}


queue<node> Q ;
map<int,int> info ;
int lineNo = 0 ;
Q.push({root,0});
while(!Q.empty())
{
node t= Q.front();
Q.pop();
if(!contains(info,t.level))
{
info[t.level] = t.tptr->val ;
}
else
{
info[t.level]+=t.tptr->val;
}
if(t.tptr->left)
{
Q.push({t.tptr->left,t.level-1});
}
if(t.tptr->right)
{
Q.push({t.tptr->right,t.level+1});
}

}

map<int,int>::iterator it;
trv(info,it)
{
cout<<"["<<it->first<<","<<it->second<<"]";
}
cout<<"\n";
}


void verticleSum(TreeNode *root)
{

// vector<vector<int> > map(2,vector<int> (MAXWIDTH,0));
// VerticleSumUtil(root,map,0);
vector<vector<int> > map(2,vector<int> ());
VerticleSumUtilV2(root,map,0);


for(vector<int>::reverse_iterator it = map[1].rbegin() ;
it != map[1].rend() ; ++it)
{
cout<<" "<<*it;
}
for(vector<int>::iterator it = map[0].begin() ;
it != map[0].end() ; ++it)
{
cout<<" "<<*it;
}
cout<<"\n";
}

void vericleSumDllTest(TreeNode *root)
{
DLLNode *sumList = new DLLNode(0);
VerticleSumUtilV3(root,sumList);
while(sumList->left!=NULL)
{
sumList=sumList->left ;
}
cout<<sumList ;
}

void verticleSumLeveOrderTraversalTest(TreeNode* root){
VerticleSumUsingLevelOrderTraversal(root);
}
int main() {
/* Create following Binary Tree
1
/ \
2 3
/ \ / \
4 5 6 7
/ \ / \
3 89 10
*/
TreeNode root = *new TreeNode(1);
root.left=(new TreeNode(2));
root.right=(new TreeNode(3));
root.left->left=(new TreeNode(4));
root.left->right=(new TreeNode(5));
root.right->left=(new TreeNode(6));
root.right->right=(new TreeNode(7));
root.left->left->left=(new TreeNode(3));
root.left->left->right=(new TreeNode(8));
root.right->left->left=(new TreeNode(9));
root.right->left->right=(new TreeNode(10));

//verticleSum(&root);
//vericleSumDllTest(&root);
verticleSumLeveOrderTraversalTest(&root);

}
