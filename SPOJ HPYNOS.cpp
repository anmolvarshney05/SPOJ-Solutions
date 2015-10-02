#include<iostream>
#include<cstdio>
#include<map>
using namespace std;
unsigned long long int count=0;
bool check(unsigned long long int x)
{
	if(x==1)return true;
	map<unsigned long long int,int> m;
	unsigned long long int temp=x;
	unsigned long long int sum=0;
	while(sum!=1)
	{
		sum=0;
		while(temp)
		{
			sum=sum+((temp%10)*(temp%10));
			temp/=10;
		}
		temp=sum;
		if(m[sum]==1)
		{
			return false;
		}
		m[sum]=1;
		count++;
	}
	return true;
}
int main() {
	long long int n;
	scanf("%lld",&n);
	if(check(n))
	printf("%lld\n",count);
	else
	printf("-1\n");
	return 0;
}