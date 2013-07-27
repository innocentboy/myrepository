#include<string.h>
using namespace std;
class Solution {
    int a[10000];
public:
    int strlen(char *s)
    {

        int i=0,c=0;
        while(s[i++]) c++;
        return c;

    }

    char *strStr(char *haystack, char *needle) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if(!haystack[0]&&!needle[0]) return "";
       else  if(!haystack[0]&&needle[0]) return NULL;
       else  if(haystack[0]&&!needle[0]) return haystack;
        return matcher(haystack,needle,a);

    }
    char *matcher(char *t,char *p,int *a)
{
    int q=0,l=0,i,m=0;
    l=strlen(t);
    prefix(p,a);
    for(i=0;i<strlen(t);i++)
    {

        while(q!=0&&(*(t+i)!=*(p+q)))
        {
                 q=*(a+q-1);

        }
        if(*(t+i)==*(p+q))
        {

                          q+=1;
                         // printf("\n%d:::%d",q,i);
        }

        if(q==strlen(p))
        {
                 //  printf("\nthere is a matching position at position :::%d",(i-q)+1);
                   //q=*(a+q-1);
                   return t+(i-strlen(p))+1;
        }

    }
    return NULL;

}
void prefix(char *p,int *a)
{
     int l,k=0,i;
     *(a)=k;
     l=strlen(p);
     for(i=1;i<l;i++)
     {
           while(k!=0&&(*(p+i)!=*(p+k)))
               k=*(a+k);
            if(*(p+i)==*(p+k))
              k=k+1;
            *(a+i)=k;
     }

}

};
