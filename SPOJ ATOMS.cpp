#include <bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		LL a,b,c;
		scanf("%lld%lld%lld",&a,&b,&c);
		if( c <= a )
        {
            printf("0\n");
            continue;
        }
		float x=log(c/a)/log(b);
		LL ans=(LL)x;
		printf("%lld\n",ans);
	}
	return 0;
}