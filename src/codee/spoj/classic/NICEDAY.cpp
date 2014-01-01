/**
http://www.spoj.com/problems/NICEDAY/
*/
/**
INPUT:
1
3
1 2 3
2 3 1
3 1 2

OUTPUT:
3
*/
#include <cstdio>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN = 100000;

struct Tuple {
    int x, y, z;
} P[MAXN];

struct Pair {
    int x, y;
    bool operator<(const Pair &t) const {
        return x < t.x;
    }
} p;

bool cmp3d(const Tuple &a,const Tuple &b) {
    return a.z < b.z;
}

set<Pair> S;

bool check(set<Pair>::iterator it,Pair &p) {
	printf("\ninsdide the check..\n");
    set<Pair>::iterator it2 = it;
    it2--;
    if(it == S.end()) return it2->y > p.y;
    return (it2->y > p.y && p.y > it->y)||(it->y > p.y);
}

void  driver() 
{
	printf("\ndriver of niceday is running..\n");
    int t;
    scanf("%d",&t);
    while(t--) {
        int N;
        scanf("%d",&N);
        for(int i = 0; i < N; i++)
            scanf("%d %d %d",&P[i].x,&P[i].y,&P[i].z);

        sort(P,P+N,cmp3d);
		
		printf("\nprint the array after sorting..\n");
		for(int i=0;i<N;i++)
            printf("%d %d %d\n",P[i].x,P[i].y,P[i].z);

        S.clear();
        set<Pair>::iterator it;
        int ans = 0;

        for(int i = 0; i < N; i++) {
            p.x = P[i].x;
            p.y = P[i].y;
            it = S.lower_bound(p);
			if(it==S.end())
			{
				printf("\ninside the end..\n");
			}

            if(it == S.begin() || check(it,p)) {
				printf("\ninside the if..\n");
                ans++;
                for(; it != S.end()&&it->y > p.y;)
                    S.erase(it++);
                S.insert(p);
            }
        }

        printf("%d\n",ans);
    }

   // return 0;
}
