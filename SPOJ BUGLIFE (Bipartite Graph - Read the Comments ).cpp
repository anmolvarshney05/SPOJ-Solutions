/*
SPOJ BUGLIFE (Bipartite Graph - All the nodes can be put into two sets and there is no connection
inside one set(only cross connection) ie "bi" and here we can say that one set is male and other
set is female and all males is connected to females only. 
*/
#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;

int flag=0;
int k=0;
vector<int> adj[2003];
int color[2003];
list<int> q;

int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		k++;
		flag=0;
		int v,e,a,b;
		scanf("%d%d",&v,&e);
		for(int i=1;i<=v;i++)
		{
			adj[i].clear();
		}
		q.clear();
		for(int i=0;i<e;i++)
		{
			scanf("%d%d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		for(int i=0;i<=2002;i++)color[i]=-1;
		for(int i=1;i<=v;i++)
		{
			if(color[i]==-1)
			{
				color[i]=1;
				q.push_back(i);
				vector<int>::iterator j;
				while(!q.empty())
				{
					int s=q.front();
					q.pop_front();
					for(j=adj[s].begin();j != adj[s].end();j++)
					{
						if(color[*j]==-1)
						{
							color[*j]=1-color[s];
							q.push_back(*j);
						}
						else if(color[*j]==color[s])
						{
							flag=1;
							break;
						}
					}
					if(flag==1)break;
				}
			}
			if(flag==1)break;
		}
		printf("Scenario #%d:\n",k);
		if(flag==1)
		{
			printf("Suspicious bugs found!\n");
		}
		else 
		{
			printf("No suspicious bugs found!\n");
		}
	}
	return 0;
}