#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	long long int i,n,ans1,max1,val;
	scanf("%d",&t);
	while(t--)
    {
    	scanf("%lld",&n);
    	map<long long int,long long int>v;
    	v.clear();
    	for(i=0;i<n;i++)
    	{
    		scanf("%lld",&val);
    		v[val]++;
    	}
    	max1=ans1=0;
    	for(typeof(v.begin()) it=v.begin();it!=v.end();it++)
    	{
    		if(max1<(it->second))
    		{
    			max1=it->second;
    			ans1=it->first;
    		}
    	}
    	printf("%lld\n",ans1);
    }
	return 0;
}