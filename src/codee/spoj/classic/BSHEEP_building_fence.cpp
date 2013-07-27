#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<set>
#include<cmath>
#define x first
#define y second
#define N 1000000
#define pb push_back
using namespace std;
typedef pair<int,int> par;
typedef vector<int> VI;
typedef pair< int,pair< int,int > > tri;
tri p[N];
VI v;
//pt p(N);
tri p0;
stack<tri> s;
int n;
double dist;
inline bool cmp_x (tri a,tri b) {
	 return (a.y.x<b.y.x)||(a.y.x==b.y.x&&a.y.y<b.y.y);
 }

 inline bool cmp_y (tri a,tri b) {
	 if(a.y.y<b.y.y)return 1;
	 else if(a.y.y==b.y.y&&a.y.x<b.y.x)return 1;
	 else return 0;
 }
 inline bool polar_cmp(tri a,tri b){
     a.y.x=(a.y.x-p0.y.x);b.y.x=(b.y.x-p0.y.x);
     a.y.y=(a.y.y-p0.y.y);b.y.y=(b.y.y-p0.y.y);
	 if((a.y.x*b.y.y-a.y.y*b.y.x)>0)return 1;
	 else return 0;
 }
 inline void upd_ans(tri a,tri b) {
	  dist+=sqrt((a.y.x-b.y.x)*(a.y.x-b.y.x)+(a.y.y- b.y.y)*(a.y.y-b.y.y)+.0);
}
 inline bool non_left(tri a,tri b,tri c) {
	 a.y.x=(a.y.x-c.y.x);b.y.x=(b.y.x-c.y.x);
     a.y.y=(a.y.y-c.y.y);b.y.y=(b.y.y-c.y.y);
     if((a.y.x*b.y.y-a.y.y*b.y.x)>0) return 1;
     else return 0;
}
int main()
{
    int i,j,t,fl;
    tri b,c;
    par z;
    scanf("%d",&t);
    while(t--)
    { dist=0;
      v.clear();

      while (!s.empty() )
     {
      s.pop();
     }

      scanf("%d",&n);

       for(i=0;i<n;i++)
      {
         scanf("%d%d",&p[i].y.x,&p[i].y.y);
         p[i].x=i+1;

      }


  if(n==1){
           printf("0.00\n1\n\n");

       }
       else{
      sort(p,p+n,&cmp_y);p0=p[0];
      fl=0;
      for(i=0,j=0;i<n;i++)
      {
          if(p[i].y==p[j].y)
          {
            continue;
          }
          j++;
          p[j]=p[i];
      }
      n=j+1;
       for(i=1;i<n;i++)
      {
         if((p[i].y.x*p[i-1].y.y-p[i].y.y*p[i-1].y.x)!=0)
          {
           fl=1;
              break;
          }

      }
      if(!fl)
      {
          tri a=p[0],b=p[n-1];
          printf("%.2f\n",2.0*(sqrt((a.y.x-b.y.x)*(a.y.x-b.y.x)+(a.y.y- b.y.y)*(a.y.y-b.y.y)+.0)));
          if(n==1)printf("%d\n\n",a.x);
          else printf("%d %d\n\n",a.x,b.x);
          continue;
      }

      sort(p+1,p+n,&polar_cmp);

      s.push(p[0]);s.push(p[1]);if(n>2)s.push(p[2]);

      for(i=3;i<n;i++)
      {
         b=s.top();
         if(b.y.x==p[i].y.x&&b.y.y==p[i].y.y)
         continue;
         s.pop();
         c=s.top();s.push(b);

         while(!s.empty()&&non_left(p[i],b,c))
         {
            s.pop();
             if(!s.empty())
            {
                b=s.top();s.pop();c=s.top();s.push(b);
            }else break;

         }
         s.push(p[i]);
      }

      c=s.top();
      dist=0;

      for(i=s.size();i>1;i--){
        b=s.top();
        v.pb(b.x);
        s.pop();
        upd_ans(b,s.top());
      }

      b=s.top();
      v.pb(b.x);
      upd_ans(s.top(),c);
      printf("%.2f\n",dist);

      for(i=v.size()-1;i>=0;i--)
       printf("%d ",v[i]);
       printf("\n\n");
    }
    }
    return 0;
}
