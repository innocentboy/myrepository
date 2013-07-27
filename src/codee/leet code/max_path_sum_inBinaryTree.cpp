/**
Given a binary tree, find the maximum path sum.

The path may start and end at any node in the tree.

For example:
Given the below binary tree,

       1
      / \
     2   3
Return 6.

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

 METHOD 1:
 */

 #include<algorithm>
 using namespace std;
 int maxsum=-9999999;
class Solution {
public:

    int maxPathSumm(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l,r,i,j;
        if(!root) return -999999;
        else
        {
            l=maxPathSumm(root->left);
            r=maxPathSumm(root->right);
            if(l!=-999999&&r!=-999999)i=l+r+root->val;
            else if(l==-999999&&r!=-999999) i=root->val+r;
            else if(r==-999999&&l!=-999999) i=root->val+l;
            else i=root->val;
            maxsum=max(maxsum,max(root->val,max(max(l,r),i)));
            maxsum=max(maxsum,max(l+root->val,r+root->val));
            j=max(max(l+root->val,root->val),r+root->val);
            return j;
        }

    }
    int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int l,r,i,j;
        if(!root) return 0;
        else
        {
            maxsum=root->val;
            l=maxPathSumm(root->left);
            r=maxPathSumm(root->right);
            if(l!=-999999&&r!=-999999)i=l+r+root->val;
            else if(l==-999999&&r!=-999999) i=root->val+r;
            else if(r==-999999&&l!=-999999) i=root->val+l;
            else i=root->val;
            maxsum=max(maxsum,max(max(l,r),i));
            maxsum=max(maxsum,max(l+root->val,r+root->val));
            return maxsum;
        }

    }
};


/**

METHOD 2:

*/
class Solution {
public:

    void helper(TreeNode *&root,int &cursum,int &maxsum)
    {
      if(!root)
      {
        cursum=0;
        return ;
      }
      int left=0,right=0;
      helper(root->left,left,maxsum);
      helper(root->right,right,maxsum);
      cursum=max(root->val,max(root->val+left,root->val+right));
      maxsum=max(max(cursum,left+right+root->val),maxsum);
    }

   int maxPathSum(TreeNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int maxsum=-999999999,cursum=-99999999;
        helper(root,cursum,maxsum);
        return maxsum;
   }
};
