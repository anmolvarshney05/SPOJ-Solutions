#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cstring>
#include <climits>
#include <stdlib.h>
using namespace std;
#define REP(a,b) for(int i=a;i<=b;i++)
#define ITER(a) for(typeof(a.begin()) it=a.begin();it!=a.end();it++)
#define MAXV 100001
vector<int> adj[MAXV];
int dp[MAXV][2];
int visited[MAXV][2]={0};
int solve(int u,int taken,int parent)
{
    if(visited[u][taken]==1)
        return dp[u][taken];
    visited[u][taken]=1;
    int ans=0;
    ITER(adj[u])
    {
        if(*it!=parent)
        {
            if(taken==1)ans=ans+min(solve(*it,1,u),solve(*it,0,u));
            else ans=ans+solve(*it,1,u);
        }
    }
    ans=ans+taken;
    dp[u][taken]=ans;
    return ans;
}

int main()
{
    int n,a,b;
    while(scanf("%d",&n)==1)
    {
        REP(0,MAXV-1)
        {
            visited[i][0]=0;
            visited[i][1]=0;
        }
        REP(0,MAXV)adj[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        //int ans=1;
        //if(n!=1)
        int ans=min(solve(1,1,-1),solve(1,0,-1));
        printf("%d\n",ans);
    }
    return 0;
}
