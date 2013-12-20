//imported file..
//#include "IP.h"
#include <stdio.h>
#include <limits.h>

//Function for calculating the Difference of array elements repetedly.
int getFact(int n)
{
    int fact=1;
    while(n>1)
    {
        fact*=n;
        --n;
    }
    return fact;
}

int getCominationValue(int n,int r)
{
    return getFact(n)/(getFact(r)*getFact(n-r));
}

void arrayElementDifference(int a[],int n)
{
    int i,sum=0;
    for(i=0;i<n;i++)
    {
        sum+=(((n-1-i)&1)?-1:1)*getCominationValue(n-1, i)*a[i];
    }
    printf("\nvalue of sum:%d\n",sum);
}

//checks the divisibilty by 4.
/*
To check the divisibility by 4,8,16,or Numbers in binary representations, having Only one ste bit.
We need to check only the remainder that will be left after dividing thet No with the Divider.
EX: Checking divisibility by different N0(divisor) to given divident n is.
    2=!(n&1)
    4=!(n&3)
    8=!(n&7)
    16=!(n&15)
*/
int DivisibleBy4(int n)
{
    n = n > 0 ? n : -n;
    return (!(n&&3));
}

//checks the divisibilty by 3.
int DivisibleBy3(int n)
{
    n = n > 0 ? n : -n;
    while( n > 0 )
        n = (n >> 1) - (n & 1);
    return (n == 0);
}

//checks the divisibilty by 5.
int DivisibleBy5 (int n)
{
    n = n > 0 ? n : -n;
    while( n > 0 )
        n = (n >> 2) - (n & 3);
    return (n == 0);
}


//checks the divisibilty by 6.
int DivisibleBy6(int n)
{
    n = n > 0 ? n : -n;
    while( n > 0 )
        n = 2*(n >> 2) - (n &3);
    return (n == 0);
}

//checks the divisibilty by 7.
int DivisibleBy7(int n)
{
    n = n > 0 ? n : -n;
    while( n > 0 )
        n = 3*(n >> 2) - (n &3);
    return (n == 0);
}
//checks the divisibilty by 9.
int DivisibleBy9(int n)
{
    n = n > 0 ? n : -n;
    while( n > 0 )
        n = (n >>3) - (n&7);
    return (n == 0);
}

//checks the divisibilty by 10.
int DivisibleBy10(int n)
{
    n = n > 0 ? n : -n;
    while( n > 0 )
        n=2*(n>>3) - (n&7);
    return (n == 0);
}

//checks the divisibilty by 11.
int DivisibleBy11(int n)
{
    n = n > 0 ? n : -n;
    while( n > 0 )
        n=3*(n>>3) - (n&7);
    return (n == 0);
}



/**
 Getting the balanced paranthesis
 */
void printValideParantheses(char *s,int n,int open,int close,int index)
{
    if(close==n)
    {
        s[index]='\0';
        printf("\n%s",s);
    }
    if(open>close)
    {
        s[index]=')';
        printValideParantheses(s,n,open,close+1,index+1);
    }
    if(open<n)
    {
        s[index]='(';
        printValideParantheses(s,n,open+1,close,index+1);
        
    }
    
}

/**
 Getting the min element.. in sorted rotated array.
 */

int findMin(int arr[], int low, int high)
{
    // This condition is needed to handle the case when array is not
    // rotated at all
    if (high < low)  return 0;
    
    // If there is only one element left
    if (high == low) return low;
    
    // Find mid
    int mid = low + (high - low)/2; /*(low + high)/2;*/
    
    // Check if element (mid+1) is minimum element. Consider
    // the cases like {3, 4, 5, 1, 2}
    if (mid < high && arr[mid+1] < arr[mid])
        return mid+1;
    
    // Check if mid itself is minimum element
    if (mid > low && arr[mid] < arr[mid - 1])
        return mid;
    
    // Decide whether we need to go to left half or right half
    if (arr[high] > arr[mid])
        return findMin(arr, low, mid-1);
    return findMin(arr, mid+1, high);
}

void getminElement(int a[],int n)
{
    int s,e,m;
    s=0;e=n;
    while (s<e) {
        m=s+(e-s)/2;
        if(a[(m-1)%n]>a[m%n]&&a[m%n]<a[(m+1)%n])
        {
            printf("\n index of minimum element id:%d\n",m);
            break;
        }
        else if(a[e]>a[m])
        {
            e=m-1;;
        }
        else
            s=m+1;
    }
    if(s==e&&s<n)
         printf("\n index of minimum element id:%d\n",s);
    else
         printf("\n index of minimum element id:%d\n",s%n);
}

/**
 Get the comination of string..
 */

