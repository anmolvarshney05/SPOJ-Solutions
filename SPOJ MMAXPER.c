#include <stdio.h>
int max(int a,int b)
{
	return(a>=b?a:b);
}
int abs1(int x)
{
	if(x<0)return ((-1)*x);
	else return x;
}
int a[1000][2],dp[1000][2];
int main(void) {
	int n,i;
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%d%d",&a[i][0],&a[i][1]);
		if(i==0)
		{
			dp[i][0]=a[i][0];
			dp[i][1]=a[i][1];
		}
		else
		{
			dp[i][0]=max(dp[i-1][0]+abs1(a[i][1]-a[i-1][1])+a[i][0],dp[i-1][1]+abs1(a[i][1]-a[i-1][0])+a[i][0]);
			dp[i][1]=max(dp[i-1][0]+abs1(a[i-1][1]-a[i][0])+a[i][1],dp[i-1][1]+abs1(a[i][0]-a[i-1][0])+a[i][1]);
		}
		
	}
	printf("%d\n",max(dp[n-1][0],dp[n-1][1]));
	return 0;
}
