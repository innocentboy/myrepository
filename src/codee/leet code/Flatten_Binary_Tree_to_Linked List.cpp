/**
Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6

The flattened tree should look like:

   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6

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
void flatten(TreeNode *root) {
    if (!root) return;

    TreeNode* left = root->left;
    TreeNode* right = root->right;

    if (left) {
        root->right = left;
        root->left = NULL;

        TreeNode* rightmost = left;
        while(rightmost->right) {rightmost = rightmost->right;}
        rightmost->right = right; // point the right most to the original right child
    }

    flatten(root->right);
}
};



