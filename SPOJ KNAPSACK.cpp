#include <bits/stdc++.h>
using namespace std;

int main() {
	int n,i,x,y,size,j;
	pair<int,int>pf[2001];
	scanf("%d%d",&size,&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&x,&y);
		pf[i]=make_pair(x,y);
	}
	int dp[n+1][size+1];
	for(i=0;i<=n;i++)
	for(j=0;j<=size;j++)
	{
		dp[i][j]=0;
	}
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=size;j++)
		{
			if(pf[i-1].first<=j)
			{
				dp[i][j]=max(pf[i-1].second+dp[i-1][j-pf[i-1].first],dp[i-1][j]);
			}
			else 
			{
				dp[i][j]=dp[i-1][j];
			}
		}
	}
	int max1=dp[n][size];
	printf("%d",max1);
	return 0;
}