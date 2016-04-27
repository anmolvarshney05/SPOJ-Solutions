/* Created by Anmol Varshney */

#include <stdio.h>
#include <string.h>
#include <string>
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

ll gcd(ll a,ll b)
{
    if(b>a) return gcd(b,a);
    else if(b!=0) return gcd(b,a%b);
    else return a;
}

string to_string(ll num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

set<int> s;
int mark[101];

void foo()
{
    for(int i=2;i*i<=100;i++)
    {
        if(mark[i]==0)
        {
            for(int j=i*2;j<=100;j+=i)
                mark[j]=1;
        }
    }
    for(int i=2;i<=100;i++)
        if(mark[i]==0)
            s.ins(i);
}

ll dp[10][2][2][50][50];
int n;
string y;

ll f(int pos,bool smaller_or_not,bool nozero,int oddsum,int evensum)
{
    if(pos==n)
        return (s.find(evensum-oddsum)!=s.end());

    if(dp[pos][smaller_or_not][nozero][oddsum][evensum]>=0)
        return dp[pos][smaller_or_not][nozero][oddsum][evensum];

    ll res=0;
    bool newnozero;

    REP(i,0,10)
    {
        if(smaller_or_not||(i<=(int)(y[pos]-'0')))
        {
            newnozero=(nozero||i>0);
            if(newnozero)
            {
                if(!((n-pos-1)&1)) res+=f(pos+1,(smaller_or_not||(i<(int)(y[pos]-'0'))),true,oddsum+i,evensum);
                else res+=f(pos+1,(smaller_or_not||(i<(int)(y[pos]-'0'))),true,oddsum,evensum+i);
            }
            else
            {
                res+=f(pos+1,(smaller_or_not||(i<(int)(y[pos]-'0'))),false,oddsum,evensum);
            }
        }
    }
    dp[pos][smaller_or_not][nozero][oddsum][evensum]=res;
    return res;
}

int main() {
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t,a,b;
    ll ans;
    cin>>t;
    foo();
    while(t--)
    {
        ans=0;
        cin>>a>>b;
        a--;
        if(b>0)
        {
            y=to_string(b);
            n=y.size();
            memset(dp,-1,sizeof dp);
            ans=f(0,false,false,0,0);
        }
        if(a>0)
        {
            y=to_string(a);
            n=y.size();
            memset(dp,-1,sizeof dp);
            ans-=f(0,false,false,0,0);
        }
        cout<<ans<<endl;
    }
    return 0;
}
