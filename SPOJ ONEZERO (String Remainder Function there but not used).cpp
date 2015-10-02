#include <bits/stdc++.h>
#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long int LL;

#define iter(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define REP(p,a,b) for(int p=a;p<=b;p++)

int stringremainder(char *s,int y)
{
	int modulus=0;
	for(int i=0;i<strlen(s);i++)
	{
		int x=(int)(s[i]-'0');
		modulus=(modulus*10+x)%y;
	}
	return modulus;
}

int visited[20000];
struct node
{
	string number;
	int modulus;
};


	void BFS(int s)
	{
		list<struct node> q;
		node temp;
		temp.number='1';
		temp.modulus=1%s;
		visited[temp.modulus]=1;
		q.push_back(temp);
		while(!q.empty())
		{
			node temp1=q.front();
			if(temp1.modulus==0)
			{
				//printf("%s\n",temp1.number);
				cout<<temp1.number<<endl;
				break;
			}
			q.pop_front();
			visited[temp1.modulus]=1;
			node temp2,temp3;
			temp2.number=temp1.number;
			temp3.number=temp1.number;
			temp2.number+='0';
			temp3.number+='1';
			int x;
			x=(temp1.modulus*10)%s;
			temp2.modulus=x;
			if(visited[x]==0)
			q.push_back(temp2);
			x=(temp1.modulus*10+1)%s;
			temp3.modulus=x;
			if(visited[x]==0)
			q.push_back(temp3);
			
		}
	}
	
	
int main() {
	int t;
	scanf("%d",&t);
	while(t--)
	{
		for(int i=0;i<20000;i++)visited[i]=0;
		int n;
		scanf("%d",&n);
		BFS(n);
	}
	return 0;
}