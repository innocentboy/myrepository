#pragma comment(linker, "/stack:64000000")
#include <algorithm>
#include <iostream>
#include <cassert>
#include <climits>
#include <utility>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <memory.h>
#include <vector>
#include <bitset>
#include <string>
#include <deque>
#include <queue>
#include <ctime>
#include <set>
#include <map>
#include <deque>
#include <stack>
#include <cmath>
#include<conio.h>
using namespace std;

typedef long long ll;
typedef long double ld;
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define for1(i, n) for (int i = 1; i <= int(n); i++)
#define fore(i, l, r) for (int i = int(l); i < int(r); i++)
#define all(a) (a).begin(), (a).end()
#define sz(a) int((a).size())
#define pb push_back
#define pii pair <int, int>
#define vi vector <int>
#define mp make_pair

template <typename X> inline X abs (const X &a) {return a < 0? -a: a;}
template <typename X> inline X sqr (const X &a) {return a * a;}

const int INF = INT_MAX / 2;
const ll INF64 = LLONG_MAX / 2LL;
const ld EPS = 1E-9, PI = 3.1415926535897932384626433832795;

const ll MOD = 1000000007LL;

inline vector <vector <ll> > mul (const vector <vector <ll> > &a, const vector <vector <ll> > &b)
{
    vector <vector <ll> > res (4);
    forn (i, 4)
        res[i].resize (4);

    forn (i, 4)
        forn (j, 4)
            forn (k, 4)
            {
                res[i][j] = (res[i][j] + ((a[i][k] % MOD) * (b[k][j] % MOD)) % MOD) % MOD;
            }       

    return res;
}

vector <vector <ll> > binPow (const vector <vector <ll> > &a, int k)
{
    if (k == 0)
    {
        vector <vector <ll> > res (4);
        forn (i, 4)
            res[i].resize (4);

        forn (i, 4)
            res[i][i] = 1;

        return res;
    }

    if (k & 1)
        return mul (binPow (a, k - 1), a);
    else
    {
        vector <vector <ll> > res = binPow (a, (k >> 1));
        return mul (res, res);
    }
}

int main()
{
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif*/

    int n;
    cin >> n;

    vector <vector <ll> > g;
    
    g.resize (4);
    forn (i, 4)
        g[i].resize (4);

    forn (i, 4)
        forn (j, 4)
            g[i][j] = (i == j? 0: 1);

    vector <vector <ll> > ans = binPow (g, n);

    cout << ans[0][0] << endl;
    getch();
    return 0;
}
