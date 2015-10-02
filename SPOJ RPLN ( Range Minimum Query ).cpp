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
#define INF 1000000001
int tree[500001];
int arr[500001];

void build_tree(int node,int a,int b)
{
    if(a==b)
    {
        tree[node]=arr[a];
        return;
    }
    build_tree(node<<1,a,(a+b)>>1);
    build_tree(1+(node<<1),1+((a+b)>>1),b);
    tree[node]=tree[node<<1]<tree[1+(node<<1)]?tree[node<<1]:tree[1+(node<<1)];
}

int query(int node,int a,int b,int i,int j)
{
    if(a>b||b<i||a>j) return INF;
    if(a>=i&&b<=j) return tree[node];
    int x=query(node<<1,a,(a+b)>>1,i,j);
    int y=query(1+(node<<1),1+((a+b)>>1),b,i,j);
    if(x<y) return x;
    else return y;
}

int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t,n,q,x,y;
	scanf("%d",&t);
	for(int j=1;j<=t;j++)
    {
        memset(tree,0,sizeof(tree));
        scanf("%d%d",&n,&q);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        build_tree(1,0,n-1);
        printf("Scenario #%d:\n",j);
        for(int i=0;i<q;i++)
        {
            scanf("%d%d",&x,&y);
            x--;
            y--;
            int ans=query(1,0,n-1,x,y);
            printf("%d\n",ans);
        }
    }
	return 0;
}
