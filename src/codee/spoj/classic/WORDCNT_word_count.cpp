#include<cstdio>
#include<string>
#define gi(i) scanf("%d\n",&i);
char s[21005];
int main()
{
    int T,i,max,len,pre,cnt;
    gi(T);
    while(T--)
    {
        gets(s);
        //puts(s);
        i=0;
        pre=0;
        cnt=1;
        max=0;
        len=0;
        while(s[i]!='\0')
        {
          if(s[i]==' ')
         { while(s[i]==' ')
             i++;
             i--;
            if(len==pre){
                cnt++;
                if(cnt>max){
                    max=cnt;
                }
            }
            else{
                cnt=1;
            }
            pre=len;
            len=0;
         }
         else
         {
              len++;
         }
          i++;
        }
        if(len!=0 ){
                if(len==pre)cnt++;
                if(cnt>max){
                    max=cnt;
                }
        }
        if(max)printf("%d\n",max);
        else T++;
    }
}

