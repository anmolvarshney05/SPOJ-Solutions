#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,flag=0,index;
		long int max=0;
		scanf("%d",&n);
		pair < long int , long int > p[n];
		for(int i=0;i<n;i++)
		{
			scanf("%ld%ld",&p[i].first,&p[i].second);
			if(p[i].first>max)
			{
				index=i;
				max=p[i].first;
			}
		}
		for(int i=0;i<n;i++)
		{
			if(index!=i)
			{
				if(p[i].second>=max)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag==0)printf("%d\n",index+1);
		else printf("-1\n");
	}
	return 0;
}