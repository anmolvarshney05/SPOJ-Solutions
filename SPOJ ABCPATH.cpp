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

int gcd(int a,int b)
{
    if(b>a) return gcd(b,a);
    else if(b!=0) return (b,a%b);
    else return a;
}

char a[51][51];

static int x[]={0,1,1,1,0,-1,-1,-1};
static int y[]={1,1,0,-1,-1,-1,0,1};

int exist[51][51];
int ans[51][51];
map< pii ,int> vis;

int dfs(int i,int j,int r, int c)
{
    vis[mkp(i,j)]++;
    if(exist[i][j]!=-1) return ans[i][j];
    int temp=0;
    for(int l=0;l<8;l++)
    {
        if(i+x[l]>=0 && j+y[l]>=0 && i+x[l]<r && j+y[l]<c)
        {
            if(((char)(a[i][j]+1)==a[i+x[l]][j+y[l]])&&(vis[mkp(i+x[l],j+y[l])]<8))
            {
                temp=max(temp,dfs(i+x[l],j+y[l],r,c));
            }
        }
    }
    exist[i][j]=1;
    ans[i][j]=temp+1;
    return temp+1;
}

int main() {
    //freopen("input 1.in","r",stdin);
    //freopen("output.txt","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int r,c,t=0,ans;
    while(1)
    {
        cin>>r>>c;
        if(r==0&&c==0) break;
        t++;
        memset(exist,-1,sizeof(exist[0][0])*51*51);
        vis.clear();
        REP(i,0,r)
            cin>>a[i];
        ans=0;
        REP(i,0,r)
            REP(j,0,c)
                if(a[i][j]=='A')
                    ans=max(ans,dfs(i,j,r,c));
        cout<<"Case "<<t<<": "<<ans<<endl;
    }
    return 0;
}
