/**
LINK FOR IMPLEMENTATION OF THE BIPRATITE GRAPH:http://www.geeksforgeeks.org/maximum-bipartite-matching/
*/

/**
REGULAR GRAPH:   A REGULAR GRAPH IS A GRAPH HAVING THE SAME NO. OF NEIGHBOUR , IT MEANS EVERY VERTEX
                 HAS SAME NO OF DEGREE.A regular directed graph must also satisfy the stronger condition
                 that the indegree and outdegree of each vertex are equal to each other.

MAXIMAL MATCHING NO. IN GRAPH: IT'S THE MAXIMUM NO. OF EDGES OF GRAPH SUCH THAT no TWO OF THEM
                                INCIDENT ON THE SAME VERTEX.
                                A matching in a graph is a set of edges no two of which share an
                                endpoint,and a matching is maximum if no other matching has more edges.

MINIMUM VERTEX NO:  IT'S MINIMUM NO. OF SET OF VETREX OF GRAPH WHICH COVERS THE ENTIRE EDGES OF
                    THE GRAPH.A vertex cover in a graph is a set of vertices that includes at least one endpoint of
                    each edge, and a vertex cover is minimum if no other vertex cover has fewer
                    vertices.

BIPARTITE : IT'S A KIND IF GRAPH IN WHICH EACH EDGE IS HAVING ONE VERTEX IN ONE INDEPENDENT SET
            AND OTHER VERTEX IN OTHER INDEPENDENT SET OF VERTEX.no EDGES OF GRAPH HAVING THE
            BOTH END OF VERTEX IN THE SAME SET.
            A graph is bipartite if its vertices can be partitioned into two sets such that each
            edge has one endpoint in each set
*/
/**
NOTE: A BIPARTITE GRAPH IS TWO COLORABLE, IF IT'S HAVING NO CYCLE, OR CYCLE WITH EVEN LENGTH.

NOTE:every regular bipartite graph has a perfect matching,[1] and more generally that the chromatic index of any
        bipartite graph (that is, the minimum number of matchings into which it can be partitioned) equals its
        maximum degree[2] – the latter statement is known as König's Line Coloring Theorem.

NOTE: A theorem by Nash-Williams says that every k‑regular graph on 2k + 1 vertices has a Hamiltonian
        cycle.

NOTE:König's theorem states that, in any bipartite graph, the number of edges in a maximum matching
        is equal to the number of vertices in a minimum vertex cover.

IN BIPARTITE GRAPH NO OF MAXIMAL MATCHING AND MINIMUM VECTREX INDEX NUMBER IS SAME.

NOTE: FOR OTHER GRAPH IT'S DIFFERENT, IN WHICH NO. OF MAXIMAL MATCHING( EDGE MATCHING.) OF
        GRAPH AND THE MINIMUM VERTEX NO. OF GRAPH IS DIFFERENT.
        MAXIMAL MATCHING OF GRAPH CAN BE CMPUTED IN PLYNOMIAL TIME BUT IT'S NOT POSSIBLE
        FOR MINIMUM VERTEX NO., BECAUSE IT'S A NP-COMPLETE PROBLEM.
*/
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <cstring>
using namespace  std;
#define N 100
#define M 100
#define INF 1000000000
#define ull long long


/**
In bpm(), we one by one try all jobs that an applicant ‘u’ is interested in until we find a job,
 or all jobs are tried without luck. For every job we try, we do following.
If a job is not assigned to anybody, we simply assign it to the applicant and return true.
If a job is assigned to somebody else say x, then we recursively check whether x can be assigned
 some other job. To make sure that x doesn’t get the same job again, we mark the job ‘v’ as seen
 before we make recursive call for x. If x can get other job, we change the applicant for job ‘v’
 and return true. We use an array maxR[0..N-1] that stores the applicants assigned to different jobs.
*/

// A DFS based recursive function that returns true if a
// matching for vertex u is possible
bool bpm(bool bpGraph[M][N], int u, bool seen[], int matchR[])
{
    // Try every job one by one
    for (int v = 0; v < N; v++)
    {
        // If applicant u is interested in job v and v is
        // not visited
        if (bpGraph[u][v] && !seen[v])
        {
            seen[v] = true; // Mark v as visited

            // If job 'v' is not assigned to an applicant OR
            // previously assigned applicant for job v (which is matchR[v])
            // has an alternate job available.
            // Since v is marked as visited in the above line, matchR[v]
            // in the following recursive call will not get job 'v' again
            if (matchR[v] < 0 || bpm(bpGraph, matchR[v], seen, matchR))
            {
                matchR[v] = u;
                return true;
            }
        }
    }
    return false;
}

// Returns maximum number of matching from M to N
int maxBPM(bool bpGraph[M][N])
{
    // An array to keep track of the applicants assigned to
    // jobs. The value of matchR[i] is the applicant number
    // assigned to job i, the value -1 indicates nobody is
    // assigned.
    int matchR[N];

    // Initially all jobs are available
    memset(matchR, -1, sizeof(matchR));

    int result = 0; // Count of jobs assigned to applicants
    for (int u = 0; u < M; u++)
    {
        // Mark all jobs as not seen for next applicant.
        bool seen[N];
        memset(seen, 0, sizeof(seen));

        // Find if the applicant 'u' can get a job
        if (bpm(bpGraph, u, seen, matchR))
            result++;
    }
    return result;
}

int main()
{

    // Let us create a bpGraph shown in the above example
    bool bpGraph[M][N] = {  {0, 1, 1, 0, 0, 0},
                        {1, 0, 0, 1, 0, 0},
                        {0, 0, 1, 0, 0, 0},
                        {0, 0, 1, 1, 0, 0},
                        {0, 0, 0, 0, 0, 0},
                        {0, 0, 0, 0, 0, 1}
                      };

    cout << "Maximum number of applicants that can get job is "
         << maxBPM(bpGraph);

    return 0;
}


/**
ALGORITHM: FOR FINDING THE VERTEX COVER OR MAXIMAL MATHING IN BIPATTITE GRAPH.
*/
/**
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <map>
#include <vector>
using namespace std;

const int maxn = 1000;

vector<int> adj[maxn];
int mark[maxn], stamp, match[maxn];

// Hungray, find augment path
inline bool augment(int x)
{
    for (int i = 0; i < adj[x].size(); ++ i) {
        int y = adj[x][i];
        if (mark[y] == stamp) {
            continue;
        }
        mark[y] = stamp;
        if (match[y] == -1 || augment(match[y])) {
            match[y] = x;
            return true;
        }
    }
    return false;
}

int main()
{
    int T;
    for (scanf("%d", &T); T --;) {
        int n;
        scanf("%d", &n);
        assert(1 <= n <= maxn);
        map<int, int> hashX, hashY;
        for (int i = 0; i < n; ++ i) {
            int x, y;
            scanf("%d%d", &x, &y);
            if (!hashX.count(x)) {
                int newid = hashX.size();
                adj[newid].clear();
                hashX[x] = newid;
            }
            x = hashX[x];
            if (!hashY.count(y)) {
                int newid = hashY.size();
                hashY[y] = newid;
            }
            y = hashY[y];
            adj[x].push_back(y);
        }
        memset(mark, -1, sizeof(mark));
        memset(match, -1, sizeof(match));
        stamp = 0;
        int maxMatch = 0;
        for (int i = 0; i < hashX.size(); ++ i) {
            ++ stamp;
            if (augment(i)) {
                ++ maxMatch;
            }
        }
        printf("%d\n", maxMatch);
    }
    return 0;
}

*/
