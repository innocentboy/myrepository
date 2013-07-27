#include<stdio.h>
#include<conio.h>
#include<string.h>
int main()
{
   char ss[20],su[5]; 
   char *s,*sub;
   int l=0;
   printf("enter the value of string\n");
   gets(ss);   
   //scanf("%s",ss); 
   printf("enter the value of substring character\n"); 
   gets(su);
   //scanf("%s",su);
   s=ss;
   sub=su; 
   l=strlen(s);
   if(l==strspn(s,sub))
   printf("both strings are anagram to each other");
   else
    printf("strings are not anagram..");
    getch();
}
