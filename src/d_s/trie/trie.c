#include<stdio.h>
#include<string.h>
struct diction
{
struct diction *alpha[26];
int flag;
};
typedef struct diction dic;

dic *root;
int maptoptr(char a)
{
char j='a';
int i;
for(i=0; i<26 a="'a';" root="(dic" i="0;i<26;i++,a++)" t="maptoptr(a);">alpha[t]=NULL;
}
}


void insert(char ip[])
{
dic *ptr=root;
int t;
int f=0;//false
int i=0;

t=maptoptr(ip[i]);
while(ptr->alpha[t]!=NULL && f==0) //not finished searchin and if there is a path with current letter
{
if(ip[i]=='\0' && ptr->flag==1)
{
f=1;//true
}
else
{
ptr=ptr->alpha[t];
i++;
}
t=maptoptr(ip[i]);
}
if(f==1)
{
printf("Already exists\n");
}
else
{
dic *ptr1=NULL;
char temp='a';
int j;
while(ip[i]!='\0')
{
temp='a';
ptr1=(dic *)malloc(sizeof(dic));
for(j=0;j<26;j++,temp++) t="maptoptr(temp);">alpha[t]=NULL;
}
ptr1->flag=0;
t=maptoptr(ip[i]);
ptr->alpha[t]=ptr1;
ptr=ptr1;
i++;
}
ptr->flag=1;
}
}
void search(char ip[])
{
int i=0,f=1;
int t;
dic *ptr=root;
while(ip[i]!='\0'&& f==1)
{
t=maptoptr(ip[i]);
if(ptr->alpha[t]==NULL)
{
f=0;
i++;
break;
}
ptr=ptr->alpha[t];
i++;
}
if(f==1 && ip[i]=='\0' && ptr->flag==1)
printf("\nFound\n");
else
printf("\nNot found\n");
}

void bt_free(dic *ptr)
{
int i=0,t;
char a='a';
if(ptr==NULL)
return;
for(i=0;i<26;i++,a++) t="maptoptr(a);">alpha[t]!=NULL)
{
bt_free((ptr->alpha[t]));
} 
}
free(ptr); 
}
main()
{
char a[25];
printf("Enter the word to insert : ");
gets(a);
createroot();
insert(a);
printf("Enter another word to insert : ");
gets(a);
insert(a);
printf("Enter the word to be searched : ");
gets(a);
search(a);
bt_free(root);
}
