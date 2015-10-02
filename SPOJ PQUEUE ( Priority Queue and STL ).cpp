#include <bits/stdc++.h>
using namespace std;

int main() {
	int t,x,time;
	scanf("%d",&t);
	while(t--)
	{
		time=0;
		queue< pair<int,int> > q;
		priority_queue <int> pq; 
		int n,m;
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&x);
			q.push(make_pair(x,i));
			pq.push(x);
		}
		while(!q.empty())
		{
			int first=q.front().first;
			int second=q.front().second;
			q.pop();
			if(first!=pq.top())
			{
				q.push(make_pair(first,second));
			}
			else
			{
				time++;
				pq.pop();
				if(second==m)break;
			}
		}
		printf("%d\n",time);
	}
	return 0;
}