void swap(char s[],int i,int j)
{
    char c=s[i];
    s[i]=s[j];
    s[j]=c;
}

void printCombinationString(char s[],int n,int i)
{
    int j;
   if(i==n)
   {
     s[i]='\0';
       printf("\n%s",s);
       return;
   }
    for(j=i;j<n;j++)
    {
        if(j!=i&&s[j]==s[i]) continue;
        swap(s,i,j);
        printCombinationString(s,n,i+1);
        swap(s,j,i);
    }
}

/**
 Function for finding the array with max no of 1's in that row..
 */
int findFirst(int a[],int i,int n)
{
    int s,m,e;
    s=0;e=n-1;
    while(e>=s)
    {
        m=s+(e-s)/2;
        if((m==0||a[m-1]==0)&&a[m]==1)
            return m;
        else if(a[m]==0)
            s=m+1;
        else
            e=m-1;
    }
    return -1;
}

int first(int arr[], int low, int high)
{
    if(high >= low)
    {
        // get the middle index
        int mid = low + (high - low)/2;
        
        // check if the element at middle index is first 1
        if ( ( mid == 0 || arr[mid-1] == 0) && arr[mid] == 1)
            return mid;
        
        // if the element is 0, recur for right side
        else if (arr[mid] == 0)
            return first(arr, (mid + 1), high);
        
        else // If element is not first 1, recur for left side
            return first(arr, low, (mid -1));
    }
    return -1;
}

int rowWithMax1s(int a[][4])
{
    int i,j,k=-1,rowindex=-2;
    for(i=0;i<4;i++)
    {
         j=findFirst(a[i],0,4);
        // j=first(a[i],0,3);
        if(j!=-1&&(4-j)>k)
        {
            k=4-j;
            rowindex=i;
        }
    }
    return rowindex;
}


/**Find the subarray with the given sum..
 */
void findSubArray(int a[],int n,int sum)
{
    int i,j=0,k;
    k=a[0];
    for(i=1;i<n;i++)
    {
        k+=a[i];
        while ((i)>j&&k>sum) {
            k-=a[j++];
        }
        if(k==sum)
            printf("\nsubarray exits.. from : %d  %d\n",j,i);
    }
}


/**
 Find Maximum element in sorted rotated array.
 */
//int findMaximum(int a[],int s,int e)
//{
//      int m;
//    while (s<=e) {
//        m=s+(e-s)/2;
//        if(a[m]>a[m-1]&&a[m]>a[m+1])
//            return m;
//        else if(a[s]<a[m])
//            s=m+1;
//        else
//            e=m-1;
//    }
//    return s;
//}


