#include<cstdio>
#define N 315
char s[N];


int buf[26];
int main()
{

   int i,j,t;
   scanf("%d",&t);
   while(t--)
   {
       for(i=0;i<26;i++)
       buf[i]=0;
       gets(s);
       int i=0;
       while(s[i])
       {

          if(s[i]>=65&&s[i]<=90)
          {
              s[i]=s[i]+32;
            }
           if(s[i]>=97&&s[i]<=122)
            buf[s[i]-'a']++;
            i++;
        }
        int c;
        int flag=0;
        for(i=0;i<26;i++)
        {
          if(buf[i]==0)
          {  flag=1;
                printf("%c",buf[i]+'a');
            }
        }

      // if(flag==1 && i==26)
       //  puts("tumari ma ki");
       if(flag==0){
         puts("~");
       }
       else{
           printf("\n");
       }
    }
  return 0;
}
