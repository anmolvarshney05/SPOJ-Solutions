#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	while(n!=-1)
	{
		int a[n],sum=0;
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		int temp=sum/n;
		if(temp*n==sum)
		{
			sum=0;
			for(int i=0;i<n;i++)
			{
				if(a[i]<temp)sum+=(temp-a[i]);
			}
			printf("%d\n",sum);
		}
		else printf("-1\n");
		scanf("%d",&n);
	}
	return 0;
}