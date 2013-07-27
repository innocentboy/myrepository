
    //URL:http://www.spoj.pl/problems/TRIP/
    #include <vector>
    #include <list>
    #include <map>
    #include <set>
    #include <deque>
    #include <stack>
    #include <bitset>
    #include <algorithm>
    #include <functional>
    #include <numeric>
    #include <utility>
    #include <sstream>
    #include <iostream>
    #include <iomanip>
    #include <cstdio>
    #include <cmath>
    #include <cstdlib>
    #include <ctime>
    #include <queue>
    #include <string>
    #include <cstring>
    using namespace std;
    #define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
    #define PB push_back
    //#define INF INT_MAX
    #define DEBUG(___x) cout<<#___x<<" = ["<<___x<<"]"<<endl
    #define SORT(___a) sort(___a.begin(),___a.end())
    #define RSORT(___a) sort(___a.rbegin(),___a.rend())
    #define PI 3.141592653589793238
    #define MP make_pair
    #define PII pair<int,int>
    #define ALL(___v) (___v).begin(), (___v).end()
    #define VS vector<string>
    #define VI vector<int>
    #define S size()
    #define B begin()
    #define E end()
    #define print(___v) {cout<<"[";if(___v.S)cout<<___v[0];FOR(___i,1,___v.S)cout<<","<<___v[___i];cout<<"]\n";}
    #define clr(___x, ___v) memset(___x, ___v , sizeof ___x);
    #define tr(container, it) for(typeof(container.begin()) it = container.begin(); it != container.end(); it++)
    typedef long long bint;
    typedef map< string,int > msi;
    typedef map< string,int >::iterator msit;
    typedef map< VI ,int > mvi;
    typedef map< VI ,int >::iterator mvit;
    template<typename T> string tos( T a ) { stringstream ss; string ret; ss << a; ss >> ret; return ret;}
    struct node {
    int i;
    int j;
    };
    int memo[88][88], soto, la, lb;
    string a, b;
    vector<node> arr[88][201];
    set<string> ase;
    VS res;
    void xload(int pa, int pb, string par, int d) {
    if(d == 0) {
    if(ase.count(par) == 0) {
    ase.insert(par);
    res.PB(par);
    }
    return;
    }
    for(char ch='a'; ch <= 'z';ch++) {
    int len = arr[d][ch].S;
    FOR(i,0,len) {
    node now = arr[d][ch][i];
    if(now.i < pa && now.j < pb) {
       xload(now.i, now.j, tos(ch)+par, d-1);
    }
    }
    }
    }
    int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int T;
    cin >> T;
    FOR(t,0,T) {
    cin >> a >> b;
    la = a.S;
    lb = b.S;
    clr(memo, -1);
    FOR(i,0,87)FOR(j,0,201)arr[i][j].clear();
    ase.clear();
    res.clear();
    FOR(i,0,la+1)memo[i][0] = 0;
    FOR(i,0,lb+1)memo[0][i] = 0;
    FOR(i,1,la+1)FOR(j,1,lb+1) {
    if(a[i-1] == b[j-1]) {
    memo[i][j] = memo[i-1][j-1]+1;
    }
    else {
    int ra = memo[i-1][j];
    int rb = memo[i][j-1];
    memo[i][j] = max(ra, rb);
    }
    }
    soto = memo[la][lb];
    FOR(i,0,la)FOR(j,0,lb) {
    if(a[i] == b[j]) {
    node ns ;
    ns.i = i;
    ns.j = j;
    arr[memo[i+1][j+1]][a[i]].PB(ns);
    }
    }
    xload(la, lb, "", soto);
    SORT(res);
    int lox = res.S;
    if(t)cout << endl;
    FOR(i,0,lox)cout << res[i] << endl;
    }
    return 0;
    }

