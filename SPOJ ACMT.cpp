#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y,min1,max1,temp,count=0;
		scanf("%d%d",&x,&y);
		min1=min(x,y);
		max1=max(x,y);
		while(min1>0&&max1>1)
		{
			min1--;
			max1-=2;
			count++;
			temp=min1;
			min1=min(min1,max1);
			max1=max(temp,max1);
		}
		printf("%d\n",count);
	}
	return 0;
}