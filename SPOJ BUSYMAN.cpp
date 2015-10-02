//#include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<stack>
#include<stdio.h>
#include<math.h>
#include<string>
#include<stdlib.h>
using namespace std;
 
int main() {
	int t,n,i,x,y,count,flag;
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
	    count=1;
		scanf("%d",&n);
		pair < int ,int > v[n];
		for(i=0;i<n;i++)
		{
			scanf("%d%d",&x,&y);
			v[i]=make_pair(x,y);
		}
		sort(v,v+n);
		x=v[0].first;
		y=v[0].second;
		for(i=1;i<n;i++)
		{
			if(v[i].first<y) 
			{
				//x=v[i].first;
				if(v[i].second<=y){y=v[i].second;}
			}
			else 
			{
				count++;
				x=v[i].first;
				y=v[i].second;
			}
		}
		printf("%d\n",count);
	}
	return 0;
} 