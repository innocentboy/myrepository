/**
PROBLEM STATMENT:
As a good example would serve the following problem:

Given an undirected graph G having positive weights and N vertices.

You start with having a sum of M money. For passing through a vertex i,
you must pay S[i] money. If you don't have enough money - you can't pass through that
vertex. Find the shortest path from vertex 1 to vertex N, respecting the above conditions;
or state that such path doesn't exist. If there exist more than one path having the same length,
then output the cheapest one. Restrictions: 1<N<=100 ; 0<=M<=100 ; for each i, 0<=S[i]<=100.
*/

/**
SOLUTION:
Set states(i,j) as unvisited for all (i,j)
Set Min[i][j] to Infinity for all (i,j)

Min[0][M]=0

While(TRUE)

Among all unvisited states(i,j) find the one for which Min[i][j]
is the smallest. Let this state found be (k,l).

If there wasn't found any state (k,l) for which Min[k][l] is
less than Infinity - exit While loop.

Mark state(k,l) as visited

For All Neighbors p of Vertex k.
   If (l-S[p]>=0 AND
    Min[p][l-S[p]]>Min[k][l]+Dist[k][p])
      Then Min[p][l-S[p]]=Min[k][l]+Dist[k][p]
   i.e.
If for state(i,j) there are enough money left for
going to vertex p (l-S[p] represents the money that
will remain after passing to vertex p), and the
shortest path found for state(p,l-S[p]) is bigger
than [the shortest path found for
state(k,l)] + [distance from vertex k to vertex p)],
then set the shortest path for state(i,j) to be equal
to this sum.
End For

End While

Find the smallest number among Min[N-1][j] (for all j, 0<=j<=M);
if there are more than one such states, then take the one with greater
j. If there are no states(N-1,j) with value less than Infinity - then
such a path doesn't exist.
*/

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
#include <cmath>
#define N 52
#define M 101

using namespace std;

int main()
{
    printf("\ndijkastra is running..\n");
    return 0;
}
