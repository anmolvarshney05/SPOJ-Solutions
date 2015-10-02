#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	while(n)
	{
		char org[300];
		cin>>org;
		char s[(int)((strlen(org)/n))][n];
		int j=0,flag=0;
		for(int i=0;i<strlen(org);j++)
		{
			int k=i,count=0;
			while(count<n)
			{
				if(flag==0)
				{
					s[j][count]=org[i];
					i++;
					count++;
				}
				else
				{
					s[j][count]=org[k+n-count-1];
					i++;
					count++;
				}
			}
			flag^=1;
		}
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<(int)((strlen(org)/n));j++)
			{
				cout<<s[j][i];
			}
		}
		cout<<endl;
		cin>>n;
	}
	return 0;
}