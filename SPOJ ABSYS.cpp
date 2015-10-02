#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	char ch=getchar();
	while(t--)
	{
		int x,y,z;
		char a[200],b[2],c[200],d[2],e[200];
		scanf("%s%s%s%s%s",a,b,c,d,e);
		char ch1=getchar();
		if(strchr(a,'m')!=NULL)
		{
			 y=atoi(c);
			 z=atoi(e);
			 x=z-y;
		}
		else if(strchr(c,'m')!=NULL)
		{
			 x=atoi(a);
			 z=atoi(e);
			 y=z-x;
		}
		else if(strchr(e,'m')!=NULL)
		{
			 x=atoi(a);
			 y=atoi(c);
			 z=x+y;
		}
		printf("%d + %d = %d\n",x,y,z);
	}
	return 0;
}