#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
bool mem[9][82];
LL D[9][82];
int prms[29] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109};
bool isprime(long long int  x)
{
	if(x<0)
	return 0;
 
	for(int i=0;i<29;i++)
		if(prms[i]==x)
			return 1;
 
	return 0;
}
LL f(int digit,int sum)
{
	if(digit==0)return (sum==0);
	if(mem[digit][sum]) return D[digit][sum];
	mem[digit][sum]=true;
	LL ret = 0LL;
	for(int i=0;i<=9;i++)
	{
		ret+=f(digit-1,sum-i);
	}
	D[digit][sum]=ret;
	return ret;
}

LL solve(LL x)
{
	LL ret=0;
	char cad[10];
	sprintf(cad,"%lld",x);
	int len=strlen(cad);
	int qued=len;
	int sum=0;
	for(int i=0;i<len;i++)
	{
		qued--;
		int d=cad[i]-'0';
		for(int j=0;j<d;j++)
		{
			for(int l=0;l<=qued*9;l++)
			{
				int temp = sum+l+j;
				if(isprime(temp))
				ret+=f(qued,l);
			}
		}
		sum+=d;
	}
	return ret;
}

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		LL ans=solve(y+1)-solve(x);
		printf("%lld\n",ans);
	}
	return 0;
}