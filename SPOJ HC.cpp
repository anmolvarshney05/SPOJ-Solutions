#include <iostream>
#include<cstdio>
#include<string.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int count=0;
		char s1[4];
		int n;
		scanf("%d",&n);
		char ch=getchar();
		for(int i=0;i<n;i++)
		{
			scanf("%s",s1);
			if(strcmp(s1,"lxh")==0)
			count++;
		}
		if(count&1)
		{
			printf("lxh\n");
		}
		else
		{
			printf("hhb\n");
		}
	}
	return 0;
}