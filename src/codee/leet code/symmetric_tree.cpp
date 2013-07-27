/***
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).

For example, this binary tree is symmetric:

    1
   / \
  2   2
 / \ / \
3  4 4  3

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
using namespace std;
class Solution{
public:

    static bool same(TreeNode *p,TreeNode *q)
    {
        if(!p&&!q) return true;
        else if(p&&q) return (p->val==q->val)&&same(p->left,q->right)&&same(p->right,q->left);
        else return false;
    }

    bool isSymmetric(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return true;
        else if(!root->left&&!root->right) return true;
        else if(root->left&&root->right) return Solution::same(root->left,root->right);
        else return false;
    }
};
