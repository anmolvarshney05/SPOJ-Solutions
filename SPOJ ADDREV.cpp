#include <bits/stdc++.h>
using namespace std;

int reverse(int x)
{
	int rever=0;
	while(x)
	{
		int temp=x%10;
		rever=rever*10+temp;
		x/=10;
	}
	return rever;
}
int adder(int x,int y)
{
	int a=reverse(x);
	int b=reverse(y);
	return(a+b);
}

int main() {
	int n,x,y;
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&x,&y);
		int add=adder(x,y);
		add=reverse(add);
		cout<<add<<endl;
	}
	return 0;
}