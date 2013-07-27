/**

You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        ListNode *p=l1,*q;
        int carry=0;
        while(l1!=NULL&&l2!=NULL)
        {

            int sum=(l1->val)+(l2->val)+carry;
            if(sum>9)
            {
              int val=sum%10;
              carry=sum/10;
              sum=val;
            }
            else
            carry=0;
            q=l1;
            l1->val=sum;
            l1=l1->next;
            l2=l2->next;

        }
        while(l1!=NULL)
        {

            int sum=(l1->val)+carry;
            if(sum>9)
            {
                int val=sum%10;
                carry=sum/10;
                sum=val;

            }
            else
               carry =0;
               l1->val=sum;
               q=l1;
               l1=l1->next;
        }
        while(l2!=NULL)
        {
            int sum=(l2->val)+carry;
             if(sum>9)
            {
                int val=sum%10;
                carry=sum/10;
                sum=val;

            }
            else
               carry =0;
               l1=q;
               l1->next=(ListNode *)malloc(sizeof(ListNode));
               q=l1->next;
               q->val=sum;
               l2=l2->next;
        }
        if(carry>0)
        {
            l1=q;
            l1->next=(ListNode *)malloc(sizeof(ListNode));
            l1->next->val=carry;
            l1->next->next=NULL;
        }
        else{
            l1=q;
            l1->next=NULL;

        }
        return p;

    }


};
