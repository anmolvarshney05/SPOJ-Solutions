#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const long long int mod=1000000007;
LL A[2][2]={{1,1},{1,0}};
void matrix_multiply(LL T[2][2],LL A[2][2])
{
	LL result[2][2];
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			result[i][j]=0;
			for(int k=0;k<2;k++)
			{
				result[i][j]=(result[i][j]+(T[i][k]*A[k][j])%mod)%mod;
			}
		}
	}
	for(int i=0;i<2;i++)
	{
		for(int j=0;j<2;j++)
		{
			T[i][j]=result[i][j];
		}
	}
}
void matrix_power(LL T[2][2],LL exponent)
{
	if(exponent==0||exponent==1)
	return;
	matrix_power(T,exponent>>1);
	matrix_multiply(T,T);
	if(exponent&1)
	matrix_multiply(T,A);
}
LL result(LL n)
{
	LL T[2][2]={{1,1},{1,0}};
	matrix_power(T,n);
	LL ans=(T[0][1]);
	ans=(ans-1+mod)%mod;
	return ans;
}
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL n,m,ans;
		scanf("%lld%lld",&n,&m);
		ans=(result(m+2)-result(n+1)+mod)%mod;
		printf("%lld\n",ans);
		
	}
	return 0;
}