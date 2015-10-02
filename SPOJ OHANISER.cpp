#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long int ans[100000];
int main() {
	ans[0]=1;
	long long int add=1,n;
	for(int i=1;i<100000;i++)
	{
		ans[i]=((ans[i-1]<<1)+add)%MOD;
		add=(add<<1)%MOD;
	}
	int t;
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		scanf("%lld",&n);
		printf("Case %d: %lld\n",i,ans[n-1]);
	}
	return 0;
}