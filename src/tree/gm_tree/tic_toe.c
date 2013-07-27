#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define N 3
char matrix[N][N];
char newboard[N][N];
struct gmtree
{
  char board[N][N];
  int turn;
  struct gmtree *son;     
  struct gmtree *snext;
};
struct gmtree *getnode()
{
    struct gmtree *ptr;
    ptr=(struct gmtree *)malloc(sizeof(struct gmtree));
    return ptr;       
}
void nextmove(char brd[][N],int looklevel,char player,char newbrd[][N]);
struct gmtree *build_tree(char brd[][N],int looklevel);
void expand(struct gmtree *,int,int);
struct gmtree *generate(struct gmtree *);
void best_search(struct gmtree *ptr,char player,struct gmtree **,int *value);
int evalute(char matrix[][N],char player); 
char check(void);
void init_matrix(void);
void get_player_move(void);
void get_computer_move(void);
void disp_matrix(void);
int main()
{
    char done;
    printf("This is the game of Tic Tac Toe.\n");
    printf("You will be playing against the computer.\n");
    done = ' ';
    init_matrix();

    do {
    disp_matrix();
    get_player_move();
    done = check();
    if(done!= ' ') break;
    get_computer_move();
    done = check(); 
    } while(done== ' ');
    
    if(done=='x') printf("You won!\n");
    else printf("I won!!!!\n");
    disp_matrix();
    getch();
}

void nextmove(char brd[][N],int looklevel,char player,char newbrd[][N])
{
     struct gmtree *ptr,*pbest;
     int value,i,j;
     ptr=build_tree(brd,looklevel);
    // printf("\n before best search");
     best_search(ptr,player,&pbest,&value);
    // printf("\n after best search");
     for(i=0;i<3;i++)
          for(j=0; j<3; j++)
          newbrd[i][j]=pbest->board[i][j];
}

struct gmtree *build_tree(char brd[][N],int looklevel)
{
       int i,j;
       struct gmtree *ptr;
       ptr=getnode();
       for(i=0;i<N;i++)
          for(j=0;j<N;j++)
          ptr->board[i][j]=brd[i][j];
       ptr->turn=1;
       ptr->son=NULL;   
       ptr->snext=NULL;
       expand(ptr,0,2);   
       return ptr;   
       
}
void expand(struct gmtree *ptr,int depth,int looklevel)
{
     struct gmtree *p,*q;
     if(depth<looklevel)
     {
     p=generate(ptr);
     ptr->son=p;
     while(p!=NULL)
     {
         if(ptr->turn==1)
            p->turn=-1;
         else
            p->turn=1; 
         p->son=NULL;     
         expand(p,depth+1,looklevel);
         p=p->snext;                    
     }
    } 
}

struct gmtree *generate(struct gmtree *ptr)
{
       struct gmtree *p,*r=ptr,*q=NULL;
       int i,j,k,l,t;
       for(i=0;i<N;i++)
         for(j=0;j<N;j++)
       {
          if(r->board[i][j]==' ')
          {
             p=getnode();
             p->snext=NULL;
             p->son=NULL;
             for(k=0;k<N;k++)
                  for(l=0;l<N;l++)
             {
                p->board[k][l]=r->board[k][l];     
             }
             if(ptr->turn==1)
                p->board[i][j]='o';
             else
                p->board[i][j]='x';
             if(q==NULL)
                 q=p;
             else
             {
                p->snext=q;
                q=p;    
             }                               
          }                  
                         
       }p=q;
      /* while(p!=NULL)
       {
       for(t=0; t<3; t++) {
      printf(" %c | %c | %c ",p->board[t][0],
      p->board[t][1], p->board[t][2]);
      if(t!=2) printf("\n---|---|---\n");
      }
    
    printf("\n*********************\n");
      p=p->snext;  
      } */
       return q;
}

void best_search(struct gmtree *ptr,char player,struct gmtree **pbest,int *value)
{
     struct gmtree *p,*q,*pbest2;
     int val,t,i;
     p=ptr->son;
     if(p==NULL)
     {     
         *pbest=ptr;
         *value=evalute(ptr->board,player);                  
     }
     else
     {
        // printf("\n this is else sectin of best search function");
         best_search(p,player,pbest,value);
        // printf("\n come nafter the else section");
         q=p->snext;
         *pbest=p;
         if(ptr->turn==-1)
         {
           *value=-*value;                 
         }
         while(q!=NULL)
         {
             best_search(q,player,&pbest2,&val);
             if(ptr->turn==-1)
                val=-val;
             if(val>*value)
             {
                 *value=val;
                 *pbest=q;              
             }
             q=q->snext;                        
         }        
         if(ptr->turn==-1)
         *value=-*value;
     }
}

