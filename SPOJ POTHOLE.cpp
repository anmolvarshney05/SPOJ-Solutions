/* Created by Anmol Varshney */

#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define INF 2000000000
#define INF_SMALL 10000
#define INF_LL 9223372036854775807LL
#define PI acos(-1.0)
#define llu long long unsigned
#define ll long long int
#define ld long int
#define iter(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define REP(p,a,b) for(int p=a;p<b;p++)
#define mod 1000000007
#define getchar_unlocked getchar
#define pb(f) push_back(f)
#define pob(f) pop_back(f)
#define pf(f) push_front(f)
#define pof(f) pop_front(f)
#define mkp(a,b) make_pair(a,b)
#define fst first
#define snd second
#define pii pair<int,int>
#define ins(a) insert(a)

#define v 210

bool visited[v];
int parent[v];
vector<int> adj[v];
int rescap[v][v]; //Residual Capacity. At first these are the original Capacities
int cap[v][v];

void initialize()
{
    REP(i,0,v)
        REP(j,0,v)
            rescap[i][j]=0,cap[i][j]=0;
    REP(i,0,v)
        adj[i].clear();
}

bool BFS(int ve,int s,int t) //Mixture of both BFS and Edmonds Karp
{
    memset(visited,false,sizeof(visited));
    memset(parent,-1,sizeof(parent));
    queue<int> q;
    q.push(s);
    visited[s]=true;
    parent[s]=-1;
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        if(temp==t)break;
        REP(i,1,ve+1) // We check every Vertex because edges keep on changing (Magnitude as well as Direction).
        {
            if(visited[i]==false && rescap[temp][i]>0)
            {
                q.push(i);
                parent[i]=temp;
                visited[i]=true;
            }
        }
    }
    for(int vertex=t;vertex>-1;vertex=parent[vertex])
    {
        int temp=parent[vertex];
        rescap[temp][vertex]--;  //Add/Subtract Original Capacities. Here 1.
        rescap[vertex][temp]++;
    }
    return (visited[t]==true);
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    int tests;
    scanf("%d",&tests);
    while(tests--)
    {
        initialize();
        int ve,n,e;
        scanf("%d",&ve);
        REP(i,0,ve-1)
        {
            scanf("%d",&n);
            REP(j,0,n)
            {
                scanf("%d",&e);
                adj[i+1].pb(e);
                rescap[i+1][e]=((i==0||e==ve)?1:INF_SMALL); //INF_SMALL because it is to be added to original Capacities.
            }
        }
        int cnt=0;
        while(BFS(ve,1,ve))cnt++; //We have to count how many people can be sent
                                  //i.e. how many times BFS can be applied.
        printf("%d\n",cnt);
    }
    return 0;
}
