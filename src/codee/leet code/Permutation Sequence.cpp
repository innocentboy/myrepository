/**
LINK:::http://oj.leetcode.com/problems/permutation-sequence/

he set [1,2,3,…,n] contains a total of n! unique permutations.

By listing and labeling all of the permutations in order,
We get the following sequence (ie, for n = 3):

Given n and k, return the kth permutation sequence.
*/
#include<cstdio>
#include<iostream>
#include<algorithm>
#include <vector>
#define N 100005
#define M 1005

using namespace std;

int fact(int n)
{
    int i=1;
    for(;n>0;n--)
    i=i*n;
    return i;
}

string getPermutation(int n, int k)
{
    int i,j,kk;
    vector<int> vt;
    int index[10];
    for(i=0;i<10;i++)
    index[i]=0;

    kk=k-1;
    for(i=n-1;i>0;i--)
    {
        j=fact(i);
        while(kk>=j)
        {
            index[i]++;
            kk-=j;
        }
    }

    for(i=0;i<n;i++) vt.push_back(i+1);
    string ans;
    for(i=n-1;i>=0;i--)
    {
        ans+=vt[index[i]]+'0';
        vt.erase(vt.begin()+index[i]);
    }
    return ans;
}

int main()
{
    int i,j,k;
    cout<<"ans: "<<getPermutation(3,4)<<endl;

    return 0;
}
