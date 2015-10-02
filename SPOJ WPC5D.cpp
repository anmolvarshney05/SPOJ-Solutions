#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
const LL M=1000000007;

LL power(LL a, LL b) {
	LL x = 1, y = a;
    while(b > 0) {
        if(b%2 == 1) {
            x=(x*y);
            if(x>M) x%=M;
        }
        y = (y*y);
        if(y>M) y%=M;
        b /= 2;
    }
    return x;
}


int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL temp=1,temp1=1,n,k;
		scanf("%lld%lld",&n,&k);
		temp=power(k,n-1);
		temp1=power(k-2,n-1);
		LL a=(temp+temp1)%M;
		LL d=(k-1)%M;
		a=(a*d)%M;
		LL b=power(2,M-2);
		LL ans=a*b;
		ans%=M;
		printf("%lld\n",ans);
	}
	return 0;
}