#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long int LL;

#define iter(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define REP(p,a,b) for(int p=a;p<=b;p++)
#define mod 1000000007

list<int> adj[100010];
set<int> visited;

	void DFS(int v)
	{
		visited.insert(v);
		set<int>::iterator s;
		iter(it,adj[v])
		{
			
			s=visited.find(*it);
			if(s==visited.end())
			{
				DFS(*it);
			}
		}
	}
	
	
int main() {
	
		int v,e,i,a,b;
		scanf("%d%d",&v,&e);
		int flag=0;
		REP(i,0,e-1)
		{
			scanf("%d%d",&a,&b);
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		if(e!=v-1)
		{
			printf("NO\n");
		}
		else flag=1;
		DFS(1);
		if(visited.size()==v&&flag==1)
		{
			cout<<"YES"<<endl;
		}
		else if(flag==1) 
		{
			cout<<"NO"<<endl;
		}
	
	return 0;
}