/*
this file contains the algorithm to calclulate the all tendem repeates in a string.
EX:-
Consider the example of tandem repeats of some simple string, for example:
  "acababaee"
This line contains the following tandem repeats:

    [2, 5] =abab
    [3, 6] =baba
    [7, 8] =ee
*/

#include<cstdio>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#define N 1000
using namespace std;

inline int get_z (const vector <int> & z, int i) {
	 return 0 <= i && i <(int) z. size ()?  z [i]: 0;
 }

/*
start of the Z-function.
*/

vector<int> z_function(const string &s)
{
  int i,j,l,r,len=0;
  len=s.length();
  vector<int> z(len,0);
  l=0;r=0;
  for(i=1;i<len;i++)
  {
       if(i<=r) z[i]=min(z[i-l],r-i+1);
       while(i+z[i]<len&&s[z[i]]==s[i+z[i]])
       z[i]++;
       if(i+z[i]-1>r)
       {
           l=i;r=i+z[i]-1;
           }
    }
    return z;
}
/*
end of z-function.
*/


void output_tandem(const string &s,int shift,bool left,int cntr,int l,int l1,int l2) {
	 int pos;
	 if (left)
		 pos=cntr-l1;
	 else
		 pos =cntr-l1-l2-l1+1;
//     cout <<"["<<shift+pos<<".."<<shift+pos+2*l-1<<"]="<<s.substr(pos,2*l)<<endl;
 }

 void output_tandems (const string &s,int shift,bool left,int cntr,int l,int k1,int k2) {
	 for (int l1=1;l1<=l;++l1) {
		 if (left&&(l1==l)) break;
		 else if (l1<=k1&&(l-l1)<=k2)
			 output_tandem(s,​​shift,left,cntr,l,l1,l-l1);
	 }
 }



/*
start of the find_repeat function
*/

void find_repeates(string s,int shift)
{
  int n=(int)s.length();
  if(n<=1) return ;
  int nu=n/2;
  int nv=n-nu;
  string u=s.substr(0,nu);
  string v=s.substr(nu);
  string ru=string(u.rbegin(),u.rend());
  string rv=string(v.rbegin(),v.rend());
  find_repeates(u,shift);
  find_repeates(v,nu+shift);

  vector<int> z1,z2,z3,z4;
  z1=z_function(ru);
  z2=z_function(v+"#"+u);
  z4=z_function(v);
  z3=z_function(ru+"#"+rv);
  for(int cntr=0;cntr<n;cntr++)
  {
      int l,k1,k2;
      if(cntr<nu)
      {
          l=nu-cntr;
          k1=get_z(z1,nu-cntr);
          k2=get_z(z2,nv+1+cntr);
      }
      else
      {
          l=cntr-nu+1;
          k1=get_z(z3,nu+nv-(cntr-nu));
          k2=get_z(z4,cntr-nu+1);
       }
       if(k1+k2>=l)  output_tandems(s,shift,cntr<nu,cntr,l,k1,k2);
   }
}

/*
end of find_rtepeat function.
*/

/*
end of the function.
*/

int main()
{


    return 0;
}
