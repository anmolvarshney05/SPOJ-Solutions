/* Created by Anmol Varshney */

/*INCLUDE_HEADERS*/
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
/*END HEADERS*/
using namespace std;
/*START_MACROS*/
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define INF 2000000000
#define INF_LL 9223372036854775807LL
#define PI acos(-1.0)
#define llu long long unsigned
#define lld long long int
#define ld long int
#define iter(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define REP(p,a,b) for(int p=a;p<b;p++)
#define mod 1000000007
#define getchar_unlocked getchar
#define pi(c) printf("%d\n",c)
#define pwa(a,b) printf(#a,b)
#define pll(c) printf("%lld\n",c)
#define pc(c) printf("%c\n",c)
#define pf(c) printf("%f\n",c)
#define ps(x) printf("%s\n",&x)
#define pd(x) printf("%lf\n",x)
#define w(j) for(int f=0;f<j;f++)
#define si(f) scanf("%d",&f)
#define sc(f) scanf("%c",&f)
#define sll(f) scanf("%lld",&f)
#define ss(f) scanf("%s",f)
#define sf(f) scanf("%f",&f)
#define two(d) (1<<d)
#define twoL(X) (((lld)(1))<<(X))
#define ip(a,b) ((int)pow(a,b))
#define ic(a) (a-'0')
#define contain(S,X) (((S)&two(X))!=0)
#define containL(S,X) (((S)&twoL(X))!=0)
#define sof(da_type) sizeof(da_type)
/*STL DEFINITIONS*/
#define pub(f) push_back(f)
#define pob(f) pop_back(f)
#define puf(f) push_front(f)
#define pof(f) pop_front(f)
#define iv vector<int>
#define il list<int>
#define v(arg) vector<arg>
#define l(arg) list<arg>
#define ivit vector<int>::iterator
#define ilit list<int>::iterator
#define vit(arg) vector<arg>::iterator
#define lit(arg) list<arg>::iterator
#define cl() clear()
#define sz() size()
#define fd() find()
#define ft() front()
#define bk() back()
#define beg() begin()
#define ed() end()
#define asn(asrgument1,asrgument2) assign(asrgument1,asrgument2)
#define rz(size_argument) resize(size_argument)
#define mkp(a,b) make_pair(a,b)
#define fst first
#define snd second
/*END STL MACROS*/
/*END MACROS*/

#define edge pair <int,int>
#define maxV 1001
vector < pair <long long int,edge> > G;

struct subset
{
    int parent;
    int rank;
};

subset subsets[maxV];

void initialize(int V)
{
    G.clear();
    REP(i,0,V+1)
    {
        subsets[i].parent=i;
        subsets[i].rank=0;
    }
}

int find(int x)
{
    if(subsets[x].parent!=x)
    {
        subsets[x].parent=find(subsets[x].parent);
    }
    return subsets[x].parent;
}

void Union(int x,int y)
{
    int xroot=find(x);
    int yroot=find(y);

    if(subsets[xroot].rank>subsets[yroot].rank)
    {
        subsets[yroot].parent=xroot;
    }
    else if(subsets[xroot].rank<subsets[yroot].rank)
    {
        subsets[xroot].parent=yroot;
    }
    else
    {
        subsets[xroot].parent=yroot;
        subsets[yroot].rank++;
    }
}

int Kruskal(int V)
{
    sort(G.begin(),G.end());
    int e=1,i=0;
    long long int cost=0;
    while(e<V)
    {
        int xroot=find(G[i].snd.fst);
        int yroot=find(G[i].snd.snd);
        if(xroot!=yroot)
        {
            e++;
            cost+=G[i].fst;
            Union(xroot,yroot);
        }
        i++;
    }
    return cost;
}

int main() {
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    int t,v,e,a,b;
    long long int w,p;
    scanf("%d",&t);
    while(t--)
    {
	    scanf("%lld%d%d",&p,&v,&e);
	    initialize(v);
	    REP(i,0,e)
	    {
	        scanf("%d%d%d",&a,&b,&w);
	        G.push_back(pair<int,edge>(w*p,mkp(a,b)));
	    }
	    long long int ans=Kruskal(v);
	    printf("%lld\n",ans);
    }
	return 0;
}
