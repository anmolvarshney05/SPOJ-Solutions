#include<bits/stdc++.h>
using namespace std;
long long int nCr[66][33];

long long int C( long long int x, long long int y)
{
	if(x==y)return 1;
	if(y==0) return 1;
	if(y==1) return (long long int)x;
	if(nCr[x][y]) return nCr[x][y];
	return nCr[x][y]=C(x-1,y)+C(x-1,y-1);
}
int main() {
	long long int dp[70];
	dp[0]=0;
	dp[1]=1;
	dp[2]=1;
	for(long long int i=3;i<=69;i++)
	{
		if(i&1)
		{
			dp[i]=dp[i-1];
		}
		else
		{
			dp[i]=dp[i-1]+C(i-1,i/2);
		}
	}
	long long int n;
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",dp[(int)(log2(n))]);
	}
	return 0;
}