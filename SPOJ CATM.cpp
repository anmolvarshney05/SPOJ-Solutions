#include <bits/stdc++.h>
using namespace std;
int main() {
	int x,y,k,a,b,c,d,e,f,dis1,dis2,dis3;
	scanf("%d%d%d",&x,&y,&k);
	for(int i=0;i<k;i++)
	{
		int flag=0;
		scanf("%d%d%d%d%d%d",&a,&b,&c,&d,&e,&f);
		for(int j=1;j<=y;j++)
		{
			dis1=abs(a-1)+abs(b-j);
			dis2=abs(c-1)+abs(d-j);
			dis3=abs(e-1)+abs(f-j);
			if(dis1<dis2&&dis1<dis3)
			{
				flag=1;
				break;
			}
		}
		if(flag!=1)
		{
			for(int j=1;j<=x;j++)
			{
				dis1=abs(a-j)+abs(b-y);
				dis2=abs(c-j)+abs(d-y);
				dis3=abs(e-j)+abs(f-y);
				if(dis1<dis2&&dis1<dis3)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag!=1)
		{
			for(int j=1;j<=y;j++)
			{
				dis1=abs(a-x)+abs(b-j);
				dis2=abs(c-x)+abs(d-j);
				dis3=abs(e-x)+abs(f-j);
				if(dis1<dis2&&dis1<dis3)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag!=1)
		{
			for(int j=1;j<=x;j++)
			{
				dis1=abs(a-j)+abs(b-1);
				dis2=abs(c-j)+abs(d-1);
				dis3=abs(e-j)+abs(f-1);
				if(dis1<dis2&&dis1<dis3)
				{
					flag=1;
					break;
				}
			}
		}
		if(flag!=1)printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}