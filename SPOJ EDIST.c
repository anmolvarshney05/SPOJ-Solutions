#include <stdio.h>
#include<string.h>
int min(int len1,int len2,int len3)
{
	return (len1<len2?(len1<len3?len1:len3):(len2<len3?len2:len3));
}
char ch,str1[2001],str2[2001];
int dp[2001][2001];
int main(void) {
	int t;
	
	scanf("%d",&t);
	int i,j,len1,len2,len3;
	ch=getchar();
	while(t--){
    scanf("%s",str1);
	scanf("%s",str2);
	int m=strlen(str1);
	int n=strlen(str2);
	//int dp[m+1][n+1];
	for(i=0;i<=m;i++)
	{
		dp[i][0]=i;
	}
	for(i=0;i<=n;i++)
	{
		dp[0][i]=i;
	}
	for(i=1;i<=m;i++)
	{
		for(j=1;j<=n;j++)
		{
			len1=(str1[i-1]==str2[j-1]?0:1)+dp[i-1][j-1];
			len2=dp[i][j-1]+1;
			len3=dp[i-1][j]+1;
			//printf("%d\t%d\t%d\t%d\n",len1,len2,len3,min(len1,len2,len3));
			dp[i][j]=min(len1,len2,len3);
		}
	}
	printf("%d\n",dp[m][n]);
	}	
	return 0;
}
