#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	while(scanf("%d",&n)!=0&&n!=0)
	{
		long long int x,sum=0,cost=0;
		for(int i=0;i<n;i++)
		{
			cost+=abs(sum);
			scanf("%lld",&x);
			sum+=x;
		}
		printf("%lld\n",cost);
	}
	return 0;
}