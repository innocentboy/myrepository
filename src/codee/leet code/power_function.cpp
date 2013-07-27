#include<math.h>
using namespace std;
class Solution {
public:

    double power(double n,int poww)
    {

        int i,j;
        double ans=1;
  if(poww<=0)return 1;
  if(!(poww&1)){
  ans=pow(n,poww/2);
  ans*=ans;
  }
  else
  {
    ans=pow(n,poww/2);
    ans*=ans;
    ans*=n;
  }
  return ans;

    }
    double pow(double n, int poww) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function

         if(poww==0) return 1.0;
         else if(n==0) return 0.0;
        else if(n>0&&poww>0) return power(n,poww);
        else if(n>0&&poww<0) return 1.0/power(n,-(poww));
        else if(n<0&&poww<0)
        {
            if(poww&1) return -(1.0/power(-n,-(poww)));
            else return (1.0/power(-n,-(poww)));

        }
        else if(n<0&&poww>0)
        {
           return (power(n,(poww)));


        }

    }
};
