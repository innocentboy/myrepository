/*#include<stdio.h>
#include<string.h>
#define N 1010
char str1[N];
char str2[N];
char concat[N];
char db[28][1]={"a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
int a[27],b[27],len1,len2,lencat;
void conct(char *concat,int i,int min)
{
   int j=lencat;
   while(min--)
   {
      strcat(concat,db[i]);           
      j++;         
   }
   lencat=j;
   concat[lencat]='\0';     
}
int main()
{
   int i,j,k,t,min;
   scanf("%d",&t);
   while(t--)
   {
      scanf("%s%s",str1,str2);    
      for(i=0;i<26;i++)
      {
        a[i]=0;b[i]=0;                 
      }
      len1=strlen(str1);len2=strlen(str2);
      lencat=0;
      for(i=0;i<len1;i++)
      a[str1[i]-'a']++;
      for(i=0;i<len2;i++)
      b[str2[i]-'a']++;
      for(i=0;i<26;i++)
      {
         min=(a[i]<b[i])?a[i]:b[i];
         if(min!=0)
         {
            conct(concat,i,min);          
         }                   
      }
      printf("%s\n",concat);    
   } 
   getch(); 
   return 0;    
}*/
