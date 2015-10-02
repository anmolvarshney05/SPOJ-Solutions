#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,avg;
		scanf("%d%d",&x,&avg);
		long long int sum=avg*avg+avg-x*avg-x;
		long long int n=sum/(avg+1);
		long long int ans=sum-((n*(n-1))/2);
		printf("%lld\n",ans);
	}
	return 0;
}