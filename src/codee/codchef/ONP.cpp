/**
http://www.codechef.com/problems/ONP
*/
/**
3
(a+(b*c))
((a+b)*(z+x))
((a+t)*((b+(a+c))^(c+d)))

Output:
abc*+
ab+zx+*
at+bac++cd+^*
*/
#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>
#include <stack>
#include <map>
#include <cstring>
using namespace  std;
#define N 1000
#define M 1000000007

//Map for comparing the Operators.
map<char,int> mp;
char s[N];

//For getting the length of the string.
int strlenn(char *s)
{
	int i=0;
	while(s[i++]);
	return i-1; 
}

//For comparing the operators.
bool compare(char a,char b)
{
	return mp[a]<mp[b]; 
}

//For computing the postfix expression of the string.
vector<char> postfix(char *s,int n)
{
	int i,j,k;
	char a,b;
	i=0;
	stack<char> st;
	vector<char> vt;

	for(i=0;i<n;i++)
	{
		if(s[i]=='(')
			st.push(s[i]);
		else if(s[i]==')')
		{
			while(st.top()!='(')
			{
				a=st.top();
				st.pop();
				vt.push_back(a);
			}
			st.pop();
		}
		else if(s[i]=='-'||s[i]=='+'||s[i]=='*'||s[i]=='/'||s[i]=='^')
		{
			char a=s[i];
			while(compare(s[i],st.top()))
			{
				b=st.top();
				st.pop();
				vt.push_back(b);
			}
			st.push(a);
		}
		else
			vt.push_back(s[i]);

	}

	while(!st.empty())
	{
		a=st.top();
		st.pop();
		vt.push_back(a);
	}
	return vt;
}

//int main()
void driver()
{
	//initialise the map.
	mp['-']=1;
	mp['+']=1;
	mp['*']=2;
	mp['/']=2;
	mp['^']=3;

	int i,j,k,t,n;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",s);
		n=strlenn(s);
		vector<char> vt;
		vt=postfix(s,n);
		for(i=0;i<vt.size();i++)
			printf("%c",vt[i]);
		printf("\n");
	}


	//return 0;
}
