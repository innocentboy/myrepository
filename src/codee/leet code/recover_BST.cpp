/**

Two elements of a binary search tree (BST) are swapped by mistake.

Recover the tree without changing its structure.

Note:
A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?

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

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
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

    void helper(TreeNode *root,TreeNode* &prv,TreeNode* &cur,TreeNode* &p)
    {
        if(!root) return;
        helper(root->left,prv,cur,p);
        if(p&&p->val>root->val&&!prv){
            prv=p;
            cur=root;
        }
        else if(p&&p->val>root->val&&prv)
            cur=root;
        p=root;
        helper(root->right,prv,cur,p);
    }

    void recoverTree(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!root) return ;
        TreeNode *prv=NULL,*cur=NULL,*p=NULL;
        helper(root,prv,cur,p);
        int t=prv->val;
        prv->val=cur->val;
        cur->val=t;
    }
};
