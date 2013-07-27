/**

Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined
as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.

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
 #include<math.h>
 #include<algorithm>
 using namespace std;

class Solution {
public:

    int isavl(TreeNode *root)
    {
        if(!root) return 0;
        else
        {
            int l,r,d;
            l=isavl(root->left);
            r=isavl(root->right);
            if(l==-1||r==-1) return -1;
             else if(abs(l-r)<2)
            {
                d=(l>r?l:r)+1;
                return d;
            }
            else return -1;
        }
    }

    bool isBalanced(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i;
        if(!root) return true;
        else
        {
            i=isavl(root);
            if(i==-1) return false;
            else return true;
        }

    }
};
