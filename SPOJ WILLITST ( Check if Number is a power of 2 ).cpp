#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

bool ispow2(LL x)
{
	return ( x && (!(x&(x-1))) );
}

int main() {
	LL x;
	scanf("%lld",&x);
	if(ispow2(x))
	printf("TAK\n");
	else
	printf("NIE\n");
	return 0;
}