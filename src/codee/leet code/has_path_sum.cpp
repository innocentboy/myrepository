/**
Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example:
Given the below binary tree and sum = 22,
              5
             / \
            4   8
           /   / \
          11  13  4
         /  \      \
        7    2      1

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
class Solution {
public:

    bool summ(TreeNode *root,int sum)
   {
       if(!root)
        {
            if(sum==0) return true;
            else return false;
        }
        else return(summ(root->left,sum-root->val)||summ(root->right,sum-root->val));

   }

    bool hasPathSum(TreeNode *root, int sum) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return false;
        else if(root->val==sum) false;
        else if(root&&sum==0) return false;
        else return summ(root->left,sum-root->val)||summ(root->right,sum-root->val);

    }
};
