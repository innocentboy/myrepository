#include<cstdio>
#include<cmath>
#define ESP 1e-6
using namespace std;
class Solution {
public:
    double sqrt(double x) {

        double y,z;
        y=x;z=x-0.1;
        while(fabs(z-y)>ESP){
            y=z;
            z=y-(((y*y)-x)/2*y);
        }
        return(z);
    }
   double sqrtt(double x)
  {
  double x1,x2;
  x1=x;x2=x-0.1;
  while(fabs(x2-x1)>ESP)
  {
     x1=x2;
     x2=x1-(((x1*x1)-x)/2.0*x1);
   }
   return x2;
  }
};

int main()
{
   Solution s;
   printf("\nsqrt of no:%f\n",s.sqrtt(9));
   return 0;
}
