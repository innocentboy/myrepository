/**

*/
#include<cstdio>
#include<vector>
#include<set>
#include<vector>
#include<stack>
#include<queue>
#include<algorithm>
#include<cstring>
#include<math.h>
#include<cstring>
#include<iostream>

using namespace std;

/**
####################################################
####################################################
####################################################
####################################################
Array
####################################################
####################################################
####################################################
####################################################
*/
/**
Arrange in three parts..
*/
int index(int i,int N)
{
    int idx=(i%3)*N+i/3;
    return idx;
}

void arrangThreeParts()
{
    int a[]={0,0,0,0,0,1,1,1,1,1,2,2,2,2,2};
    int i,j,k,n=sizeof(a)/sizeof(a[0]),idx;
    int N=n/3;
    for(i=0;i<n;i++)
    {
       idx=index(i,N);
       while(idx<i)
       {
         idx=index(idx,N);
       }
       if(a[idx]!=a[i])
        a[i]^=a[idx]^=a[i]^=a[idx];
    }
    printf("\nPint the aray..");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

/**
Arrange array in two parts.
*/
int indexTwo(int i,int N)
{
    int idx=(i%2)*N+i/2;
    return idx;
}

void arrangTwoParts()
{
    int a[]={0,0,0,0,0,1,1,1,1,1};
    int i,j,k,n=sizeof(a)/sizeof(a[0]),idx;
    int N=n/2;
    j=n/2;k=0;
    for(i=0;i<n;i++)
    {
        if(k)
        {
            k=0;
            if(a[i]!=a[j])
             a[i]^=a[j]^=a[i]^=a[j];
             j++;
        }
        else
        {
            k=1;
            //do nothing..
        }
    }

    printf("\nPint the aray..");
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
}

/**
Finding maximum in sorted rotated array.. Having bitonic nature.
*/
int findMaxElement(int A[],int l,int r)
{
    if(l>r||l==r) return l;
    int m=(l+r)>>1;
    if(A[l]<A[m])
    return   findMaxElement(A,m,r);
    else return findMaxElement(A,l,m-1);
}

void maximumInBitonicSequence()
{
        //int arr[] = {8, 10, 20, 80, 100, 200, 400, 500, 3, 2, 1};
        int arr[]={1,2,4,3,2};
        int i,j,k,n=sizeof(arr)/sizeof(arr[0]);
        i=findMaxElement(arr,0,n-1);
        printf("\nMAximum index:%d value:%d",i,arr[i]);
}
/**
Find minimum element in sorted rotated array..
*/
int minimumElement(int A[],int l,int r)
{
    if(l>r||l==r) return l;
    int m=(l+r)>>1;
   // printf("\nm:%d %d %d",l,m,r);
    if(A[m]<A[r])
    return minimumElement(A,l,m);
    else return minimumElement(A,m+1,r);
}

void findMinimumElement()
{
    int arr[]={4,5,6,1,2};
    //int arr[]={2,1};
    int i,n=sizeof(arr)/sizeof(arr[0]);
    printf("\nn:%d",n);
    i=minimumElement(arr,0,n-1);
    printf("\nMinmimum index:%d value:%d",i,arr[i]);
}




/**
Given array with sorted element. Find the smallest element missing from the array..
*/
int smallestIndex(int arr[],int s,int e)
{
    if(s>e)
    return e;
    if(arr[s]!=s)
    return s;
    int mid=(s+e)>>1;
    if(arr[mid]>mid)
        return smallestIndex(arr,s,mid);
    else
        return smallestIndex(arr,mid+1,e);
}

void findSmallestMissInteger()
{
    int arr[]={0,1,2,3,4,5,6,7,7,7,7,10};
    int i,j,k,n=sizeof(arr)/sizeof(arr[0]);
    printf("\nSmallest No:%d",smallestIndex(arr,0,n-1));
}


/**
Sort element by frequenecy..
*/
typedef struct DataToSort
{
        int value;
        int count;

        DataToSort(int v=0,int c=0)
        {
                value=v;
                count=c;
        }

        DataToSort(const DataToSort &o)
        {
                value=o.value;
                count=o.count;
        }

        DataToSort& operator=(const DataToSort &o)
        {
                value=o.value;
                count=o.count;
        }

        int  operator<(const DataToSort &o) const
        {
            return value<o.value;
        }

};

typedef struct TempDataToSort
{
        int value;
        int count;
        int operator<(const TempDataToSort& o) const
        {
            return count>o.count;
        }
};

void sortByFrequency()
{
    int arr[] = {2, 3, 2, 4, 5, 12, 2, 3, 3, 3, 12};
    int i,n = sizeof(arr)/sizeof(arr[0]);
//    sortByFrequencyOfElement(arr, n);
    set<DataToSort> st;
    set<DataToSort>::iterator it;
    multiset<TempDataToSort> stTemp;
    multiset<TempDataToSort>::iterator itr;
    for(i=0;i<n;i++)
    {
            DataToSort d(arr[i],0);
            it=st.find(d);
            if(it!=st.end())
            {
                    DataToSort t=*it;
                    st.erase(it);
                    t.count++;
                    st.insert(t);
            }
            else
            {
                    DataToSort d(arr[i],1);
                    st.insert(d);
            }
    }
   // sort(st.begin(),st.end(),comparator());
   printf("\nelement befor sort\n");
    for(it=st.begin();it!=st.end();it++)
   {
       printf("\n%d %d",it->value,it->count);
   }
   for(it=st.begin();it!=st.end();it++)
   {
        TempDataToSort d;
        d.value=(*it).value;
        d.count=(*it).count;
        stTemp.insert(d);
    }
    printf("\nAfter sorting the element by frequency");
    for(itr=stTemp.begin();itr!=stTemp.end();itr++)
    {
            printf("\n%d %d",(*itr).value,(*itr).count);
    }
}

/**
Find the median of the element of the stream of the array.
*/
/**
This is maxHeapify which heapify the array in max heap..
*/
void minHeapify(vector<int>& v,int i,int n)
{
        int l,r,t;
        l=2*i+1;
        r=2*i+2;
        if(l<n&&v[l]<v[i])
        t=l;
        else
        t=i;
        if(r<n&&v[r]<v[t])
        t=r;
        if(t!=i)
        {
          if(v[t]!=v[i]){
          int tt=v[t];
          v[t]=v[i];
          v[i]=tt;
          }
          minHeapify(v,t,n);
        }
}

void maxHeapify(vector<int>& v,int i,int n)
{
        int l,r,t;
        l=2*i+1;
        r=2*i+2;
        if(l<n&&v[l]>v[i])
        t=l;
        else
        t=i;
        if(r<n&&v[r]>v[t])
        t=r;
        if(t!=i)
        {
          if(v[t]!=v[i]){
          int tt=v[t];
          v[t]=v[i];
          v[i]=tt;
          }
          maxHeapify(v,t,n);
        }
}

/**
Min Heapify
*/
void maxheap(vector<int> &v)
{
        int i,j,k,n=v.size();
        for(i=n/2;i>=0;i--)
        {
           minHeapify( v,i,n);
        }
}

/**
Max Heapify
*/
void maxheapHeapify(vector<int> &v)
{
        int i,j,k,n=v.size();
        for(i=n/2;i>=0;i--)
        {
           maxHeapify( v,i,n);
        }
}

void minheapHeapify(vector<int> &v)
{
        int i,j,k,n=v.size();
        for(i=n/2;i>=0;i--)
        {
           minHeapify( v,i,n);
        }
}

void maxheapify(vector<int> &v)
{
    int i,j,n=v.size();
    i=n-1;
    while(i>=0)
    {
      j=i/2;
      if(j>=0&&v[j]<v[i])
      {
          v[j]^=v[i]^=v[j]^=v[i];
          i=j;
      }
      else
            break;
    }
}

void minheapyfi(vector<int> &v)
{
    int i,j,n=v.size();
    i=n-1;
    while(i>=0)
    {
      j=i/2;
      if(j>=0&&v[j]>v[i])
      {
          v[j]^=v[i]^=v[j]^=v[i];
          i=j;
      }
      else
            break;
    }
}

vector<int> maxHeapVector;
vector<int> minHeapVector;

int findMedianOfStream(int num)
{
        int m,n,ans=0;
        if(maxHeapVector.size()==0)
        {
            maxHeapVector.push_back(num);
            return num;
        }
        if(num<=maxHeapVector[0])
        {
            maxHeapVector.push_back(num);
            maxheapify(maxHeapVector);
        }
        else
        {
            minHeapVector.push_back(num);
            minheapyfi(minHeapVector);
        }
        m=maxHeapVector.size();
        n=minHeapVector.size();

        if(m==n+1)
        {
            ans= maxHeapVector[0];
        }
        else if(n==m+1)
            ans=minHeapVector[0];
        else if(m==n)
        {
            ans=(maxHeapVector[0]+minHeapVector[0])/2;

        }
        else if(abs(m-n)>1)
        {
           if(m>n){
           int temp=maxHeapVector[0];
           maxHeapVector[0]=maxHeapVector[m-1];
           maxHeapVector.pop_back();
           maxHeapify(maxHeapVector,0,maxHeapVector.size());
           minHeapVector.push_back(temp);
           minheapyfi(minHeapVector);
           }
           else
           {
            int temp=minHeapVector[0];
            minHeapVector[0]=minHeapVector[n-1];
            minHeapVector.pop_back();
            minHeapify(minHeapVector,0,minHeapVector.size());
            maxHeapVector.push_back(temp);
            maxheapify(maxHeapVector);
            }
           ans=(maxHeapVector[0]);
        }

        //printf the vectors..
        printf("\nmax heap\n");
        for(int i=0;i<maxHeapVector.size();i++)
        printf("%d ",maxHeapVector[i]);
        printf("\nMin heap..\n");
        for(int i=0;i<minHeapVector.size();i++)
        printf("%d ",minHeapVector[i]);

        //return
        return ans;
}

void findFindMedianofArray()
{
    int n;
    printf("\nEnter the element..");
    while(scanf("%d",&n)&&n!=-1)
    {
            printf("\nMedian is:%d",findMedianOfStream(n));
            printf("\nEnter the element..");
    }
    printf("\nWe are done with the processing..");
}




/**
####################################################
####################################################
####################################################
####################################################
Tree



####################################################
####################################################
####################################################
####################################################
*/

/**
####################################################
####################################################
####################################################
####################################################
List
####################################################
####################################################
####################################################
####################################################
*/

/**
####################################################
####################################################
####################################################
####################################################
String
####################################################
####################################################
####################################################
####################################################
*/

/**
String match..
*/
bool wildCardMatch(const char *s1,const char *s2)
{
    if(*s1=='\0'&&*s2=='\0')
    return true;
    if(*s1=='*'&&*(s1+1)!='\0'&&*s2=='\0')
    return false;
    if(*s1=='?'||*s1==*s2)
    return wildCardMatch(s1+1,s2+1);
    if(*s1=='*')
    return wildCardMatch(s1+1,s2)||wildCardMatch(s1,s2+1);
    return false;
}

void stringMatch()
{
    char s1[]="a*d?c";
    char s2[]="abbbdcc";
    if(wildCardMatch(s1,s2))
        printf("\nBoth are matched..");
    else
        printf("\nStrings are dfferent..");
}

/**
Longest incresing subsequence..
*/
void lengestSeubsequence()
{
    char s1[]="abhsgdjd";
    char s2[]="ahgsbdft";
    int i,j,k,m,n;
    m=strlen(s1);
    n=strlen(s2);
    int dp[m+1][n+1];
    for(i=0;i<=m;i++)
    dp[i][0]=0;
    for(i=0;i<=n;i++)
    dp[0][i]=0;
    for(i=1;i<=m;i++)
    {
            for(j=1;j<=n;j++)
            {
                    if(s1[i-1]==s2[j-1])
                    {
                            dp[i][j]=dp[i-1][j-1]+1;
                    }
                    else if(dp[i-1][j]>dp[i][j-1])
                    dp[i][j]=dp[i-1][j];
                    else
                    dp[i][j]=dp[i][j-1];
            }
    }
    printf("\nLingest length:%d",dp[m][n]);
}
/**
Edit distance..
*/
void editdistance()
{
    char s1[]="suhndh";
    char s2[]="shumnh";
    int i,j,k,m,n;
    m=strlen(s1);
    n=strlen(s2);
    int dp[m+1][n+1];
    dp[0][0]=0;
    for(i=1;i<=m;i++)
    dp[i][0]=i;
    for(i=1;i<=n;i++)
    dp[0][i]=i;
    for(i=1;i<=m;i++)
    {
            for(j=1;j<=n;j++)
            {
                    if(s1[i-1]==s2[j-1])
                    {
                            dp[i][j]=dp[i-1][j-1];
                    }
                    else if(dp[i-1][j]<dp[i][j-1])
                    dp[i][j]=dp[i-1][j]+1;
                    else
                    dp[i][j]=dp[i][j-1]+1;
            }
    }
    printf("\nLingest length:%d",dp[m][n]);
}

/**
####################################################
####################################################
####################################################
####################################################
DP
####################################################
####################################################
####################################################
####################################################
*/
/**
Maximum sum of the array where no two elements will be consecutive..
*/
int noTwoConsecutive(int dp[],int arr[],int i,int n,int f)
{
    if(i>=n) return 0;
    if(i==n-1&&f) return dp[i]=0;
    if(i==n-1)return dp[i]=arr[i];
    if(dp[i]!=-1) return dp[i];
    return dp[i]=max(arr[i]+noTwoConsecutive(dp,arr,i+2,n,f),noTwoConsecutive(dp,arr,i+1,n,f));
}

void maximumSumOfElementsNoTwoConsecutive()
{
        int arr[] = {5,  5, 10, 40, 50, 35};
        int i,j,k,n=sizeof(arr)/sizeof(arr[0]);
        int dp[n];
        for(i=0;i<n;i++)
        dp[i]=-1;
        int sum=max(arr[0]+noTwoConsecutive(dp,arr,2,n,1),noTwoConsecutive(dp,arr,1,n,0));
        printf("\nMax sum:%d",sum);
}

/**

sqrt of no.
*/
void sqrt(int x) {
        int mid,l,u;
        if(x==0||x==1) return ;
        l=0;
        u=x;
        while(l<u)
        {
            mid=l+(u-l)/2;
            printf("\nmid:%d",mid);
           /* if((mid)==x/mid)
            {
                break;
            }
            */
            if(mid>x/mid)
            u=mid-1;
            else
            l=mid;
        }
        printf("\nmid:%d l:%d",mid,l);
}

void sqrtOfNo()
{
        sqrt(5);
}

/**

*/
void parentheses(vector<string> &ans,int open,int close,int n,int index,char *s)
    {
        if(close==n)
        {
            s[index]='\0';
            string str(s);
            ans.push_back(str);
            return ;
        }
        if(open<n)
        {
            s[index]='(';
            parentheses(ans,open+1,close,n,index+1,s);
        }
        if(close<open)
        {
            s[index]=')';
            parentheses(ans,open,close+1,n,index+1,s);
        }

    }

    void generateParenthesis(int n) {
        int i,j,k;
        char s[2*n+1];
        vector<string> ans;
        parentheses(ans,0,0,n,0,s);
        for(i=0;i<ans.size();i++)
        cout<<ans[i];
}

/**
Spiral matrix..
*/
void spiral(int n)
{
    vector< vector<int> > ans(n,vector<int>(n));
    int i,j,k=0,l=0,cnt=1;
    int temp=n;
    int m=n;
    while(k<m&&l<n)
    {
        for(i=l;i<n;i++)
        {
            ans[k][i]=cnt++;
        }
        k++;
        for(i=k;i<n;i++)
        ans[i][n-1]=cnt++;
        n--;
        if(k<m)
        {
            for(i=n-1;i>=l;i--)
            ans[m-1][i]=cnt++;
            m--;
        }
        if(l<n)
        {
            for(i=m-1;i>=k;i--)
            ans[i][l]=cnt++;
            l++;
        }
    }
    n=temp;
    printf("\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",ans[i][j]);
        printf("\n");
    }
}

