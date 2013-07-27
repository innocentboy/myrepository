/**
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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

    vector<TreeNode *> helper(int start,int end)
    {
        if(start>end)
        {
          TreeNode *t=NULL;
          vector<TreeNode *> vt(1,t);
          return vt;
        }
        else
        {
            vector<TreeNode *> res,left,right;
           for(int i=start;i<=end;i++)
           {
              left=helper(start,i-1);
              right=helper(i+1,end);
              for(int j=0;j<left.size();j++)
              {
                   for(int k=0;k<right.size();k++)
                   {
                      TreeNode *p=new TreeNode(i);
                      p->left=left[j];
                      p->right=right[k];
                      res.push_back(p);
                    }
                }
            }
            return res;
        }

    }

    vector<TreeNode *> generateTrees(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<TreeNode *> ans;
        ans=helper(1,n);
        return ans;
    }
};

