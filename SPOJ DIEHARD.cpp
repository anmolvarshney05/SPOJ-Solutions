#include <iostream>
#include <cstdio>
using namespace std;
typedef long long int LL;
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL x,y;
		scanf("%lld%lld",&x,&y);
		if(x==0||y==0)
		{	
			printf("0\n");
			continue;
		}
		LL count=1;
		x+=3;
		y+=2;
		while(true)
		{
			if(x>5&&y>10)
			{
				x-=2;
				y-=8;
				count+=2;
			}
			else if(x>20&&y<=10)
			{
				x-=17;
				y+=7;
				count+=2;
			}
			else
			{
				printf("%lld\n",count);
				break;
			}
		}
	}
	return 0;
}