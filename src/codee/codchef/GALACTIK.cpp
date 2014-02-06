/**
http://www.codechef.com/problems/GALACTIK
*/

/**
DATA STRUCTURE :  IT REQUIRES THE DISJOINT-SET DATA STRUCTURE. 
				  SINCE INITIALLY THE INFORMATION ABOUT THE CONNECTING EDGES OF THE GRAPH IS GIVEN, WE WOULD FORM THE NO. OF
				  DIFFERENT JOINT COMPONENTS ON THE BASIS OF EDGE  INFORMATION OF THE GIVEN GRAPH THROUGH DISJOINT-SET DATA STRUCTURE.
				  IF AFTER FINDING THE ALL NO. OF DIFFERENT COMPONENTS:
				   AFTER  CALCULATING ALL THE COMPONENTS WE WOULD , WE WOULD CONSIDERING EACH COMPONENTS AS SINGLE VERTEX OF THE GRAPH
				   AND TRY TO CONNECT THEM WITH THE OTHER COMPONENT, CONSIDERD AS SINGLE VERTEX.
					SUPPOSE WE CALCULATE THE K-COMPONENTS, THEN FOR MAKING ALL THE COMPONENTS RECAHBLE , WE ONLY NEED TO ADD
						K-1 EDGES BETWEEN COMPONENTS. SINCE THERE ARE POSSIBLY C(K,2) EDGES POSSIBLE OUT OF WHICH WE ONLY NEED
						TO CONSIDER THE K-1 EDGES FOR MAKING THEM COMPLETLY CONNECTED.
						SO, WE WOULD USE  MINIMUM SPANNING TREE ANOLOGY FOR FINDING THE BEST K-1 EDGES FOR CONNECTING THEM.  
					1. IF IT'S SIGLE COMPONENT THEN THE ANSWER WOULD BE 1. BECAUSE ALL THE CITIES ARE CONNECTED HECCE WE DON'T
						NEED TO BUID ANY CONNECTION BETWEEN THEM, AND ANSWER WOULD BE ONE.
					2. IF ANY OF THE CALCUCALTED COMOPENTS ARE HAVING ONLY NEGATIVE- EDGES WITH THEM , THEN CONNECTION IS NOT POSSIBLE
						AND ANSWER WOULD BE -1.
					3. ELSE, WE WOULD CALULATE THE MINIMUM COST OF VERTEX OF EACH CONNECTED COMPOENT.
							AFTER THAT , WE WOULD FIND THE MINIMUM VERTEX AMONG ALL THE VERTEX COST, (I.E. AFTER FINDING THE MINIMUM AMONG 
							ALL THE VERTEX OF A PARTICULAR COMPONENT.)
						THEN , WE MAKE THE CONNECTION OF THIS VERTEX WITH ALL THE OTHER VERTEXES OF THE GRAPH, AND MAKE THE WHOLE
						GRAPH CONNECTED.
						ANS=COST[0]+COST[I]; WHERE 1<=I<N, VERTEX NO STARTING FROM 0. 

*/

/**
Input 1
6 6
1 2
2 3
1 3
4 5
5 6
4 6
1
3
5
2
4
6

Output 1
3


Input 2
3 1
2 3
1
-1
-1

Output 2
-1
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
#define N 100005
#define M 1000005
#define MAX 1000000007

int tax[N];

/**
CODE FOR HANDLING THE FIND AND JOIN OF DISJOINT SET DATA STRUCTURE.
*/
int rankk[N];
int par[N];

void init(int n)
{
	for(int i=0;i<n;i++)
	{
		par[i]=i;
		rankk[i]=1;
	}
}

int find(int u)
{
	if(par[u]==u) return par[u];
	else return par[u]=find(par[u]);
}

void merge(int u,int v)
{
	int pu,pv;
	pu=find(u);
	pv=find(v);
	if(pu!=pv)
	{
		if(rankk[pu]>rankk[pv]){
			par[v]=pu;
			rankk[pu]++;
		}
		else{
			par[u]=pv;
			rankk[pv]++;
		}
	}
}

//int main()
void driver()
{
	int i,j,k,t,n,m;
	scanf("%d%d",&n,&m);
	//initialise the comonents.
	init(n);

	set<int> no_components;
	map<int,int> mp;

	for(i=0;i<m;i++)
	{
		scanf("%d%d",&j,&k);
		j--;k--;
		merge(j,k);
	}

	//initialise the all elements of map.
	for(i=0;i<n;i++)
		mp[find(i)]=MAX;

	for(i=0;i<n;i++)
	{
		scanf("%d",&tax[i]);
		//ASSIGN THE COST VALUE AS MAXIMUM INTEGER OF MAKING THE UNIFORMATY FOR APPLYING THE ALGORITHM 
		mp[find(i)]=min(mp[find(i)],tax[i]<0?MAX:tax[i]);
	}

	//Now calculate, no of components.
	for(i=0;i<n;i++)
	{
		no_components.insert(find(i));
	}
	//IT MEANS THAT GARPH IS COMPLETELY CONNECTED AND WE DON'T NEED ADD ANY MORE EDGES TO THE GRAPH.
	if(no_components.size()==1)
	{
		printf("0\n");
	}
	else	//we need to go for further calculations.
	{
		//NOW CHECK IF ANY OF THE COMPONENT IS HAVING THE NEGATIVE 
		//I.E. IF AFTER CALCYLATING THE MINIMUM VERTEX COST OF EACH COMPONENT, WE ARE GETTING THE MAX INTEGER VALUE
		//I.E. HAVING ONLY THE NEGATIVE COST VALUE FOR EACH VERTEX THAT COMPONENT BELONG TO, IT MEANS THAT THERE 
		//DOESN'T EXITS ANY SOLUTION FOR THIS. BECAUSE THEY ARE NOT GOING TO CONNECT WITH VERTX HAVING NEGATIV EG=DGES.
		map<int,int>::iterator it;
		vector<int> minimumcost;
		for(it=mp.begin();it!=mp.end();it++)
		{
			if(it->second==MAX)
			{
				//NO SOULTION EXITS.
				printf("-1\n");

				return ;
				//return 0;
			}
			minimumcost.push_back(it->second);
		}

		//Now calculate the actual answer;
		//sort the minimumcost Vector in increasing order of costs.
		sort(minimumcost.begin(),minimumcost.end());
		int sum=0;
		
		for(i=1;i<minimumcost.size();i++)
		{
			sum+=minimumcost[0];
			sum+=minimumcost[i];
		}
		printf("\nAns:%d\n",sum);
	}

	//return 0;
}
