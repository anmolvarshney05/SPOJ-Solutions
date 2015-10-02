#include <iostream>
#include <cstdio>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		if(((x-y)==0)||((x-y)==2))
		{
			if(x&1)
			{
				printf("%d\n",x+y-1);
			}
			else
			{
				printf("%d\n",x+y);
			}
		}
		else printf("No Number\n");
	}
	return 0;
}