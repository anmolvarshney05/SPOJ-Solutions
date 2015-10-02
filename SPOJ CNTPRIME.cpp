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

int seg[100001];
int lazy[100001];
int arr[100001];
static int check[1000001];
void generate()
{
	int i,j;
	for(i=0;i<1000001;i++)
	check[i]=1;
	for(i=2;i*i<1000001;i++)
	{
		if(check[i]==1)
		{
			for(j=i*2;j<1000001;j+=i)
			{
				check[j]=0;
			}
		}
	}
}

void build_tree(int node,int beg,int end)
{
    if(beg>end) return;
    if(beg==end)
    {
        if(check[arr[beg]]==1)
            seg[node]=1;
        else seg[node]=0;
        return;
    }
    build_tree(node*2,beg,(beg+end)/2);
    build_tree(1+2*node,(beg+end)/2 + 1,end);
    seg[node]=seg[node*2]+seg[1+2*node];
}

void update_tree(int node,int a,int b,int start,int end,int val)
{
    if(lazy[node]!=0)
    {
        if(check[lazy[node]]==1)
        {
            seg[node]=(b-a+1);
            if(a!=b)
            {
                lazy[node*2]=lazy[node];
                lazy[1+2*node]=lazy[node];
            }
        }
        else
        {
            seg[node]=0;
            if(a!=b)
            {
                lazy[node*2]=lazy[node];
                lazy[1+2*node]=lazy[node];
            }
        }
        lazy[node]=0;
    }
    if(a>b||a>end||b<start) return;

    if(a>=start&&b<=end)
    {
        if(check[val]==1)
        {
           seg[node]=(b-a+1);
           if(a!=b)
           {
               lazy[node*2]=val;
               lazy[1+2*node]=val;
           }
        }
        else
        {
            seg[node]=0;
            if(a!=b)
            {
               lazy[node*2]=val;
               lazy[1+2*node]=val;
            }
        }
     return;
    }
    update_tree(node*2,a,(a+b)/2,start,end,val);
    update_tree(1+2*node,1+(a+b)/2,b,start,end,val);
    seg[node]=seg[2*node]+seg[1+2*node];
}

int query_tree(int node,int a,int b,int begin,int end)
{
    if(lazy[node]!=0)
    {
        if(check[lazy[node]]==1)
        {
            seg[node]=(b-a+1);
            if(a!=b)
            {
                lazy[node*2]=lazy[node];
                lazy[1+2*node]=lazy[node];
            }
        }
        else
        {
            seg[node]=0;
            if(a!=b)
            {
                lazy[node*2]=lazy[node];
                lazy[1+2*node]=lazy[node];
            }
        }
        lazy[node]=0;
    }

    if(a>b||a>end||b<begin) return 0;
    if(a>=begin&&b<=end) return seg[node];
    int x=query_tree(node*2,a,(a+b)/2,begin,end);
    int y=query_tree(1+2*node,1+(a+b)/2,b,begin,end);
    return (x+y);
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t,n,q,i,x,y,z,w;
	scanf("%d",&t);
	generate();
	for(int count1=1;count1<=t;count1++)
	{
	    memset(lazy,0,sizeof(lazy));
	    memset(seg,0,sizeof(seg));
        scanf("%d%d",&n,&q);
        for(i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        build_tree(1,0,n-1);
        printf("Case %d:\n",count1);
        for(i=0;i<q;i++)
        {
            scanf("%d",&x);
            if(x==0)
            {
                scanf("%d%d%d",&y,&z,&w);
                y--;
                z--;
                update_tree(1,0,n-1,y,z,w);
            }
            else
            {
                scanf("%d%d",&y,&z);
                y--;
                z--;
                int ans=query_tree(1,0,n-1,y,z);
                printf("%d\n",ans);
            }
        }
    }
	return 0;
}
