#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int initial,y,m,sum=0;
		scanf("%d%d%d",&initial,&y,&m);
		for(int i=0;i<m;i++)
		{
			int mode,charge;
			double rate;
			scanf("%d%lf%d",&mode,&rate,&charge);
			if(mode==0)
			{
				int interest=0;
				int amount=initial;
				for(int j=0;j<y;j++)
				{
					interest+=amount*rate;
					amount-=charge;
				}
				amount+=interest;
				sum=sum>amount?sum:amount;
			}
			else
			{
				int amount=initial;
				for(int j=0;j<y;j++)
				{
					int interest=amount*rate;
					amount=amount+interest-charge;
				}
				sum=sum>amount?sum:amount;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}