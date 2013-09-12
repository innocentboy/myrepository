/**
this file prints the all balanced parantheses.
EX:
N=2;
{}{}
{{}}
*/
#include<cstdio>
#include<vector>
#include<iostream>
#include<algorithm>
#define N 10000
using namespace std;
char s[N];

void print_all_paranthese(vector <string> &vt,int pos,int n,int open,int close)
{
    if(close==n)
    {
     // printf("%s\n",s);
      string ss(s);
      vt.push_back(ss);
    }
    else
    {
      if(open>close)
      {
          s[pos]=')';
          print_all_paranthese(vt,pos+1,n,open,close+1);
       }
       if(open<n)
       {
           s[pos]='(';
           print_all_paranthese(vt,pos+1,n,open+1,close);
        }
    }

}

vector< string > printParenthesis(int n)
{
   vector < string > vt;
   if(n>0)
   print_all_paranthese(vt,0,n,0,0);
   return vt;
}


int main()
{

    int i,j,k,n;
    scanf("%d",&n);
    vector < string > vt=printParenthesis(n);
    for(i=0;i<vt.size();i++)
    cout<<vt[i]<<endl;
    return 0;
}


/**
 * 
 * //IP address are simulated as  a.b.c.d

#include "stdio.h"
#include "string.h"
#include "math.h"
#include <assert.h>

//9091515  12803191 72550255
#define N 255256
#define LEN 100

#define STREAM1 "test_demo.txt"
#define STREAM2 "test1_demo.txt"

#define OUTSTREAM1 "optput1.txt"
#define OUTSTREAM2 "optput2.txt"
#define INTERSECTIPSTREAM "intersectIP.txt"


FILE *out1;
FILE *out2;
FILE *intersectIPstream;


typedef struct stud {
    int val;
    char status;
    char a[4];
    char d[4];
    struct stud *next;
}Node;

typedef struct hashstruct
{
    char b[4];
    char c[4];
    Node *nPtr;
}Hash;

Hash mp1[N],mp2[N];
char s1[LEN]="1.0.0.123.45.12.223.12445.199.239.399.1245.32522..1234";
char s2[LEN]="34.245.12.3455.11.0.0.14685.199.239.3346.83.0.12.0.1";



//initialises the map for providing hashing..
void setUp()
{
    int i;
    for(i=0;i<N;i++)
        mp1[i].nPtr=mp2[i].nPtr=NULL;
}


//insert the Node in the increasing sorted array..
void insert(Node *dest,int idx,int flag)
{
    Node *src=NULL,*p=NULL;
    if(flag==1)
        src=mp1[idx].nPtr;
    else
        src=mp2[idx].nPtr;
    
    if(src==NULL)
    {
        if(flag==1)
            mp1[idx].nPtr=dest;
        else
            mp2[idx].nPtr=dest;
    }
    
    while (src!=NULL&&src->val<=dest->val) {
        if(src->val==dest->val){
            free(dest);
            return;
        }
        p=src;
        src=src->next;
        
    }
    if(p==NULL)
    {
        dest->next=src;
        if(flag==1)
            mp1[idx].nPtr=dest;
        else
            mp2[idx].nPtr=dest;
    }
    else if(src==NULL)
    {
        p->next=dest;
    }
    else
    {
        dest->next=p->next;
        p->next=dest;
    }
    
}


//get the Integer value from the string
int strToInt(char *a,char *b)
{
    int i=0,idx=0,flag=0,j=0,mHash=10;    
    while(a[i]!='\0')
    {
        while (a[i]=='0'&&flag==0) {
            i++;
        }
        if(a[i]=='\0')
        {
            break;
        }
        flag=1;
        idx = idx*mHash+(a[i]-'0');
        i++;
    }
    flag=0;j=0;
    i=0;
    
    j=strlen(b);
    int k=0;
    while (k<3-j) {
        idx*=10;
        k++;
    }
    
    while(b[i]!='\0')
    {
        idx = idx*mHash+(b[i]-'0');
        i++;
    }    
    return idx;
}


//copies the string value to different value
void strCopy(char *dest,char *src,int s,int e)
{
    int j=0;
    while (s<=e) {
        dest[j]=src[s];
        j++;s++;
    }
    dest[j]='\0';
}

//Generates the different possible cominations.
void generateComb(char *a,char *d,char *b,char *c,int flag)
{
    int i,j,alen,dlen;
    int idx=0;
    alen=strlen(a);
    dlen=strlen(d);
    if(atoi(b)>255||atoi(c)>255)
    {
        return;
    }
    idx=strToInt(b, c);
    if(flag==1)
    {
        if(mp1[idx].nPtr==NULL){
            strCopy(mp1[idx].b,b,0,strlen(b)-1);
            strCopy(mp1[idx].c,c,0,strlen(c)-1);
        }
    }
    else
    {
        if(mp2[idx].nPtr==NULL){
            strCopy(mp2[idx].b,b,0,strlen(b)-1);
            strCopy(mp2[idx].c,c,0,strlen(c)-1);
        }
    }
    
    for(i=alen-1;i>=0;i--)
    {
        for(j=0;j<dlen;j++)
        {
            Node *ptr=(Node *)malloc(sizeof(Node));
            strCopy(ptr->a, a, i, alen);
            strCopy(ptr->d, d, 0, j);
            ptr->val=strToInt(ptr->a, ptr->d);
            ptr->next=NULL;
            if(atoi(ptr->a)>255||atoi(ptr->d)>255||atoi(ptr->a)==0||atoi(ptr->d)==0)
            {
                free(ptr);
            }
            else{
                insert(ptr,idx,flag);
            }
        }
    }
}



//parses the first stream..
void parse1()
{
    
    FILE *fptr;
    fptr=fopen(STREAM1,"r");
    
    int k=0,tempIdx=0;
    char a[4],b[4],c[4],d[4];
    a[0]=b[0]=c[0]=d[0]='\0';
    
    char temp[4],temp1[4],charcter[4];
    int nOctact=0,len=0;
    
    if(fptr==NULL)
    {
        printf("\nsome problem in openning the file test1..\n");
        return;
    }
    
    char ch,prvChar='\0';
    
    while (( fscanf(fptr,"%c",&ch) ) != EOF) {
        fputc(ch, fptr);
        if(ch!='.'){
            len++;
            temp[(len-1)%3]=ch;
            
            if(len<4)
                temp1[len-1]=ch;
            
            if(len>3)
            {
                tempIdx=(len-1)%3;
            }
          //  printf("\n*** len :%d***\n",len);
        }
        else if(prvChar=='.'&&ch=='.')
        {
            len=0;
            nOctact=0;
        }
        
        else
        {
            nOctact++;
            temp1[3]='\0';
            if(len<=3)
                tempIdx=0;
            else
                tempIdx=(tempIdx+1)%3;
            
            int i=tempIdx,j;
            j=0;
            do{
                
                //   assert(j<4);
                if(j<4)
                    charcter[j]=temp[i];
                j++;
                if(len>3)
                    i=(i+1)%3;
                else
                    i=(i+1)%len;
              //  printf("\ni:%d  idx:%d  len:%d\n",i,tempIdx,len);
            }while(i!=tempIdx);
            
            if(len>3)
                charcter[3]='\0';
            else
                charcter[len]='\0';
            // printf("\n****** %d ******\n",nOctact);
            switch(nOctact)
            {
                case 1:
                    strCopy(a,charcter,0,strlen(charcter)-1);
                    break;
                case 2:
                    strCopy(b,charcter,0,strlen(charcter)-1);
                    break;
                case 3:
                    strCopy(c,charcter,0,strlen(charcter)-1);
                    break;
                case 4:
                    if(len>3)
                        k=3;
                    else
                        k=len;
                    // printf("\nprevdot:%d len:%d\n",prevDot,prevDot+len);
                    strCopy(d,temp1,0,k-1);
                    // printf("\ns1**** a:%s b:%s c:%s d:%s\n",a,b,c,d);
                    generateComb(a,d,b,c,1);
            }
            if(len>3)
            {
                nOctact=1;
                strCopy(a,charcter,0,strlen(charcter)-1);
            }
            else if(nOctact==4)
            {
                nOctact=3;
                strCopy(a,b,0,strlen(b)-1);
                strCopy(b,c,0,strlen(c)-1);
                strCopy(c,d,0,strlen(d)-1);
            }
            len=0;
        }
        prvChar=ch;
    }
    
    if(nOctact==3)
    {
        if(len>3)
            k=3;
        else
            k=len;
        strCopy(d,temp1,0,k-1);
        // printf("\ns1**** a:%s b:%s c:%s d:%s\n",a,b,c,d);
        generateComb(a,d,b,c,1);
    }
    
    fclose(fptr);
    
    //printing the IP addresses to the file..
    int i=0;
    Node *ptr;
    for(i=0;i<N;i++)
    {
        ptr=mp1[i].nPtr;
        while (ptr!=NULL) {
            if(out1)
            fprintf(out1,"\n%s.%s.%s.%s",ptr->a,mp1[i].b,mp1[i].c,ptr->d);
            ptr=ptr->next;
        }
    }
    
}




//parses the second stream..
void parse2()
{
    FILE *fptr=fopen(STREAM2,"r");
    
    int k=0,tempIdx=0;
    char a[4],b[4],c[4],d[4];
    a[0]=b[0]=c[0]=d[0]='\0';
    
    char temp[4],temp1[4],charcter[4];
    int nOctact=0,len=0;
    
    if(fptr==NULL)
    {
        printf("\nsome problem in openning the file test2..\n");
        return;
    }
    
    char ch,prvChar='\0';
    
    while (( ch = fgetc(fptr) ) != EOF) {
        if(ch!='.'){
            len++;
            temp[(len-1)%3]=ch;
            
            if(len<4)
                temp1[len-1]=ch;
            
            if(len>3)
            {
                tempIdx=(len-1)%3;
            }
        }
        else if(prvChar=='.'&&ch=='.')
        {
            len=0;
            nOctact=0;
        }
        else
        {
            nOctact++;
            
            temp1[3]='\0';
            if(len<=3)
                tempIdx=0;
            else
                tempIdx=(tempIdx+1)%3;
            
            int i=tempIdx,j=0;
            do{
                charcter[j]=temp[i];
                j++;
                if(len>3)
                    i=(i+1)%3;
                else
                    i=(i+1)%len;
            }while(i!=tempIdx);
            
            if(len>3)
                charcter[3]='\0';
            else
                charcter[len]='\0';
            
            switch(nOctact)
            {
                case 1:
                    strCopy(a,charcter,0,strlen(charcter)-1);
                    break;
                case 2:
                    strCopy(b,charcter,0,strlen(charcter)-1);
                    break;
                case 3:
                    strCopy(c,charcter,0,strlen(charcter)-1);
                    break;
                case 4:
                    if(len>3)
                        k=3;
                    else
                        k=len;
                    // printf("\nprevdot:%d len:%d\n",prevDot,prevDot+len);
                    strCopy(d,temp1,0,k-1);
                    // printf("\ns1**** a:%s b:%s c:%s d:%s\n",a,b,c,d);
                    generateComb(a,d,b,c,0);
            }
            if(len>3)
            {
                nOctact=1;
                strCopy(a,charcter,0,strlen(charcter)-1);
            }
            else if(nOctact==4)
            {
                nOctact=3;
                strCopy(a,b,0,strlen(b)-1);
                strCopy(b,c,0,strlen(c)-1);
                strCopy(c,d,0,strlen(d)-1);
            }
            len=0;
        }
        prvChar=ch;
    }
    
    if(nOctact==3)
    {
        if(len>3)
            k=3;
        else
            k=len;
        strCopy(d,temp1,0,k-1);
        //printf("\ns1**** a:%s b:%s c:%s d:%s\n",a,b,c,d);
        generateComb(a,d,b,c,0);
    }
    
    fclose(fptr);
    
    //printing the IP addresses to the file..
    int i=0;
    Node *ptr;
    for(i=0;i<N;i++)
    {
        ptr=mp2[i].nPtr;
        while (ptr!=NULL) {
            if(out2)
                fprintf(out2,"\n%s.%s.%s.%s",ptr->a,mp2[i].b,mp2[i].c,ptr->d);
            ptr=ptr->next;
        }
    }
    
}


//Function that gets the intersected IP addresses.
void getIntersection()
{
    printf("\nget the intersections of IP:");
    int i=0;
    Node *ptr1,*ptr2;
    for(i=0;i<N;i++)
    {
        ptr1=mp1[i].nPtr;
        ptr2=mp2[i].nPtr;
        while (ptr1!=NULL&&ptr2!=NULL) {
            if(ptr1->val==ptr2->val)
            {
                if(intersectIPstream)
                fprintf(intersectIPstream,"\n%s.%s.%s.%s",ptr1->a,mp1[i].b,mp1[i].c,ptr1->d);
                
                printf("\n%s.%s.%s.%s        %s.%s.%s.%s",ptr1->a,mp1[i].b,mp1[i].c,ptr1->d,ptr2->a,mp2[i].b,mp2[i].c,ptr2->d);
                
                ptr1=ptr1->next;
                ptr2=ptr2->next;
            }
            else if(ptr1->val<ptr2->val)
                ptr1=ptr1->next;
            else
                ptr2=ptr2->next;
        }
    }
}

//this is the main function
int main()
{
    
    printf("\nthis is demo programm.\n");
    
    //check();
   // printf("idx:%d",strToInt("0", "2"));
    
    //output file stream..
    out1=fopen(OUTSTREAM1, "w");
    out2=fopen(OUTSTREAM2, "w");
    intersectIPstream=fopen(INTERSECTIPSTREAM, "w");
    
    setUp();
    parse1();
    parse2();
    getIntersection();

  
    return  0;
}


 * /
