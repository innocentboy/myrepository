/**
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

*/

#include<vector>
using namespace std;
class Solution {
public:
    vector<int> grayCode(int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j;
        vector<int> v;
        if(n==0)
        {
            v.push_back(0);
        }
        else
        {
            j=1<<n;
            for(i=0;i<j;i++)
            {
                v.push_back(i^(i>>1));
            }
        }
        return v;

    }
};
