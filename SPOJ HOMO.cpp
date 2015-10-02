#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string.h>
#include <map>
using namespace std;

int main() {
	int t,homo=0,hetero=0;
	char s[7];
	long long int x;
	map<long long int,int> m;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s%lld",s,&x);
		if(strcmp(s,"insert")==0)
		{
			m[x]++;
			if(m[x]==2)
			homo++;
			else if(m[x]==1)
			hetero++;
		}
		else
		{
			if(m[x]>0)
			{
				m[x]--;
				if(m[x]==1)
				homo--;
				else if(m[x]==0)
				hetero--;
			}
		}
		if(homo>=1&&hetero>=2)
		printf("both\n");
		else if(homo>=1)
		printf("homo\n");
		else if(hetero>=2)
		printf("hetero\n");
		else printf("neither\n");
	}
	return 0;
}