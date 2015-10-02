#include <bits/stdc++.h>
using namespace std;

int main() {
	int g,b;
	scanf("%d%d",&g,&b);
	while(g!=-1&&b!=-1)
	{
		int ans=ceil((double)max(g,b)/(min(g,b)+1));
		printf("%d\n",ans);
		scanf("%d%d",&g,&b);
	}
	return 0;
}