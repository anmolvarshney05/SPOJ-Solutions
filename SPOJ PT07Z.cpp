#include <bits/stdc++.h>
using namespace std;

vector<int> v[10001];
int temp=0,d=0;
int visited[10001]={0};
void bfs(int e)
{
    queue<int> q;
    q.push(e);
    visited[e]=1;
    q.push(-1);
    while(q.size()!=1)
    {
        temp=q.front();
        q.pop();
        if(temp==-1)
        {
            q.push(-1);
        }
        else
        {
            visited[temp]=1;
            for(int i=0;i<v[temp].size();i++)
            {
                if(visited[v[temp][i]]==0)
                    {
                        q.push(v[temp][i]);
                    }
            }
        }
    }
}
void bfs1(int e)
{
    queue<int> q1;
    q1.push(e);
    visited[e]=1;
    q1.push(-1);
    while(q1.size()!=1)
    {
        int temp1=q1.front();
        q1.pop();
        if(temp1==-1)
        {
            d++;
            q1.push(-1);
        }
        else{
            	visited[temp1]=1;
            	for(int i=0;i<v[temp1].size();i++)
            		{
                		if(visited[v[temp1][i]]==0)
                			q1.push(v[temp1][i]);
        		    }
        	}
    }
}

int main()
{
    int x,a,b;
    scanf("%d",&x);
    for(int i=0;i<x-1;i++)
    {
        scanf("%d%d",&a,&b);
        v[a].push_back(b);
        v[b].push_back(a);
    }
    bfs(1);
    for(int i=0;i<=10000;i++)visited[i]=0;
    bfs1(temp);
    printf("%d\n",d);
    return 0;
}
