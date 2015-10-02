/* Created by Anmol Varshney */
/*
To count overlapping intervals, sort on the basis of upper limit of the interval. If other interval's starting value is greater than the maximum value of
upper interval then the interval lies outside and we increase count and also increase the max upper limit.
*/
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

int cmp(pair<lld,lld> a,pair<lld,lld> b)
{
    return a.second<b.second;
}
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
    {
        int n;
        lld x,y,count=0;
        vector < pair < lld, lld> > v;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%lld%lld",&x,&y);
            v.push_back(make_pair(x,y));
        }
        sort(v.begin(),v.end(),cmp);
        lld max=-1;
        for(int i=0;i<v.size();i++)
        {
            if(v[i].first>max)
            {
                count++;
                max=v[i].second;
            }
        }
        printf("%lld\n",count);
    }
	return 0;
}
