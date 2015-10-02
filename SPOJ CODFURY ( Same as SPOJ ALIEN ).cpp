#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
typedef long long int ll;
int a[50001];
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,p=0,steps=0,minsteps=0;
		ll b,sum=0,minpeople=1000001;
		scanf("%d%lld",&n,&b);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			if(sum+a[i]<=b)
			{
				sum+=a[i];
				steps++;
			}
			else
			{
				sum+=a[i];
				steps++;
				while(sum>b)
				{
					sum-=a[p];
					steps--;
					p++;
				}
			}
			if(minsteps<steps)
			{
				minsteps=steps;
				minpeople=sum;
			}
			else if(minsteps==steps)
			{
				if(minpeople>sum)
				{
					minpeople=sum;
				}
			}
		}
		printf("%lld %d\n",minpeople,minsteps);
	}
	return 0;
}