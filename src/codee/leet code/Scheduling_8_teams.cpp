/**
There are 8 soccer teams. Each team needs to play against every other team exactly once. Each team can play no more
than once each day. Write a program that prints out the shortest possible schedule.

*/

/**
SOLUTION:

        The idea is we can divide all team to two parts as team group A and team group B, and then fight between each team
        from A with each team from B. After we go through all the fights between A and B, we recursively divide A and B
        separately and find fights between each team. In this division, we just cut the problem to two subproblems. NOTE: it
        is under the assumption that we have even number teams, Odd number teams should be modified,
        maybe we could include a dump team so that we have even number teams
*/

#include <iostream>
using namespace std;

void fight(int A[], int low, int high, int day) {

if (high == low+1) {
    cout<<"day #"<<day<<": "<<A[low]<<" vs "<<A[high]<<endl;
    return;
}

int mid = (low+high)/2;
for(int i=0; i<=mid-low; i++) {
    for(int j=0; j<=mid-low; j++) {
        int k = mid+j+i+1;
        if (k>high)
            k = mid+(k-high);
        cout<<"day #"<<day<<": "<<A[low+j]<<" vs "<<A[k]<<endl;
    }
    day++;
}
fight(A, low, mid, day);
fight(A, mid+1, high, day);

return;
}

int main() {
// Start typing your code here...
int *A = new int[9];
for(int i=0; i<9; i++) {
    A[i] = i;
}
   fight(A, 1, 8, 1);
   delete A;
return 0;
}
