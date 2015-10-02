#include <bits/stdc++.h>
using namespace std;

int main() {
	long long int x;
	scanf("%lld",&x);
	while(x!=-1)
	{
		if(x&1)
		{
			x--;
			if(x%3==0)
			{
				x/=3;
				x=4*x+1;
				long long int s=(long long int)sqrt(x);
				if(s*s==x)
				{
					if(s&1) printf("Y\n");
					else printf("N\n");
				}
				else
				printf("N\n");
			}
			else printf("N\n");
		}
		else printf("N\n");
		scanf("%lld",&x);
	}
	return 0;
}