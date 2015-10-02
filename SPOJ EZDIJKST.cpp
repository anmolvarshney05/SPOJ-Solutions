#include<bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;
 
typedef long long int LL;
 
#define iter(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define REP(p,a,b) for(int p=a;p<=b;p++)
#define mod 1000000007

struct node
{
	int pre,dist;
}node[100001];

struct cmp
{
	bool operator()(const pair<int,int> &lhs,const pair<int,int> &rhs)
	{
		return lhs.second>rhs.second;
	}
};
priority_queue<pair<int,int>,vector< pair<int,int> >,cmp> q;
vector<int> adj[100001];
vector<int> w[100001];

void relax(int s)
{
	for(int i=0;i<adj[s].size();i++)
	{
		if(node[adj[s][i]].dist>(node[s].dist+w[s][i]))
		{
			node[adj[s][i]].dist=(node[s].dist+w[s][i]);
			node[adj[s][i]].pre=s;
			q.push(make_pair(adj[s][i],node[adj[s][i]].dist));
		}
	}
}

void intialize(int s,int v)
{
	for(int i=1;i<=v;i++)
	{
		node[i].pre=-1;
		node[i].dist=INT_MAX;
	}
	node[s].dist=0;
}

void dijsktra(int s,int v)
{
	
	intialize(s,v);
	/*for(int i=1;i<=v;i++)
	{
		q.push(make_pair(i,node[i].dist));
	}*/
	q.push(make_pair(s,0));
	while(!q.empty())
	{
		int one=q.top().first;
		int two=q.top().second;
		q.pop();
		relax(one);
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int v,e,t,a,b,weight;
	cin>>t;
	while(t--)
	{
		cin>>v>>e;
		for(int i=0;i<=v;i++)
		{
			adj[i].clear();
			w[i].clear();
		}
		for(int i=0;i<e;i++)
		{
			cin>>a>>b>>weight;
			adj[a].push_back(b);
			w[a].push_back(weight);
		}
		/*for(int i=1;i<=v;i++)
		{
			cout<<i<<" ";
			for(int j=0;j<adj[i].size();j++)
			{
				cout<<adj[i][j]<<" "<<w[i][j]<<endl;
			}
			cout<<endl;
		}*/
		int s,d;
		cin>>s>>d;
		dijsktra(s,v);
		if(node[d].dist!=INT_MAX)
		cout<<node[d].dist<<endl;
		else 
		cout<<"NO"<<endl;
	}
	return 0;
}