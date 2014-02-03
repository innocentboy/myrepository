/**
LINK:::http://en.wikipedia.org/wiki/Maximum_flow_problem
*/
/**
ALGORITHM: FORD-FOLKERSON.
            REQUIRED:
                        1. EACH EDGE CAPACITY SHOULD BE POSITIVE ALWAYS.
                        2. GRAPH SHOULD BE DIRECTED.
                        3. IF (U,V)->{E}  THEN (V,U) SHOULD NOT EXITS.(NO REVERSE EDGE.)
                        4.  IF C(U,V)=0, THEN THERE SHULD BE NO SHELF LOOP.

MAX FOLW-MIN CUT THEOREM:
                        IF f IS A FLOW IN NETWORK  G =(V,E) WITH SOURCE S AND SINK T THEN:-
                        1. f IS A MAXIMUM FLOW IN G IF,
                        2. RESIDUAL GRAPH G(f) HAVE NO AUGUMENTING PATH.
*/

/**
APPLICATIONS:
              1. Find maximum number of edge disjoint paths between two vertices
                  SOLU: ASSIGN UNIT CAPACITY TO EACH EDGE OF GRAPH, AND RUN THE FORD-FOLKERSON
                        ALGORITHMM FOR FINDING MAXIMUM FLOW BETWEEN SOURCE AND DESTINATION
                        VERTEX OF THE GRAPH. IN THE END OF THE ALGORITHM THE MAXIMUM NO
                        OF FLOW WOULD BE EQUAL TO THE nO. OF EDGE DISJOINT PATHS BETWEEN
                        SOURCE AND DESTINATION OF THE GRAPH.
*/

/**
INPUT:
4 0 3
0 3 2 0
0 0 3 2
0 0 0 4
0 0 0 0

6 0 5
0 16 13 0 0 0
0 0 0 12 0 0
0 4 0 0 14 0
0 0 9 0 0 20
0 0 0 7 0 4
0 0 0 0 0 0

OUTPUT:
5
24
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
#include <queue>
using namespace  std;
#define N 100
#define M 100
#define INF 1000000000
#define ull long long

int cap[N][N];
int flow[N][N];

/**
This methods provides the Ford-Fulkerson, implementation.
*/
int fordFolkerson(int n,int s,int t)
{
    int visited[N],maxFlow=0,botel=0;

    while(true)
    {
        //Find an augumenting path through BFS.
        for(int i=0;i<=n;i++)
            visited[i]=-1;
        visited[s]=-2;
        queue<int> q;
        q.push(s);
        while(!q.empty()&&visited[t]==-1)
        {
            int u=q.front();
            q.pop();
            for(int v=0;v<n;v++)
            {
                if(visited[v]==-1)
                {
                    //First check forward edge then chek bacword edge.
                    if(flow[u][v]||cap[u][v]>flow[v][u])
                    {
                        //Push that vertex for further investigation.
                        q.push(v);
                        visited[v]=u;
                    }
                }
            }
        }
        //No augumented path.
        if(visited[t]==-1)
            break;
        //else calculate the botlneck capacity.
        botel=INF;
        int u,v;
        //printf("\nprint path..\n");
        for(v=t,u=visited[v];u>=0;v=u,u=visited[v])
        {
            //printf("\ngettng the bottlenk:%d %d \n",u,v);
            if(flow[u][v])  //Always use farward edge over backward edge.
                botel=min(botel,flow[u][v]);
             else           //Must be bacward egde otherwise.
                botel=min(botel,flow[v][u]);
          //  printf("%d->",v);
        }
        //So update the max flw by the amount to the botelneck amount
        //that possibly we could send from s to t.
       // printf("\nbotel:%d\n",botel);
         maxFlow+=botel;

         //Update the flow Network..
        for(v=t,u=visited[v];u>=0;v=u,u=visited[v])
        {
            if(flow[u][v])      //for forward edge decrease the botleneck capacity for ensuring the
                                //remaining capacity..
                flow[u][v]-=botel;
            //In forward edge add.
                flow[v][u]+=botel;//Add the used capacity to bacward edge , so that this amount of
                                   //Flow could be pushed from the edge when it would be needed in future.
        }

    }
    return maxFlow;

    //No augumenting path will be same , during the calculation of the augumentation path.
    //All augumemntation path will be unique.
}

int main()
{
    int i,j,k,s,t,n;
    scanf("%d%d%d",&n,&s,&t);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
            scanf("%d",&cap[i][j]);
    }

    //Initialise the flow[][] for every vertex
    for(i=0;i<n;i++)
      for(j=0;j<n;j++)
        flow[i][j]=flow[j][i]=0;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            //reset the both one.
            if(cap[i][j])
            {
                flow[i][j]=cap[i][j];
                flow[j][i]=0;
            }
        }
    }
    //Now call the method.
    printf("\nAns:%d\n",fordFolkerson(n,s,t));

    return 0;
}
