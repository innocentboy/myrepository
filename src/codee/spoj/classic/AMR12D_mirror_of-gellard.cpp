#include<cstdio>
#include<iostream>
#include<string>

int strlen(char *s)
{
  int i=0,count=0;
  while(s[i++])
  {
      count++;
    }
    return count;
}

using namespace std;
int main()
{
    int t,middle,len,end,i;
    char arr[1000001];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",arr);
        len=strlen(arr);
        if(len==1)
            printf("YES\n");
        else if(len==2)
        {
            if(arr[0]==arr[1])
                printf("YES\n");
            else
                printf("NO\n");
        }
        else
        {
            if(len%2==0)
            {
                middle=len/2-1;
                end=len-1;
                for(i=0;i<=middle;i++)
                {
                    if(arr[i]==arr[end])
                        end=end-1;
                    else{
                        printf("NO\n");
                        break;
                    }
                }
                if(i==middle+1)
                    printf("YES\n");
            }
            else
            {
                middle=len/2;
                end=len-1;
                for(i=0;i<middle;i++)
                {
                    if(arr[i]==arr[end])
                        end=end-1;
                    else
                    {
                        printf("NO\n");
                        break;
                    }
                }
                if(i==middle)
                    printf("YES\n");
            }
        }
    }
    return 0;
}
