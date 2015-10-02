#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,y,z;
	while(true)
	{
		scanf("%d%d%d",&x,&y,&z);
		if(x==0&&y==0&&z==0)break;
		if(abs(y-x)==abs(z-y))
		{
			int ans=z+(z-y);
			printf("AP %d\n",ans);
		}
		else
		{
			int ans=z*(z/y);
			printf("GP %d\n",ans);
		}
	}
	return 0;
}