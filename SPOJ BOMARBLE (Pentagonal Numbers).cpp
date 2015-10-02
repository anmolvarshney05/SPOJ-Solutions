#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	while(n!=0)
	{
		n++;
		long long int ans=(n * (3 * n - 1))/2;
		printf("%lld\n",ans);
		scanf("%d",&n);
	}
	return 0;
}