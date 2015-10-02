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
#define N 100001
#define MAX 4*N
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

int scan_d()    {int ip=getchar_unlocked(),ret=0,flag=1;for(;ip<'0'||ip>'9';ip=getchar_unlocked())if(ip=='-'){flag=-1;ip=getchar_unlocked();break;}for(;ip>='0'&&ip<='9';ip=getchar_unlocked())ret=ret*10+ip-'0';return flag*ret;}
void print_d(int n)     {if(n<0){n=-n;putchar('-');}int i=10;char output_buffer[10];do{output_buffer[--i]=(n%10)+'0';n/=10;}while(n);do{putchar(output_buffer[i]);}while(++i<10);}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    int n,u,i,x,y,z,t;
    while(t--)
    {
        n=scan_d();
        u=scan_d();
        int a[n+2];
        memset(a,0,sizeof(a));
        REP(i,0,u)
        {
            x=scan_d();
            y=scan_d();
            z=scan_d();
            hay[x]+=z;
            hay[y+1]-=z;
        }
        q=scan_d();
        REP(i,1,n)
        {
            hay[i]+=hay[i-1];
        }
        REP(i,0,q)
        {
           x=scan_d();
           print_d((hay[x]));
        }
    }
	return 0;
}