int evalute(char matrix[][N],char player)
{
    int i,j,move_x=0,move_o=0,x=0,o=0;
    for(i=0;i<3;i++)
    {
            if(((matrix[i][0]==' '||matrix[i][0]=='o')&&(matrix[i][1]==' '||matrix[i][1]=='o')
             &&(matrix[i][2]==' '||matrix[i][2]=='o'))||(matrix[i][0]==matrix[i][1]&&matrix[i][0]==matrix[i][2]))move_o++; 
            if(((matrix[0][i]==' '||matrix[0][i]=='o')&&(matrix[1][i]==' '||matrix[1][i]=='o')
             &&(matrix[2][i]==' '||matrix[2][i]=='o'))||(matrix[0][i]==matrix[1][i] &&matrix[0][i]==matrix[2][i]))move_o++;
                       
    }
    if(((matrix[0][0]==' '||matrix[0][0]=='o')&&(matrix[1][1]==' '||matrix[1][1]=='o')
             &&(matrix[2][2]==' '||matrix[2][2]=='o'))||(matrix[0][0]==matrix[1][1] &&matrix[0][0]==matrix[2][2]))move_o++;
    if(((matrix[0][2]==' '||matrix[0][2]=='o')&&(matrix[1][1]==' '||matrix[1][1]=='o')
             &&(matrix[2][0]==' '||matrix[2][0]=='o'))||(matrix[0][2]==matrix[1][1] &&matrix[0][2]==matrix[2][0]))move_o++;   

   for(i=0;i<N;i++)
    {
            if(((matrix[i][0]==' '||matrix[i][0]=='x')&&(matrix[i][1]==' '||matrix[i][1]=='x')
             &&(matrix[i][2]==' '||matrix[i][2]=='x')))move_x++; 
            if(((matrix[0][i]==' '||matrix[0][i]=='x')&&(matrix[1][i]==' '||matrix[1][i]=='x')
             &&(matrix[2][i]==' '||matrix[2][i]=='x')))move_x++;
            if((matrix[0][i]=='x'&&matrix[0][i]==matrix[1][i] &&matrix[0][i]==matrix[2][i])||(matrix[i][0]=='x'&&matrix[i][0]==matrix[i][1] &&matrix[i][0]==matrix[i][2]))x=1;          
    }
    if(((matrix[0][0]==' '||matrix[0][0]=='x')&&(matrix[1][1]==' '||matrix[1][1]=='x')
             &&(matrix[2][2]==' '||matrix[2][2]=='x')))move_x++;
    if(((matrix[0][2]==' '||matrix[0][2]=='x')&&(matrix[1][1]==' '||matrix[1][1]=='x')
             &&(matrix[2][0]==' '||matrix[2][0]=='x')))move_x++;   
    if((matrix[0][2]=='x'&&matrix[0][2]==matrix[1][1] &&matrix[0][2]==matrix[2][0])||(matrix[0][0]=='x'&&matrix[0][0]==matrix[1][1] &&matrix[0][0]==matrix[2][2]))x=1;
    if(x==1)
    return -999;
    return (move_o-move_x);
}

void init_matrix(void)
{
int i, j;
for(i=0; i<3; i++)
for(j=0; j<3; j++) matrix[i][j] = ' ';
}

void get_player_move(void)
{
int x, y;
printf("Enter X,Y coordinates for your move: ");
scanf("%d%*c%d", &x, &y);
x--; y--;
if(matrix[x][y]!= ' '){
printf("Invalid move, try again.\n");
get_player_move();
}
else matrix[x][y] = 'x';
}

void get_computer_move(void)
{
int i, j,f=0;;
for(i=0; i<3; i++){
for(j=0; j<3; j++)
if(matrix[i][j]==' ') break;
if(matrix[i][j]==' ') break;
}
if(i*j==4){
printf("draw\n");
}
for(i=0;i<N;i++)
{
       if(((matrix[i][0]==' '&&matrix[i][1]=='o'&&matrix[i][2]=='o')||(matrix[i][1]==' '||matrix[i][1]=='o')
&&(matrix[i][2]==' '||matrix[i][2]=='o'))||(matrix[i][0]==matrix[i][1]&&matrix[i][0]==matrix[i][2])) ;        
                
}
if(f==1);
else
{
   nextmove(matrix,2,'o',newboard); 
   for(i=0; i<N; i++)
     for(j=0; j<N; j++)
     matrix[i][j]=newboard[i][j];
}   
}

void disp_matrix(void)
{
int t;

for(t=0; t<3; t++) {
printf(" %c | %c | %c ",matrix[t][0],
matrix[t][1], matrix [t][2]);
if(t!=2) printf("\n---|---|---\n");
}
printf("\n");
}
char check(void)
{
int i;
for(i=0; i<3; i++)
if(matrix[i][0]==matrix[i][1] &&matrix[i][0]==matrix[i][2]) 
return matrix[i][0];
for(i=0; i<3; i++)
if(matrix[0][i]==matrix[1][i] &&matrix[0][i]==matrix[2][i]) 
return matrix[0][i];
if(matrix[0][0]==matrix[1][1] &&matrix[1][1]==matrix[2][2])
return matrix[0][0];
if(matrix[0][2]==matrix[1][1] &&matrix[1][1]==matrix[2][0])
return matrix[0][2];
return ' ';
}
