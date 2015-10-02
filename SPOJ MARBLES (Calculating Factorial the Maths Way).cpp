#include <iostream>
#include<cstdio>
using namespace std;

long long int C(int x,int y)
{
	if(x==y)return 1;
	if(y==0) return 1;
	if(y==1) return (long long int)x;
	long long int ans=1;
	if(y>x-y)y=x-y;
	for(int i=0;i<y;i++)
	{
		ans=ans*(x-i)/(i+1);
	}
	return ans;
}

int main() {
	int t,n,k;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&k);
		printf("%lld\n",C(n-1,k-1));
	}
	return 0;
}