/**
Largest rectangle in histgram..
*/
/**
Method :2
Nice way of solving the largest rectangle question.
*/
void largetstRectangle()
{
    //int height[]={4,3,5,5,9,2,8,4,7,2,3,8,3,5,4,7,9};
    int height[]={2,2,2,2,0};
    int i,j,k,n=sizeof(height)/sizeof(height[0]);
    stack<int> st;
    int maxx=0;
    i=0;
    while(i<=n)
    {
        if(st.empty()||height[st.top()]<=height[i])
        st.push(i++);
        else
        {
            int t=st.top();
            st.pop();
            maxx=max(maxx,height[t]*(st.empty()?i:(st.top()-i-1)));
        }
    }
    printf("\nAns: %d",maxx);
}

/**
Method :1
*/
int largestRectangleArea()
{
    //int height[]={2,5,5,6,2,3};
    //int height[]={2,2,2,2};
    //int height[]={1};
    int height[]={4,3,5,5,9,2,8,4,7,2,3,8,3,5,4,7,9};
    int i,j,k,n=sizeof(height)/sizeof(height[0]);
    int l[n],r[n];
    stack< pair<int,int> > st;
    for(i=0;i<n;i++)
    l[i]=r[i]=-1;
    l[0]=0;
    pair<int,int> pr,pr1;
    pr.first=height[0];
    pr.second=0;
    st.push(pr);
    for(i=1;i<n;i++)
    {
        pr1.first=-1;
        while(!st.empty()&&st.top().first>=height[i])
        {
            pr1=st.top();
            st.pop();
        }
        if(st.empty())
        {
            if(pr1.first==-1)
            l[i]=i;
            else
            l[i]=pr1.second;
        }
        else{
            if(pr1.first!=-1)
            l[i]=pr1.second;
            else
            l[i]=i;
        }
            pr.first=height[i];
            if(pr1.first==-1)
            pr.second=i;
            else
            pr.second=pr1.second;
            st.push(pr);
    }
    while(!st.empty()) st.pop();
    pr.first=height[n-1];
    pr.second=n-1;
    st.push(pr);
    r[n-1]=n-1;
    for(i=n-2;i>=0;i--)
    {
        pr1.first=-1;
        while(!st.empty()&&st.top().first>=height[i])
        {
            pr1=st.top();
            st.pop();
        }
        if(st.empty())
        {
            if(pr1.first==-1)
            r[i]=i;
            else
            r[i]=pr1.second;
        }
        else{
            if(pr1.first!=-1)
            r[i]=pr1.second;
            else
            r[i]=i;

        }
            pr.first=height[i];
            if(pr1.first==-1)
            pr.second=i;
            else
            pr.second=pr1.second;
            st.push(pr);
    }
    printf("\nll\n");
    for(i=0;i<n;i++)
    printf("%d ",l[i]);
    printf("\nrr\n");
    for(i=0;i<n;i++)
    printf("%d ",r[i]);

    int ans=0,maxx;
    for(i=0;i<n;i++)
    {
        maxx=(i-l[i])*height[i];
        maxx+=(r[i]-i+1)*height[i];
        ans=max(ans,maxx);
    }
    printf("\nAns:%d",ans);

    //calling largetstRectangle() method..
    largetstRectangle();

}


