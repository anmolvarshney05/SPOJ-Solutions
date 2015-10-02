#include <stdio.h>

int main(void) {
	int t;
	long long int sum=0;
	long long int n,i;
	scanf("%d",&t);
	while(t--)
	{
		sum=2;
		scanf("%lld",&n);
		sum=(n*(1+3*n))/2;
		sum=sum%1000007;
		printf("%lld\n",sum);
	}
	return 0;
}
