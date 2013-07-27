/**
 * Definition for binary tree with next pointer.
 * struct TreeLinkNode {
 *  int val;
 *  TreeLinkNode *left, *right, *next;
 *  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
 * };
 */
class Solution {
public:
    void connect(TreeLinkNode *root) {
        // Start typing your C/C++ solution below
        // DO NOT write int main()
        create_linkBetween_sibling(root);

    }

    void create_linkBetween_sibling(TreeLinkNode *root)
{
   if(root!=NULL)
   {
     // root->left->sibling=root->right;
      if(root->left!=NULL)
      {
          if(root->right!=NULL)
          root->left->next=root->right;
          else if(root->next!=NULL&&root->next->left!=NULL)
          root->left->next=root->next->left;
          else if(root->next!=NULL)
          root->left->next=root->next->right;
          else
          root->left->next=NULL;
      }
      if(root->right!=NULL)
      {
         if(root->next!=NULL&&(root->next)->left!=NULL)
          root->right->next=root->next->left;
          else if(root->next!=NULL)
          root->right->next=root->next->right;
          else
          root->right->next=NULL;
      }
      create_linkBetween_sibling(root->left);
      create_linkBetween_sibling(root->right);
   }

}
};