/**
Maxpoints on a line..
*/
struct Point {
      int x;
      int y;
      Point() : x(0), y(0) {}
      Point(int a, int b) : x(a), y(b) {}
 };

static  bool compare(const struct Point &a,const struct Point &b)
 {
     return a.y*b.x<a.x*b.y;
 }

void  maxPoints() {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.

        //Point points[]={Point(2,3),Point(3,3),Point(-5,3)};
        //Point points[]={Point(0,0),Point(1,1),Point(1,-1)};
         Point points[]={Point(1,1),Point(1,1),Point(2,3)};

        int n=sizeof(points)/sizeof(points[0]),i,j,k,max=-1,tmp=-1;

        sort(points,points+n,compare);
        printf("\nPrint the points array..");
        for(i=0;i<n;i++)
        {
            Point p=points[i];
            printf("\na:%d b:%d",p.x,p.y);
        }

        tmp=1;
        struct Point a,b;
        for(i=1;i<n;)
        {
            a=points[i-1];
            b=points[i];
            if(a.y==b.y)
            {
                printf("\ninside if");
                while(a.y==b.y)
                {
                    tmp++;
                    i++;
                    if(i==n)break;
                    a=points[i-1];
                    b=points[i];
                }
                if(tmp>max)
                max=tmp;
                tmp=1;
            }
            else if(a.x==b.x)
            {
                while(a.x==b.x)
                {
                    tmp++;
                    i++;
                    if(i==n)break;
                    a=points[i-1];
                    b=points[i];
                }
                if(tmp>max)
                max=tmp;
                tmp=1;
            }
            else if(a.y*b.x==a.x*b.y)
            {
                while(a.y*b.x==a.x*b.y)
                {
                    tmp++;
                    i++;
                    if(i==n)break;
                    a=points[i-1];
                    b=points[i];
                }
                if(tmp>max)
                max=tmp;
                tmp=1;
            }
            else
            {
                printf("\nInside else..");
                i++;
                if(tmp>max)
                max=tmp;
                tmp=1;
            }
        }
        if(tmp>max)
        max=tmp;
        printf("\nMax:%d",max);
}

