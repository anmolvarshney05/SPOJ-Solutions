#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int LL;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		LL n=(2*z)/(x+y);
		LL d=(y-x)/(n-5);
		LL a=x-2*d;
		printf("%lld\n",n);
		LL sum=a;
		for(LL i=0;i<n;i++)
		{
			LL ans=sum+i*d;
			printf("%lld ",ans);
		}
		printf("\n");
	}
	return 0;
}