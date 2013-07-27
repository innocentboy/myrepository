void swap(int **aa,int **bb)
{
    int *c;
    c=*aa;
    *aa=*bb;
    *bb=c;     
}
int main()
{
    int a=5,b=10;
    int *aa,*bb;
    aa=&a;
    bb=&b;
    printf("\n value of pointer aa is:%u",aa);
    printf("\n value of pointer bb is:%u",bb);
    swap(&aa,&bb); 
    printf("\nvalue of a is: %d",*aa);
    printf("\nvalue of b is: %d",*bb);
    printf("\n********...........***********");
    printf("\nvalue of swaping");
    printf("\n value of pointer aa is:%u",aa);
    printf("\n value of pointer bb is:%u",bb);
    getch();   
}