/**
Remove duplicates
*/
void  removeDuplicates() {
        int i,j;
        int A[]={1,1,1,2,2,3,4,5,5,6};
        int n=10;
        i=1;j=0;
        for(i=1;i<n;)
        {
            if(A[i]==A[i-1])
            {
                while(i<n&&A[i]==A[i-1])
                i++;
            }
            else
            {
                A[++j]=A[i];
                i++;
            }
        }
        printf("\nAns:%d",j+1);
        printf("\nPrintf teh array\n");
        for(i=0;i<=j;i++)
        printf("%d ",A[i]);
}

/**
Remove element.
*/
void removeInstanceFromArrayInplace()
{
    int a[]={2,1,3,4,1,2,5,3,1};
    int n=sizeof(a)/sizeof(a[0]);
    int i,j,k,m=1;
    j=0;
    for(i=0;i<n;i++)
    {
        if(a[i]!=m)
             a[j++]=a[i];
    }
    printf("\nLength:%d\n",j);
    for(i=0;i<j;i++)
    printf("%d ",a[i]);
}

/**
Finding subsets from the given vector.
*/
void subsets()
{
        int i,j,k,n=2;
        vector<int> S(2);
        for(i=0;i<n;i++)
        S[i]=i+1;
        n=S.size();
        vector< vector<int> > ans;
        for(i=0;i<(1<<n);i++)
        {
                vector<int> vt;
                for(k=0;k<n;k++)
                {
                    if(i&(1<<k))
                    vt.push_back(S[k]);
                }
                ans.push_back(vt);
        }
        for(i=0;i<ans.size();i++)
        {
            for(j=0;j<ans[i].size();j++)
            printf("%d ",ans[i][j]);
            printf("\n");
        }
}

