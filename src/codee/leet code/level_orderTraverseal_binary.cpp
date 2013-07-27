/**
Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

*/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
 #include<algorithm>
 #include<queue>
 #include<vector>
 using namespace std;
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        queue<TreeNode *> q1,q2;
        vector< vector<int> > vt;
        int i=0,j,k;
        if(!root) return vt;
        else{
           q1.push(root);
           while(!q1.empty()||!q2.empty())
           {
               vector<int> v;
               if(!q1.empty())
               {
                   while(!q1.empty())
                   {
                       TreeNode *p,*q;
                       p=q1.front();q1.pop();
                       if(p)
                       {
                           v.push_back(p->val);
                       }
                       if(p->left)q2.push(p->left);
                       if(p->right)q2.push(p->right);
                   }
               }
                else
               {
                   while(!q2.empty())
                   {
                       TreeNode *p,*q;
                       p=q2.front();q2.pop();
                       if(p)
                       {
                           v.push_back(p->val);
                       }
                       if(p->left)q1.push(p->left);
                       if(p->right)q1.push(p->right);
                   }
               }
                vt.push_back(v);
               }


           return vt;
        }
    }
};
