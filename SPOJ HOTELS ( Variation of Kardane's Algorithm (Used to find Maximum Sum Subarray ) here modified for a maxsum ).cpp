#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int a[300002];
int main() {
		long long int maxsum=0,currentmax=0,m;
		int left=0,right=0,maxleft=0,maxright=0,n,j=0;
		scanf("%d%lld",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		for(int i=0;i<n;i++)
		{
			if(currentmax+(ll)(a[i])<m)
			currentmax+=a[i];
			else if(currentmax+(ll)(a[i])==m)
			{
				maxsum=currentmax+(ll)(a[i]);
				break;
			}
			else
			{
				ll temp=currentmax;
				while(temp+a[i]>m)
				{
					currentmax-=(ll)a[j];
					temp=currentmax;
					if(currentmax+(ll)a[i]<m)
					currentmax+=(ll)a[i];
					else if(currentmax+a[i]==m)
					{
						maxsum=currentmax+(ll)a[i];
						break;
					}
					j++;
				}
			}
			maxsum=max(maxsum,currentmax);
		}
		printf("%lld\n",maxsum);
	return 0;
}