/**
Generate permutations..
*/
void putmutation(vector< vector<int> > &ans,vector<int> &num,int index,int n)
{
        if(index==n)
        {

                ans.push_back(num);
        }
        else{
            for(int i=index;i<n;i++)
            {
                if(i!=index&&num[i]==num[index]) continue;
                if(num[i]!=num[index])
                num[i]^=num[index]^=num[i]^=num[index];
                putmutation(ans,num,index+1,n);
                if(num[i]!=num[index])
                num[i]^=num[index]^=num[i]^=num[index];
            }
        }
}

void permute() {
        int i,j,k,n;
        vector<int> num(4);
        n=num.size();
        for(i=0;i<n;i++)
        num[i]=i+1;
        num[1]=1;
        num[2]=2;
        vector< vector<int> > ans;
        putmutation(ans,num,0,n);
        printf("\nPrint the permutations..\n");
        for(i=0;i<ans.size();i++)
        {
            for(j=0;j<ans[i].size();j++)
                printf("%d ",ans[i][j]);
            printf("\n");
        }
}

/**
Finding combination sums t given target from the array.
*/
void combinatin(set< vector<int> > &st,vector<int> &candidates,int target,vector<int>::iterator itr
,vector<int> vt)
{
        if(target==0)
        {
            st.insert(vt);
            return ;
        }
        vector<int>::iterator it;
        for(it=itr;it!=candidates.end();it++)
        {
            if(*it<=target)
            {
                vt.push_back(*it);
                //If Number counld be used many times then..
                combinatin(st,candidates,(target-*it),it,vt);
                //if No counld be used only nce then.
                //Increment the iterator after using that value.
                //combinatin(st,candidates,(target-*it),it+1,vt);
                vt.pop_back();
            }
            else
            return ;
        }
}

