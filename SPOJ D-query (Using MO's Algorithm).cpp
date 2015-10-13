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
#define ins(a) insert(a)
#define N 30010
#define A 1000010
#define BLOCK 174
#define M 200010

int answer;
struct query
{
    int l,r,ind;
}Q[M];
int ans[M];
int a[N];
int cnt[A];

void add(int index)
{
    cnt[a[index]]++;
    if(cnt[a[index]]==1) answer++;
}

void remove(int index)
{
    cnt[a[index]]--;
    if(cnt[a[index]]==0) answer--;
}

bool cmp(query f,query s)
{
    if((f.l/BLOCK)!=(s.l/BLOCK))
        return (f.l/BLOCK)<(s.l/BLOCK);
    else
        return f.r<s.r;
}

int main() {
    ios_base::sync_with_stdio(false);
    int n,q;
    scanf("%d",&n);
    REP(i,0,n)
    {
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    REP(i,0,q)
    {
        scanf("%d%d",&Q[i].l,&Q[i].r);
        Q[i].ind=i;
        Q[i].l--;
        Q[i].r--;
    }
    sort(Q,Q+q,cmp);
    int cl=0,cr=0;
    REP(i,0,q)
    {
        int left=Q[i].l,right=Q[i].r;
        while(cl<left)
            remove(cl),cl++;
        while(cl>left)
            add(cl-1),cl--;
        while(cr<=right)
            add(cr),cr++;
        while(cr>(right+1))
            remove(cr-1),cr--;
        ans[Q[i].ind]=answer;
    }
    REP(i,0,q)
        printf("%d\n",ans[i]);
    return 0;
}
