/**
Imagine you have a square matrix, where each cell is filled with either black or white. Design an algorithm
to find the maximum subsquare such that all four borders
are filled with black pixels.

*/

/**Solution:
Thoughts:
We are going to scan column by column, checking to see if this column can be the left-border of the
 desired subsquare. Along each column, we build “sliding windows”, from large size to small size. The size of
 the window is the size of the subsquare. The winodw starts at different row, moving from top to bottom. When
 the window is fixed in a position, we chan check if this subsquare is valid or not. If so, we update the max
subsquare we have found then continue.

*/

int isSuqare(int row,int col,int size)
{
  int i,j,k;
  for (int j = 0; j < size; j++){
      if (a[row][col+j]==0) {
        return 0;
      }
      if (a[row+size-1][col+j]==0){
        return 0;
      }
    }

    // Check left and right border.
    for (int i = 1; i < size - 1; i++){
      if (a[row+i][col]==0){
        return 0;
      }
      if (a[row+i][col+size-1]==0){
        return 0;
       }
    }
   return 1;
}



int max_square_with_border()
{
   int r=-1,c=-1,max_size=0,col=0,row;
   while(N-col>=max_size)
   {
       for(row=0;row<n;row++)
       {
         int size=n-max(row,col);
         while(size>max_size)
         {
            if(isSuqare(row,col,size))
            {
              max_size=size;
              r=row;c=col;
              break;
            }
            size--;
          }
        }
        col++;
    }
    printf("\n\***** Maximum size suqare *****\n");
    printf("row:%d\ncol:%d\nsize:%d",r,c,max_size);
}



/**
end of the function.
*/