void combinationSum()
{
            vector<int> candidates;
            int target=7;
            candidates.push_back(2);
            candidates.push_back(3);
            candidates.push_back(6);
            candidates.push_back(7);

            vector< vector<int> > ans;
            set< vector<int> > st;
            set< vector<int> >::iterator itr;
            vector<int> vt;
            sort(candidates.begin(),candidates.end());
            combinatin(st,candidates,target,candidates.begin(),vt);
            for(itr=st.begin();itr!=st.end();itr++)
            ans.push_back(*itr);
            printf("\nprint the answer vector \n");
            for(int i=0;i<ans.size();i++)
            {
                for(int j=0;j<ans[i].size();j++)
                printf("%d ",ans[i][j]);
                printf("\n");
            }
}

/**
Word search in a given 2-D array.
*/

vector< vector<bool> > visit;
bool wordExit(vector<vector<char> > &board,string word,int i,int j,int index,int m,int n)
{
        if(i>=0&&j>=0&&i<=m&&j<=n)
        {
            if(!visit[i][j]&&word[index]==board[i][j])
            {
                visit[i][j]=true;
                bool ans=wordExit(board,word,i-1,j,index+1,m,n)||wordExit(board,word,i+1,j,index+1,m,n)
                ||wordExit(board,word,i,j-1,index+1,m,n)||wordExit(board,word,i,j+1,index+1,m,n);
                if(ans==true) return ans;
                else
                {
                    visit[i][j]=false;
                    return false;
                }
            }
            else
            return false;
        }
        else
        return false;
}

bool exist() {

        bool ans=false;
        int i,j,k,m,n;
        vector< vector<char> > board;
        string word;
        m=board.size();
        if(m==0) return false;
        n=board[0].size();
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            visit[i].push_back(false);
        }
        for(i=0;i<m;i++)
            for(j=0;j<n;j++){
            ans=wordExit(board,word,i,j,0,m,n);
            if(ans)
            break;
            }

        if(ans)
            printf("\nword is fund..\n");
        else
            printf("\nword is not found..\n");
    }

/**
Getting power of number..
*/
//Prblem of overflow.
double power(double x,long int n)
    {
        if(n==0) return 1;
       // printf("\nx:%f n:%d",x,n);
        if(!(n&1))
        {
            double b=power(x,n>>1);
            return b*b;
        }
        else
        return power(x,n-1)*x;
    }

void poww(double x,long int n) {
        double ans=0;
        int signNo=1;
        int signPow=1;
        if(x<0)
        signNo=(n&1)?-1:1;
        if(n<0)
        signPow=-1;
        if(signPow==1)
        ans=signNo*power(fabs(x),abs(n));
        else
        ans= (signNo)/power(fabs(x),abs(n));
        printf("\nAns:%f\n",ans);
}

