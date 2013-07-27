/**

Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
input output expected
{}	0	0

{0}	1	1

{1,2}	2	2

{1,#,2}	2	2

{1,2,3}	2	2

{1,2,3,4,5}	2	2

{1,2,3,4,#,#,5}	3	3

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
 #include<cstdio>
 #include<algorithm>
 using namespace std;
 int minn=999999;
class Solution {
public:

    int depth(TreeNode *root)
    {
        int l,r,i;
        if(!root) return 9999;
        else if(root&&!root->left&&!root->right) return 1;
        else
        {
            l=depth(root->left);
            r=depth(root->right);
            i=(l<r)?l:r;
            i++;
            return (i);

        }
    }

    int minDepth(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l,r,i;
        if(!root) return 0;
        else if(root&&!root->left&&!root->right) return 1;
        else
        {
            l=depth(root->left);
            r=depth(root->right);
            i=(l<r)?l:r;
            i++;
            return i;

        }
    }
};
