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
#define FAST_LOG2(x) (sizeof(unsigned long)*8 - 1 - __builtin_clzl((unsigned long)(x)))
#define IOS ios_base::sync_with_stdio(false)
#define citi cin.tie(NULL);
#define FREI(var) freopen(var,"r",stdin)
#define FREO(var) freopen(var,"w",stdout)
#define endl "\n"

int val[500],w[500],dp[2][2000000];

int main()
{
    int W,n;
    scanf("%d %d",&W,&n);

    for(int i=0;i<n;i++)
        scanf("%d %d",&val[i],&w[i]);

    dp[0][0]=dp[1][0]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=W;j++)
        {
            if(w[i-1]<=j)
                dp[(i&1)][j]=max(dp[!(i&1)][j],val[i-1]+dp[!(i&1)][j-w[i-1]]);
            else
                dp[(i&1)][j]=dp[!(i&1)][j];
        }
    }
    printf("%d\n",dp[n&1][W]);

    return 0;
}