/**
Generate next permutaion of given array.
*/
void nextPermutation()
{
        vector<int> num;
        num.push_back(4);
        num.push_back(2);
        num.push_back(0);
        num.push_back(2);
        num.push_back(3);
        num.push_back(2);
        num.push_back(0);


/*
        num.push_back(2);
        num.push_back(2);
        num.push_back(0);
        num.push_back(4);
        num.push_back(3);
        num.push_back(1);
        */

        /*
        num.push_back(6);
        num.push_back(5);
        num.push_back(3);
        */

        int i,j,k=-1,n=num.size();

        //find the firest index i such that num[i]<num[i+1]
        for(i=n-2;i>=0;i--)
        {
            if(num[i]<num[i+1]){
            k=i;
            break;
            }
        }
        //It means that Next permutation would be rounding of given permutation.
        if(k==-1)
        {
           i=0;j=n-1;
           while(i<j)
           {
              if(num[i]!=num[j])
              num[i]^=num[j]^=num[i]^=num[j];
              i++;
              j--;
            }
        }
        else
        {

         //Find the index j between i and n
         //such that num[i]<num[j]. from the right side start scanning..
            i=k;
            for(j=k+1;j<n;j++)
            {
              if(num[j]>num[i])
              k=j;
            }

            //Swap the num[i] and found num[j] from the abve loop.
            num[i]^=num[k]^=num[i]^=num[k];

            //sort the every element from the i to n
            //in increasing order.
            //The given sequence will be the shortest next lexicographically sequence of given permutation.
            for(j=i+1;j<n;j++)
            {
               for(k=j+1;k<n;k++)
               {
                  if(num[j]>num[k])
                  num[k]^=num[j]^=num[k]^=num[j];
                }
            }
        }


        printf("\nPrint the array..\n");
        for(i=0;i<n;i++)
        printf("%d ",num[i]);
}

/**
Rotate n*n matrix by 90 degree. By using extra space..
*/
void rotateImage90()
{
    int a[2][3]={
        1,2,3,
        4,5,6};
    //    7,8,9
     //   };


    int m=2,n=3,i,j,k;
    //vector< vector<int> > b(n,vector<int>(n));
    printf("\nbefore rotation..\n");
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }

    vector< vector<int> > b(n,vector<int>(m));
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                b[j][m-1-i]=a[i][j];
            }
        }
     //   for(i=0;i<n;i++)
     //       for(j=0;j<n;j++)
     //       a[i][j]=b[i][j];

    printf("\nAfter rtation..\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
        printf("%d ",b[i][j]);
        printf("\n");
    }
}

