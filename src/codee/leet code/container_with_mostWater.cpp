/**
Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai). n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis forms a container, such that the container contains the most water.

Note: You may not slant the container


*/


/**
METHOD 1:N^2
*/
#include<algorithm>
using namespace std;
class Solution {
public:
    int maxArea(vector<int> &height) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i,j,n=height.size(),maxx=-1;
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
               maxx=max(maxx,min(height[i],height[j])*(j-i));
            }

        }
        return maxx;

    }
};



/**
METHOD 2: N LOG(N)
*/

bool mycmp(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
}
class Solution {
public:
    int maxArea(vector<int> &height) {
        if(height.size() < 2) return 0;

        int maxarea = 0;
        vector<pair<int, int> > hs;
        for(int i = 0; i < height.size(); i++) {
            hs.push_back(pair<int, int>(height[i], i));
        }
        sort(hs.begin(), hs.end(), mycmp);
        int minl = 0, minu = height.size()-1;
        for(int i = 0; i < height.size(); i++) {
            maxarea = max(maxarea, hs[i].first*(hs[i].second-minl));
            maxarea = max(maxarea, hs[i].first*(minu-hs[i].second));
            if(i+1 < height.size()) {
                while(hs[i+1].first > height[minl])
                    minl ++;
                while(hs[i+1].first > height[minu])
                    minu --;
            }
        }
        return maxarea;
    }
};
