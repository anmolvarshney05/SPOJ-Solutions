#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;

bool isperfect(LL x)
{
	LL y=sqrt(x);
	return ( y*y==x );
}

bool isfibo(LL x)
{
	return isperfect(5*x*x+4)||isperfect(5*x*x-4);
}
int main() {
	int t,counter=1;
	scanf("%d",&t);
	while(t--)
	{
		LL n,m,sum1=1,sum=1;
		scanf("%lld%lld",&n,&m);
		for(LL i=2;i*i<=n;i++)
		{
			if(n%i==0)
			{
				if((n/i)==i)
				sum+=i;
				else sum+=i+(n/i);
			}
		}
		sum=sum%m;
		for(LL i=2;i*i<=sum;i++)
		{
			if(sum%i==0)
			{
				if((sum/i)==i)
				sum1++;
				else sum1+=2;
			}
		}
		if(isfibo(sum1))
		printf("Case #%d : YES.\n",counter);
		else
		printf("Case #%d : NO.\n",counter);
		counter++;
	}
	return 0;
}