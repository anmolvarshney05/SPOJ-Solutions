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

typedef long long int lld;

lld C[61][61]={0};
lld generate(int n,int r)
{
	if(r > n){ C[n][r]=0; return 0; }
	if (n == r){ C[n][n]=1; return 1; }
	if (r == 0){ C[n][0]=1; return 1; }
	if (r == 1){ C[n][1]=n; return n; }
	if(C[n][r]) return C[n][r];
	C[n][r]=generate(n-1,r-1)+generate(n-1,r);
	return C[n][r];
}
int main() {
	int t,b,g,te;
	scanf("%d",&te);
	while(te--)
	{
		scanf("%d%d%d",&b,&g,&t);
		lld sum=0;
		for(int i=4;i<=(t-1);i++)
		{
			sum=sum+(generate(b,i)*generate(g,t-i));
		}
		printf("%lld\n",sum);
	}
	return 0;
}
