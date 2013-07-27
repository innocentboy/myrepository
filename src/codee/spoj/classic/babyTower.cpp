    #include<iostream>
    #include<cstdlib>
    #include<cstdio>
    #include<algorithm>
    #include<vector>
    #include<stack>
    #include<set>
    #include<cmath>
    #define FOR(i,a,b) for(i=a;i<=b;i++)
    #define REP(i,n) for(i=0;i<n;i++)
    #define EVER while(1)
    #define dbgi(x) printf(#x" = %d\n",x);
    #define dbgll(x) printf(#x" = %ll\n",x);
    #define gi(i) scanf("%d",&i);
    #define gll(i) scanf("%lld",&i);
    #define gd(i) scanf("%f",&i);
    #define gui(i) scanf("%u",&i);
    #define gull(i) scanf("%ull",&i);
    #define gs(s) scanf("%s",s);
    #define gdi(m,n) scanf("%d%d",&m,&n);
    #define ps(s) printf("%s\n",s);
    #define pi(i) printf("%d\n",i);
    #define pll(i) printf("%ll\n",i);
    #define pd(i) printf("%f\n",i);
    #define sl(s) strlen(s)
    #define mcl(buff) memset(buff,0,sizeof(buff));
    #define mst(buff,val) memset(buff,val,sizeof(buff));
    #define f first
    #define s second
    #define x f
    #define y s.f
    #define z s.s
    #define N 1000000
    #define pb push_back
    #define mp make_pair
    #define mt(a,b,c) mp(a,mp(b,c))
     
    using namespace std;
     
    typedef long long int LL;
    typedef int I;
    typedef pair<int,int> pii;
    typedef pair<LL,LL> pll;
    typedef vector<int> VI;
    typedef pair< int,pair< int,int > > tri;
     
     
    vector < tri > t;
    vector < tri >::iterator it,j;
    int a[3];
     
    inline bool cmp_area(tri a, tri b)
    {
    if(((a.y)*(a.z)) > ((b.y)*(b.z)))return 1;
    if(((a.y)*(a.z) == (b.y)*(b.z)) && ((a.x)>( b.x))) return 1;
    return 0;
     
    }
    inline int maxx(int a,int b)
    {
    return a>b?a:b;
    }
     
    int main()
    {
    I n,i,k,height[100],max=0;
     
    while(true)
    {
    gi(n)
    if(n==0)
    break;
    t.clear();
    REP(i,n){
    scanf("%d%d%d",&a[0],&a[1],&a[2]);
    sort(a,a+3);
    t.pb(mt(a[0],a[1],a[2]));
    t.pb(mt(a[1],a[0],a[2]));
    t.pb(mt(a[2],a[0],a[1]));
    }
    sort(t.begin(),t.end(),&cmp_area);
    height[0]=(*(t.begin())).x;i=1;k=0;
    for(it=t.begin()+1;it!=t.end();it++,i++)
    {
    height[i]=0;k=0;
    for(j=t.begin();j!=it;j++,k++)
    {
    if(((*it).y<(*j).y)&&((*it).z<(*j).z))//{
    // printf("\n%d\n",height[i]);
    height[i]=maxx(height[i],height[k]+(*it).x);
    // printf("\ni=%d:height%d k=%d: height=%d %d\n ",i,height[i],k,height[k],(*it).x);}
    }
    }max=0;
    for(i=0;i<3*n;i++)
    {
    // printf("\nt0:%d ",height[i]);
    if(max<height[i])max=height[i];
    }
     
    printf("%d\n",max);
    /*
    for(it=t.begin();it!=t.end();it++)
    printf("%d %d %d \n",(*it).f,(*it).s.f,(*it).s.s);
    */
    }
    return 0;
    }
