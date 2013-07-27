/**
Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST
*/
class Solution {
public:

    int listsize(ListNode *head)
    {
        int n=0;
        while(head)
        {
            n++;
            head=head->next;
        }
        return n;
    }

    TreeNode *helper(ListNode* &head,int start,int end)
    {
        if(start>end) return NULL;
        TreeNode *root,*left,*right;
        int mid=(start+end)>>1;
        left=helper(head,start,mid-1);
        root=new TreeNode(head->val);
        head=head->next;
        right=helper(head,mid+1,end);
        root->left=left;
        root->right=right;
        return root;
    }

    TreeNode *sortedListToBST(ListNode *head) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!head) return NULL;
        else return helper(head,0,listsize(head)-1);

    }
};
