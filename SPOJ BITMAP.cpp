/* Created by Anmol Varshney */

#include <stdio.h>
#include <string.h>
//#include <unordered_map>
//#include <unordered_set>
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
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define INF_LL 9223372036854775807LL
#define PI acos(-1.0)
#define llu long long unsigned
#define ll long long int
#define ld long int
#define iter(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define REP(p,a,b) for(int p=a;p<b;p++)
#define REPR(p,a,b) for(int p=a;p>=b;p--)
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
#define CLR(x) memset(x,0,sizeof(x))
#define FAST_LOG2(x) (sizeof(unsigned long)*8 - 1 - __builtin_clzl((unsigned long)(x)))
#define IOS ios_base::sync_with_stdio(false)
#define citi cin.tie(NULL);
#define FREI(var) freopen(var,"r",stdin)
#define FREO(var) freopen(var,"w",stdout)
#define endl "\n"

/*ll C[101][101]; //Either C[n][r] (for First) or C[2][r] (for Second)

ll nCr(ll n,ll r)
{
    int mn=min(n-r,r);

    if(mn==0) return 1LL;
    if(mn==1) return n;

    if(C[n][mn]) return C[n][mn];

    C[n][r]=nCr(n-1,mn)+nCr(n-1,mn-1);

    return C[n][r];
}

ll nCr(ll n,ll r)
{
    C[0][0]=C[0][1]=1;
    for(ll i=2;i<=n;i++)
    {
        C[1][0]=1;
        C[1][i]=1;
        for(ll j=1;j<i;j++)
            C[1][j]=C[0][j]+C[0][j-1];
        for(ll j=0;j<=i;j++)
            C[0][j]=C[1][j];
    }
    return C[1][r];
}

ll fast_pow(ll a,ll b,ll M)
{
    ll res = 1;
    while ( b > 0 )
    {
        if ( b&1 ) res = (res*a)%M;
        a = (a*a)%M;
        b >>= 1;
    }
    return res;
}

ll FermatInverseModulo(ll b,ll modulo) // modulo is a prime number
{
    return (fast_pow(b,modulo-2,modulo));
}

void ExtendedEuclid(ll a,ll b,ll &x,ll &y) //Used for Diophantine Equations, Let g=gcd(a,b)
{                                          //If (X',Y') is solution for (a/g)X'+(b/g)Y'=1
    if(!b)                                 //Let X=(c/g)*X'
    {                                      //Let Y=(c/g)*Y'
        x=1;                               //Solution to ax+by=c where gcd(a,b) divides c is
        y=0;                               //x=X'+(b/g)t , y=Y'-(a/g)*t where t is any integer
        return;
    }
    ExtendedEuclid(b,a%b,x,y);
    ll temp=x;
    x=y;
    y=temp-(a/b)*y;
}

int InverseModuloEE(ll a,ll modulo)
{
    ll x,y;
    ExtendedEuclid(a,modulo,x,y);
    if(x<0) x+=modulo;
    return x;
}

ll ChineseMinX(ll num[],ll rem[],int n) //Elements in num[] should be pairwise relatively prime
{                                       //Otherwise solution exists only if
    ll product=1;                       //rem[i] is equivalent to rem[j] mod gcd(num[i],num[j])
                                        //In this case solutions are unique % lcm(num[0],num[1],...)
    REP(i,0,n)
        product*=num[i];

    ll res=0;

    REP(i,0,n)
    {
        ll p=product/num[i];
        res+=(rem[i]*InverseModuloEE(p,num[i])*p);
    }

    return (res%product); // All numbers are of the form res%product + k*(product)
}

string to_string(int num)
{
    stringstream ss;
    ss << num;
    return ss.str();
}

int gcd(int a,int b)
{
    if(b>a) return gcd(b,a);
    else if(b!=0) return gcd(b,a%b);
    else return a;
} */

string arr[182];
int a[182][182];
queue< pair<int,int> >q;

bool isValid(int x,int y,int R,int C)
{
    return (x>=0&&y>=0&&x<R&&y<C);
}

void solve(int R,int C)
{
    memset(a,-1,sizeof a);
    for(int i=0;i<R;i++)
    {
        for(int j=0;j<C;j++)
        {
            if(arr[i][j]=='1')
            {
                q.push(make_pair(i,j));
                a[i][j]=0;
            }
        }
    }

    int time=1;

    while(!q.empty())
    {
        int size=q.size();
        while(size--)
        {
            pair<int,int> p=q.front();
            q.pop();
            if(isValid(p.first-1,p.second,R,C)&&a[p.first-1][p.second]==-1)
            {
                q.push(make_pair(p.first-1,p.second));
                a[p.first-1][p.second]=time;
            }
            if(isValid(p.first+1,p.second,R,C)&&a[p.first+1][p.second]==-1)
            {
                q.push(make_pair(p.first+1,p.second));
                a[p.first+1][p.second]=time;
            }
            if(isValid(p.first,p.second-1,R,C)&&a[p.first][p.second-1]==-1)
            {
                q.push(make_pair(p.first,p.second-1));
                a[p.first][p.second-1]=time;
            }
            if(isValid(p.first,p.second+1,R,C)&&a[p.first][p.second+1]==-1)
            {
                q.push(make_pair(p.first,p.second+1));
                a[p.first][p.second+1]=time;
            }
        }
        time++;
    }
}

int main()
{
    //FREI("input.txt");
    //FREO("output.txt");
    IOS;
    citi;
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        REP(i,0,n)
            cin>>arr[i];
        solve(n,m);
        REP(i,0,n)
        {
            REP(j,0,m)
                cout<<a[i][j]<<" ";
            cout<<endl;
        }

    }
    return 0;
}
