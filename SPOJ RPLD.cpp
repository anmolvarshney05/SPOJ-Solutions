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


int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int t,n,r,x,y;
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
    {
        int flag=0;
        vector < pair <int ,int > > p;
        scanf("%d%d",&n,&r);
        REP(i,0,r)
        {
            scanf("%d%d",&x,&y);
            p.pub(mkp(x,y));
        }
        sort(p.begin(),p.end());
        for(int i=0;i<p.size();i++)
        {
            if(p[i+1].second==p[i].second)
            {
                if(p[i+1].first==p[i].first)
                {
                    flag=1;
                    break;
                }
            }
        }
       if(flag)
       {
           printf("Scenario #%d: impossible\n",j);
       }
       else
       {
           printf("Scenario #%d: possible\n",j);
       }
    }
	return 0;
}
