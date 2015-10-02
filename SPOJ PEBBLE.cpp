#include <bits/stdc++.h>
using namespace std;
char s[1000001];
int main() {
	int counter=1;
	while(scanf("%s",s)!=EOF)
	{
		long int count=0;
		for(int i=0;s[i];i++)
		{
			if(count&1)
			{
				if(s[i]=='0')
				{
					count++;
				}
				else
				{
					continue;
				}
			}
			else
			{
				if(s[i]=='0')
				{
					continue;
				}
				else
				{
					count++;
				}
			}
		}
		printf("Game #%d: %ld\n",counter,count);
		counter++;
	}
	return 0;
}