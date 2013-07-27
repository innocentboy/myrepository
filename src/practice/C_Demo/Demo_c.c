/**
THIS FILE CONTAINS THE C  QUESTIONS.
*/

#include<stdio.h>
#include<math.h>
#include<conio.h>
#include<string.h>
#include<stdarg.h>

#define io_lower(a) if(a>='A'&&a<='Z') a+'a'-'A'; else a;


/**
char input.
*/
void char_input()
{
    int a,b;
    a=getchar();
    fflush(stdin);
    b=getchar();
    printf("\nhellos:%c %c\n",a,b);
}



/**
lower case
*/
int to_lower(char a)
{
    if(a>='A'&&a<='Z') return a+'a'-'A';
    else return a;
}




/**
char pointer concets
*/

void char_ptr(char* const p)
{
   p[4]='g';
   printf("\nname::%s\n",p);
}




/**
indiness..
*/
void indiness_machine()
{
  int ind=0x0021;
    char *p=(char *)&ind;
    if(*p)
      printf("\nlittle indian\n");
    else
      printf("\nbigindian\n");
    printf("\nno:%d %d",p,(p+1));
}




/**
nim printf function
*/
void min_printf(char *str,...)
{
    int i=0,j,k,sum=0,d,c;
    char *ss;
    double f;
    va_list la;
    va_start(la,str);
    for(;str[i]!='\0';i++)
    {
       if(str[i]!='%')
       {
          printf("%c",str[i]);
          continue;
       }
       i++;
       switch(str[i])
       {
           case 'd':d=va_arg(la,int);
                    printf("%d",d);
                    break;

           case 'c':c=va_arg(la,int);
                    printf("%c",c);
                    break;

           case  's':ss=va_arg(la,char *);
                     printf("%s",ss);
                     break;

           case  'f':f=va_arg(la,double);
                     printf("%f",f);
                     break;

           default: printf("\nno matching found..\n");
                     break;
       }
    }
    va_end(la);
}



/**
About bit-field in C
*/
void bit_field()
{
    #define K 01
    #define E 02
    #define S 04

   struct bit{
        unsigned int is_extern:3;
        unsigned int is_static:1;
        unsigned int is_keyword:1;
    }flags;
    printf("\nsize of flags:%d\n",sizeof(flags));
   // flags.is_extern|=K|E;
    if(flags.is_extern&K)
      printf("\nthis is extern and keyword\n");
    else
      printf("\nthis is not static storage\n");
    printf("\nAbout the keyword:%d\n",flags.is_keyword);
}

/**
This function deals with the low level input output of C.
*/
void low_level_in_out()
{
  char buf[BUFSIZ];
  int n;
   while ((n = read(0, buf, BUFSIZ)) > 0)
    write(1, buf, n);
}

/**

 getchar:  unbuffered single character input
int getchar(void)
{
       char c;
       return (read(0, &c, 1) == 1) ? (unsigned char) c : EOF;
}


Symstem inmplementation of getchar() for reading the chaunk  of charracter at a time.
*/
int getcharr(void)
{
       static char buf[BUFSIZ];
       static char *bufp = buf;
       static int n = 0;
       if (n == 0) {  /* buffer is empty */
           n = read(0, buf,BUFSIZ);
           printf("\ninside function\n");
       }
       printf("buffer:%s  no:%d\n",buf,n);
       return (--n >= 0) ? (unsigned char) (*bufp)++ : EOF;
}



/**
Main function..
*/
int main(int argc,char *argv[])
{

    //char_input();
    //char_ptr(s);
    //min_printf("This is my min printf:%s  integer:%d  float:%f  char:%c","pandey",4,5.5,'A');
    // bit_field();
    //low_level_in_out();
    //char c=getcharr();
    //printf("character:%c  %c  %c %c %c",c,getcharr(),getcharr(),getcharr(),getcharr());
//    printf(_TIME_);
    return 0;
}