int findMaximum(int arr[], int low, int high)
{
    
    /* Base Case: Only one element is present in arr[low..high]*/
    if (low == high)
        return arr[low];
    
    /* If there are two elements and first is greater then
     the first element is maximum */
    if ((high == low + 1) && arr[low] >= arr[high])
        return arr[low];
    
    /* If there are two elements and second is greater then
     the second element is maximum */
    if ((high == low + 1) && arr[low] < arr[high])
        return arr[high];
    
    int mid = (low + high)/2;   /*low + (high - low)/2;*/
    
    /* If we reach a point where arr[mid] is greater than both of
     its adjacent elements arr[mid-1] and arr[mid+1], then arr[mid]
     is the maximum element*/
    if ( arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        return arr[mid];
    
    /* If arr[mid] is greater than the next element and smaller than the previous
     element then maximum lies on left side of mid */
    if (arr[mid] > arr[mid + 1] && arr[mid] < arr[mid - 1])
        return findMaximum(arr, low, mid-1);
    else // when arr[mid] is greater than arr[mid-1] and smaller than arr[mid+1]
        return findMaximum(arr, mid + 1, high);
}


/**
 This function prints the interleave of two  strings.
 */
void printInterleaveString(char s[],char s1[],char s2[],int i,int j,int k,int n,int m)
{
     if(j==m&&k==n)
     {
         s[i]='\0';
         printf("\n%s",s);
     }
     if(j<n)
     {
         s[i]=s1[j];
         printInterleaveString(s,s1,s2,i+1,j+1,k,n,m);
     }
     if(k<m)
    {
        s[i]=s2[k];
        printInterleaveString(s,s1,s2,i+1,j,k+1,n,m);
    }

}

/**
 Matcher function which matches the * and ? present in one string with the other string.
 EX:
 "g*ks", "geeks" return:True
 */
int matcher(char s1[],char s2[])
{
    if(*s1=='\0'&&*s2=='\0')
        return 1;
    if((*s1=='*'&&*(s1+1)!='\0')&&*s2=='\0')
        return 0;
    if(*s1=='?'||*s1==*s2)
        return matcher(s1+1, s2+1);
    if(*s1=='*')
        return matcher(s1,s2+1)||matcher(s1+1, s2);
    return 0;
}


void test(char s1[],char s2[])
{
    matcher(s1, s2)==1? puts("Yes"): puts("No");
}

void testMatcher()
{
    test("g*ks", "geeks"); // Yes
    test("ge?ks*", "geeksforgeeks"); // Yes
    test("g*k", "gee");  // No because 'k' is not in second
    test("*pqrs", "pqrst"); // No because 't' is not in first
    test("abc*bcd", "abcdhghgbcd"); // Yes
    test("abc*c?d", "abcd"); // No because second must have 2 instances of 'c'
    test("*c*d", "abcd"); // Yes
    test("*?c*d", "abcd"); // Yes
    test("**", "");//Yes
}

/**
 Sum of two integers without using + operator.
 */
int sum(int a,int b)
{
    if(a==0) return b;
    else if(b==0) return  a;
    int c=a^b;
    int d=(a&b)<<1;
    return sum(c, d);
}

/**
 Finding the right most set bit Position of No.
 */
void setBit()
{
    int n=9;
    printf("Set Bit:%d",n&(~n+1));
}

/**
 Swaping the odd and even position of No.
 */
void swapOddEvenPosition()
{
    int n=6;
    n=((n&0x55555555)<<1)|((n&0xaaaaaaaa)>>1);
    printf("\nSwaped Value:%d",n);
}

/**
 Smallest of two Integers without using branching.
 */
void min()
{
    int a=10,b=15;
    int c=a-b;
    int k=(c>>31)&1;
    c=b+k*(a-b);
    printf("\nmin value is:%d",c);
}

/**
 Count Set bit In an integer.
 */
int countSetBitsInInteger(int n)
{
    int count=0;
    while (n>0) {
        count++;
        n-=n&(~n+1);
    }
    //  printf("\n No Of Ste bits:%d",count);
    return count;
}

/**
 Bits fliped to get the second number.
 */
void flipNumber()
{
    int a=4,b=3;
    int c=a^b;
    printf("\nNo of bits to be flipped:%d",countSetBitsInInteger(c));
}

/**
 Print the binary presentation of No.
 */
void printBinary(int n)
{
    if(n==0) return;
    int remainder=n%2;
    printBinary(n/2);
    printf("%d",remainder);
}

/**
 Integer Overflow check.
 */
int addOvf(int* result, int a, int b)
{
    if( a > INT_MAX - b)
        return -1;
    else
    {
        *result = a + b;
        return 0;
    }
}

/**
 Finding the parity of Number odd/Even.
 */
void getParity()
{
    int n=6,parity=0;
    while (n>0) {
        parity=!parity;
        n-=n&(~n+1);
    }
    printf("\n%s",parity?"odd":"even");
}


/**
 Basic concepts of c.
 */
void demoC()
{

}


//this is the main function
int main(int argc,char **argv)
{
    printf("main\n");
  //  creatBitMap();
    
//    int a[]={5,6,2};
//    arrayElementDifference(a,sizeof(a)/sizeof(a[0]));
    
//    if(DivisibleBy11(122))
//        printf("\nit is divisible by 11.\n");
//    else
//        printf("\nit is not divisible by 11.\n");
    
    
//    char s[7];
//    printValideParantheses(s,3,0,0,0);
    
//    char s[4]="abc";
//    printCombinationString(s,3,0);
    
//    int a[]={5,1,2,3,4};
//    getminElement(a,sizeof(a)/sizeof(a[0]));
//    printf("\n min index:%d\n",findMin(a,0,3));
    
    
//    int mat[4][4] = { {0, 0, 0, 1},
//        {0, 0, 1, 1},
//        {0, 1, 1, 1},
//        {1, 0, 0, 0}
//    };
//    printf("Index of row with maximum 1s is %d \n",rowWithMax1s(mat));
    
//    int arr[] ={1, 4, 20, 3, 10, 5};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    int sum = 27;
//    findSubArray(arr, n, sum);
    
//    int arr[] = {10,20,50,60};
//    int n = sizeof(arr)/sizeof(arr[0]);
//    printf("The maximum element is %d", findMaximum(arr, 0, n-1));
    
//    char s1[]="ab";
//    char s2[]="cd";
//    char s[5];
//    printInterleaveString(s,s1,s2,0,0,0,2,2);
    
//     testMatcher();
    
//        printf("\nSum:%d",sum(13,15));
    
//        setBit();
    
//         swapOddEvenPosition();
    
 //      demoC();
    
 //       min();
    
//       countSetBitsInInteger(5);
    
//       flipNumber();
    
//        printBinary(6);
    
        getParity();
    
      return  0;
}

