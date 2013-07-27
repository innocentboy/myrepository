using namespace std;
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int size=num.size();
        return toBST(num,0,size-1);
    }

    TreeNode *toBST(vector<int> &num,int l,int r)
    {
        if(l<=r){
        int mid;
        mid=(l+r)>>1;
        TreeNode *p=new TreeNode(num[mid]);
        p->left=toBST(num,l,mid-1);
        p->right=toBST(num,mid+1,r);
        return p;
        }
        else
        return NULL;

    }
};