/**
Rotate n*n matrix by clockwise. 90 degree. By using extra space..
*/
void inplaceRotate90()
{
        int a[][3]={
        1,2,3,
        4,5,6,
        7,8,9
        };

    int n=3,i,j,k;
    //vector< vector<int> > b(n,vector<int>(n));
    printf("\nbefore rotation..\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
    printf("\ninplace tranform the matrix..\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<i;j++)
        {
            if(a[i][j]!=a[j][i])
            a[i][j]^=a[j][i]^=a[i][j]^=a[j][i];
        }
    }

    printf("\nPrint after tranform\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
    i=0;j=n-1;
    while(i<j)
    {
        for(k=0;k<n;k++)
        {
         if(a[k][i]!=a[k][j])
         a[k][i]^=a[k][j]^=a[k][i]^=a[k][j];
        }
        i++;j--;
    }
    printf("\nPrint after 90 degree rotatinon\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }
  //  printf("\n");
 //   rotateImage90();
}

/**
Finding the ladder length..
*/
int ladderLengthBFS(string &start,string &end,set<string> &dict)
{
    //cout<<"start:"<<start<<" end:"<<end<<endl;
    int i,j,k,len=0,minlen=99999999;
    //vector< vector<string> > ans;
    int ans=0;
    vector<string> vt;
    queue<string> q1,q2;
    set<string> st;
    int sl,el;
    sl=start.size();
    el=end.size();
    if(start.compare(end)==0) return ans;
    q1.push(start);
    st.insert(start);
    vt.push_back(start);
    while(!q1.empty()||!q2.empty())
    {
      if(!q1.empty())
      {
        len++;
       // printf("\n****len:%d",len);
        while(!q1.empty())
        {
            string s=q1.front();
            q1.pop();
            for(i=0;i<s.size();i++)
            {
                char c=s[i];
                for(j=0;j<26;j++)
                {
                    if(c!='a'+j)
                    {

                        s[i]='a'+j;
                     //    cout<<endl<<"*****str:"<<s;
                        if(s.compare(end)==0)
                        {
                            return len+1;
                        }
                        if(dict.find(s)!=dict.end())
                        {
                            if(st.find(s)==st.end())
                            {
                                q2.push(s);
                                st.insert(s);
                                //printf("\n***found..");
                                //cout<<endl<<"***found:"<<s;
                            }
                        }
                        s[i]=c;
                    }
                }
              }
         }
      }
        else
        {
            len++;
           // printf("\n###len:%d",len);
            while(!q2.empty())
            {
                string s=q2.front();
                q2.pop();
                for(i=0;i<s.size();i++)
                {
                    char c=s[i];
                    for(j=0;j<26;j++)
                    {
                        if(c!='a'+j)
                        {
                            s[i]='a'+j;
                          //  cout<<endl<<"#### str:"<<s;
                            if(s.compare(end)==0)
                            {
                              return len+1;
                            }
                            if(dict.find(s)!=dict.end())
                            {
                                if(st.find(s)==st.end())
                                {
                                    q1.push(s);
                                    st.insert(s);
                                    //cout<<endl<<"####found:"<<s;
                                }
                            }
                            s[i]=c;
                        }
                    }
                }
            }
        }
    }
    return ans;
}
//It gives the trasfrmation sequences.
void ladderLengthDFS(vector< vector<string> > &ans,vector<string> vt,string start,string &end,
set<string>dict,int &length,int index)
{

            if(length!=-1&&index>=length)
            return ;
            string s=start;
            vt.push_back(s);
            for(int i=0;i<s.size();i++)
            {
                char c=s[i];
                for(int j=0;j<26;j++)
                {
                    if(c!='a'+j)
                    {

                        s[i]='a'+j;
                     //    cout<<endl<<"*****str:"<<s;
                        if(s.compare(end)==0)
                        {
                            if(length==-1)
                            length=index-1;
                            vt.push_back(end);
                            ans.push_back(vt);
                            return ;
                        }
                        if(dict.find(s)!=dict.end())
                        {
                            ladderLengthDFS(ans,vt,s,end,dict,length,index+1);
                        }
                      }
                        s[i]=c;
                    }
                }
}

void  ladderLength()
{
    vector< vector<string> > ans;
    vector<string> vt;
    string start("hit");
    string end("cog");
    set<string> dict;
    dict.insert("hot");
    dict.insert("dot");
    dict.insert("dog");
    dict.insert("lot");
    dict.insert("log");
    int len=-1;
   // int len=ladderLengthBFS(start,end,dict);
    printf("\n print the vector..\n");
    ladderLengthDFS(ans,vt,start,end,dict,len,1);
    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        cout<<ans[i][j]<<" ";
        cout<<endl;
    }
}

/**
Check palindrom Number..
NOTE: In this prblem negative Nos are not considered as pelindrom.
*/
bool palin(unsigned int x,unsigned int &b)
{
        bool  ans;
        if(x<10)
        {
            ans=(b%10==x%10);
            (b=b/10);
            return ans;
        }
        ans=palin(x/10,b);
        ans=ans&&(b%10==x%10);
        (b=b/10);
        return ans;
}

void isPalindrome()
{
    int x=-2147447412;
    unsigned int b=abs(x);
    if(palin(abs(x),b))
        printf("\nNO is pelindrmm..\n");
    else
        printf("\nNo is not pelindrm..");
}

/**
Get kTh permutation of string.
*/
void kThPermutation(string &str,int n,int index,vector<string> &vt)
{
    if(index==n)
    {
        vt.push_back(str);
        return ;
    }
    for(int i=index;i<n;i++)
    {
       if(i!=index&&str[i]==str[index]) continue;
       if(str[i]!=str[index])
       str[i]^=str[index]^=str[i]^=str[index];
       kThPermutation(str,n,index+1,vt);
       if(str[i]!=str[index])
       str[i]^=str[index]^=str[i]^=str[index];
    }
}

void getPermutation()
{
        int i,j;
        int n=3,k=6,noPermutation=0;
        string str;
        for(i=1;i<=n;i++)
        str.push_back('0'+i);
        vector<string> vt;
        kThPermutation(str,n,0,vt);
        sort(vt.begin(),vt.end());
        if(k-1<vt.size())
            cout<<"\nans:"<<vt[k-1];
        else
            cout<<"\n Not present";
}

/**
Start of the main function..
*/
int main()
{
    printf("\nsimple progamm..");
   // arrangThreeParts();
   // arrangTwoParts();
   //maximumInBitonicSequence();
   //findMinimumElement();
   // stringMatch();
   //lengestSeubsequence();
   // editdistance();
   //maximumSumOfElementsNoTwoConsecutive();
   // findSmallestMissInteger();
   // findFindMedianofArray();
   // sortByFrequency();

   //   for(int i=1;i<16;i++)
   //   sqrtOfNo();

   //int a[]={2,1};
   //firstMissingPositive(a,2);
   //generateParenthesis(2);
   //spiral(4);
   //largestRectangleArea();
   // maxPoints();
   //removeDuplicates();
   //removeInstanceFromArrayInplace();
   //subsets();
   //permute();
   //combinationSum();
   //exist();
   //poww(1.00000, 214748364);
   //nextPermutation();
    rotateImage90();
   //inplaceRotate90();
   //ladderLength();
   //isPalindrome();
   getPermutation();

    return 0;
}
