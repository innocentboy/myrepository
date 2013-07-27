/**
Given an integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.

For example,
Given n = 3,
You should return the following matrix:

[
 [ 1, 2, 3 ],
 [ 8, 9, 4 ],
 [ 7, 6, 5 ]
]

*/
/**

Actually this solution is for Spiral Matrix 1 problem,  modified version of this can be used for the spriral 2 problem..
*/
void spiralMatrix(a[][],int m,int n)
{
    int i,j,k=0,l=0;
    while(k<m&&l<n)
    {
      for(i=l;i<n;i++)
      printf("%d ",a[k][i]);
      k++;
      for(i=k;i<m;i++)
      printf("%d ",a[i][n-1]);
      n--;
      if(k<m)
      {
        for(i=n-1;i>=l;i--)
        printf("%d ",a[m][i]);
        m--
      }
      if(l<n)
      {
         for(i=m-1;i>=k;i--)
         printf("%d ",a[i][l]);
         l++;
       }
    }
}
