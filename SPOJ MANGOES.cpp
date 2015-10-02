#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int LL;
int main() {
	LL t,n;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		LL temp;
		if(n&1)
		temp=n/2;
		else
		temp=(n-1)/2;
		LL sum= temp*temp;
		sum=sum%n;
		printf("%lld\n",sum);
	}
	return 0;
}