#include <bits/stdc++.h>
using namespace std;
long long int dp[10001];
long long int a[10001];
int main() {
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		int n;
		scanf("%d",&n);
		if(n==0)
		{	
			printf("Case %d: 0\n",i);
			continue;
		}
		for(int j=0;j<n;j++)
		{
			scanf("%lld",&a[j]);
		}
		dp[0]=a[0];
		dp[1]=max(a[1],dp[0]);
		for(int j=2;j<n;j++)
		{
			dp[j]=max(a[j]+dp[j-2],dp[j-1]);
		}
		printf("Case %d: %lld\n",i,dp[n-1]);
	}
	return 0;
}