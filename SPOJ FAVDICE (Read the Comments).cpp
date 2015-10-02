/*
 ( Geometrically distributed Random Variable and E(X)=1/Probability for Geometrical Distribution )
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		double sum=0;
		scanf("%d",&n);
		int temp=n-1;
		for(int i=2;i<=n;i++)
		{
			sum+=n/(double)temp;
			temp--;
		}
		sum+=1;
		printf("%.2lf\n",sum);
	}
	return 0;
}