#include <bits/stdc++.h>
using namespace std;
long long int dp[5010];
char s[5010];
int main() {
	scanf("%s",s);
	while(strcmp(s,"0"))
	{
		int flag=0;
		memset(dp,0,sizeof(dp));
		dp[0]=1;
		if(strlen(s)<2)
		{	
			printf("%lld\n",dp[0]);
			scanf("%s",s);
			continue;
		}
		char ss[3];
		ss[0]=s[0];
		ss[1]=s[1];
		ss[2]='\0';
		int y=atoi(ss);
		if(s[1]=='0'&&y>26)
		{
			printf("0\n");
			scanf("%s",s);
			continue;
		}
		else if(s[1]=='0')
		{
			dp[1]=1;
		}
		else 
		{
			if(y<=26&&y>9)
			dp[1]=2;
			else
			dp[1]=1;
		}
		for(int i=2;i<strlen(s);i++)
		{
			char s1[3];
			s1[0]=s[i-1];
			s1[1]=s[i];
			s1[2]='\0';
			int x=atoi(s1);
			if(s[i]=='0'&&x>26)
			{
				flag=1;
				printf("0\n");
				break;
			}
			else if(s[i]=='0')
			{
				dp[i]=dp[i-2];
			}
			else
			{
				if(x<=26&&x>9)
				{
					dp[i]=dp[i-1]+dp[i-2];
				}
				else
				{
					dp[i]=dp[i-1];
				}
			}
		}
		if(flag!=1)
		printf("%lld\n",dp[strlen(s)-1]);
		scanf("%s",s);
	}
	return 0;
}