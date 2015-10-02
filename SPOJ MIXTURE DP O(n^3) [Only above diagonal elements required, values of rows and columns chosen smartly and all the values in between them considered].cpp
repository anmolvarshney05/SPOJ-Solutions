#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cstring>
#include <climits>
#include <stdlib.h>
using namespace std;
#define INF 10000000;
#define REP(a,b) for(int i=a;i<=b;i++)

int color[101];
int csum(int a,int b){
	int sum=0;
		for(int i=a-1;i<b;i++)
		{
			sum=(sum+color[i]);
			sum%=100;
		}
	return sum;
}
int main() {
	int n,l,j,k;
	while(scanf("%d",&n)!=-1)
	{
		int dp[n+1][n+1];
		REP(0,n-1)
		scanf("%d",&color[i]);
		for(j=0;j<=n;j++)
		{
			for(k=0;k<=n;k++)
			{
				dp[j][k]=INF;
			}
		}
		REP(0,n)
		dp[i][i]=0;
		for(j=1;j<n;j++)
		{
			for(k=1;k<=n-j;k++)
			{
				int m=k+j;
				for(l=k;l<m;l++)
				{
					int temp=(dp[k][l]+dp[l+1][m]+(csum(k,l)*csum(l+1,m)));
					if(temp<dp[k][m])
					{
						dp[k][m]=temp;
					}
				}
			}
		}
		printf("%d\n",dp[1][n]);
	}
	return 0;
}