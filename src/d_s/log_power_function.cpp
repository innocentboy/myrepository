/**
 this file calculates the power of the given function in the LOGRITMIC complexity..
*/

#include<cstdio>
#include<algorithm>
#define N 1000
using namespace std;

int power(int n,int pow)
{
  int i,j,ans=1;
  if(pow<=0)return 1;
  if(!(pow&1)){
  ans=power(n,pow/2);
  ans*=ans;
  }
  else
  {
    ans=power(n,pow/2);
    ans*=ans;
    ans*=n;
  }
  return ans;

}

int main()
{
    int i,j,n,pow,t;
    scanf("%d",&t);
    while(t--){
    printf("\nenter the value of no. and power of that no. to be calculated..\n");
    scanf("%d%d",&n,&pow);
    printf("\nAnswer is:%d\n",power(n,pow));
    }
    return 0;
}
