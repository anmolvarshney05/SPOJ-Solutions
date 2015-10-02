#include <bits/stdc++.h>
using namespace std;
int i;
string s;
int depth()
{
	if(s[i++]=='l')return 1;
	else return (1+max(depth(),depth()));
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		i=0;
		cin>>s;
		cout<<(depth()-1)<<endl;
	}
	return 0;
}