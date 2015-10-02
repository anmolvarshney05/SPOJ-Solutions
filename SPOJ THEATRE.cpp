/* Created by Anmol Varshney */

/*INCLUDE_HEADERS*/
#include<stdio.h>
#include<string.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
/*END HEADERS*/
using namespace std;
#define mod 1000000007
typedef long long int lld;
lld a[100001];
int main() {
	stack<lld> s;
	lld x,ans=1;
	s.push(0);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(int i=n-1;i>=0;i--)
	{
		if(a[i]>s.top())
		{
			while(!s.empty()&&a[i]>s.top())s.pop();
			if(s.empty())
			s.push(a[i]);
			else
			{
				ans=(ans*s.top())%mod;
				s.push(a[i]);
			}
		}
		else
		{
			ans=(ans*s.top())%mod;
			s.push(a[i]);
		}
	}
	ans=ans%mod;
	printf("%lld\n",ans);
	return 0;
}
