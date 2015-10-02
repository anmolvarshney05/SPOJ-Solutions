#include <bits/stdc++.h>
using namespace std;
long long int a[100001];
int n,c;
int place(int x)
{
	int cowsplaced=1;
	long long int pos=a[0];
	for(int i=1;i<n;i++)
	{
		if(a[i]-pos>=x){cowsplaced++;pos=a[i];}
		if(cowsplaced==c)return 1;
	}
	return 0;
}
int bsearch()
{
	long long int start=0,mid;
	long long int end=a[n-1];
	while(start<end)
	{
		mid=(start+end)/2;
		if(place(mid)==0)end=mid;
		else start=mid+1;
	}
	return start-1;
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t,i;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		sort(a,a+n);
		cout<<bsearch()<<endl;
	}
	return 0;
}