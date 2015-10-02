#include <bits/stdc++.h>
using namespace std;
const long long int mod=1000000000+7;
bool primes[50001];
int prime[50001];
int counter=0;
void sieve()
{
	memset(primes,false,sizeof(primes));
	for(int i=2;i<50001;i++)
	{
		if(!primes[i])
		{
			prime[counter++]=i;
			for(int j=i;j<50001;j+=i)
			primes[j]=true;
		}
	}
}

int power(int x,int y)
{
	int count=0;
	long long int z=y;
	while(x>=z)
	{
		count+=(x/z);
		z*=(long long int)y;
	}
	return count;
}

int main() {
	int t,n;
	sieve();
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		long long int ans=1;
		for(int i=0;i<counter;i++)
		{
			int powers=power(n,prime[i]);
			if(powers==0)break;
			ans=(ans*((long long int)(powers+1)))%mod;
		}
		ans=ans%mod;
		printf("%lld\n",ans);
	}
	return 0;
}