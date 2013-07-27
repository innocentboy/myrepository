/**

Imagine you have a special keyboard with the following keys:

A
Ctrl+A
Ctrl+C
Ctrl+V
where CTRL+A, CTRL+C, CTRL+V each acts as one
function key for "Select All", "Copy", and "Paste" operations respectively.

If you can only press the keyboard for N times (with the above four keys),
please write a program to produce maximum numbers of A. If possible, please also print out the sequence of keys.

That is to say, the input parameter is N (No. of keys that you can press),
the output is M (No. of A's that you can produce).

*/

int f( int n )
{
int DP[n+1];
DP[1]=1;
DP[2]=2;
DP[3]=3;

int copied=0,i,val;

for( i=4;i<=n;i++ )
{
    val= max( DP[i-3]*2 , DP[i-1]+1 );

    if( copied > 0 )
        val=max( val , DP[i-1] + copied );

    if( val == DP[i-3]*2 )
        copied=max( copied , DP[i-3] );

    DP[i]=val ;
}
return DP[n] ;
