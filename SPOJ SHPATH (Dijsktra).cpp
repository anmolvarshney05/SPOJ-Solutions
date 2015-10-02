/* Created by Anmol Varshney */

#include<stdio.h>
#include<string.h>
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


#define maxV 100005

int dist[maxV];
vector<int> adj[maxV];
vector<int> w[maxV];
priority_queue< pii, vector< pii >, greater< pii > > p;
bool visited[maxV];

void initialize(int s,int v)
{
    memset(visited,false,sizeof(visited));
    REP(i,0,v)
        dist[i]=INT_MAX;
    dist[s]=0;
}

void relax(int s)
{
    REP(i,0,adj[s].size())
    {
        if(dist[adj[s][i]]>(dist[s]+w[s][i])&&!visited[adj[s][i]])
        {
            dist[adj[s][i]]=(dist[s]+w[s][i]);
            p.push(mkp(dist[adj[s][i]],adj[s][i]));
        }
    }
}

void dijsktra(int s)
{
    p.push(mkp(0,s));
    while(!p.empty())
    {
        int node=p.top().snd;
        p.pop();
        relax(node);
        visited[node]=true;
    }
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,n,k,a,b;
	char s[20],s1[20],s2[20];
	scanf("%d",&t);
	while(t--)
    {
        map<string,int> m;
        scanf("%d",&n);
        REP(i,0,n)
        {
            scanf("%s",s);
            m.insert(mkp(s,i));
            scanf("%d",&k);
            REP(j,0,k)
            {
                scanf("%d%d",&a,&b);
                adj[i].pb(a-1);
                w[i].pb(b);
            }
        }
        scanf("%d",&k);
        REP(i,0,k)
        {
            scanf("%s%s",s1,s2);
            initialize(m[s1],n);
            dijsktra(m[s1]);
            cout<<dist[m[s2]]<<endl;
        }
        REP(i,0,maxV)
        {
            adj[i].clear();
            w[i].clear();
        }
    }
	return 0;
}
