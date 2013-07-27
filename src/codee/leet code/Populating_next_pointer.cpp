/**
Follow up for problem "Populating Next Right Pointers in Each Node".

What if the given tree could be any binary tree? Would your previous solution still work?

Note:

    You may only use constant extra space.

For example,
Given the following binary tree,

         1
       /  \
      2    3
     / \    \
    4   5    7

After calling your function, the tree should look like:

         1 -> NULL
       /  \
      2 -> 3 -> NULL
     / \    \
    4-> 5 -> 7 -> NULL



*/
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        TreeLinkNode *prv,*next,*cur,*p;
        if(!root) return;
        root->next=NULL;
        cur=root;
        while(cur)
        {
          next=NULL;
          prv=NULL;
          while(cur)
          {
          if(!next) next=(cur->left)?(cur->left):cur->right;
          if(cur->left)
          {
            if(prv) prv->next=cur->left;
            prv=cur->left;
          }
          if(cur->right)
          {
            if(prv) prv->next=cur->right;
            prv=cur->right;
          }
          cur=cur->next;
          }
          cur=next;
        }

    }
};
