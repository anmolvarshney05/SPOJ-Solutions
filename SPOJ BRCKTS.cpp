#include <bits/stdc++.h>
using namespace std;
int const MAXN = 30009;
char s[MAXN];
int min( int a, int b)
 {
 	if(a<b)
 	return a;
 	else
 	return b;
 }
struct node
{
	int uopen;
	int uclose;
	void assignleaf(char ch)
	{
		if(ch=='(')
		{
			uopen=1;
			uclose=0;
		}
		else
		{
			uopen=0;
			uclose=1;
		}
	}
	
	void merge(node& left,node& right)
	{
		int match=min(left.uopen,right.uclose);
		uopen=left.uopen+right.uopen-match;
		uclose=left.uclose+right.uclose-match;
	}
	
	bool getvalue()
	{
		if(uopen==0&&uclose==0)
		return true;
		else return false;
	}
};
node Node[4*MAXN];
class stree
{
	public:
	int N;
	stree(int n)
	{
		N=n;
		build_tree(0,n-1,1);
	}
	void build_tree(int begin,int end,int index)
	{
		if(begin==end)
		{
			Node[index].assignleaf(s[begin]);
			return;
		}
		int mid=(begin+end)/2;
		build_tree(begin,mid,2*index);
		build_tree(mid+1,end,2*index+1);
		Node[index].merge(Node[2*index],Node[2*index+1]);
	}
	
	void update(int i)
	{
		update_tree(1,0,N-1,i);
	}
	void update_tree(int index,int left,int right,int i)
	{
		if(left==i&&right==i)
		{
			if(s[i]=='(')
			{
				s[i]=')';
			    Node[index].assignleaf(')');
			}
			else 
			{
				s[i]='(';
				Node[index].assignleaf('(');
			}
			return;
		}
		int mid=(left+right)/2;
		if(i>mid)
		{
			update_tree(2*index+1,mid+1,right,i);
		}
		else if(i<=mid)
		{
			update_tree(2*index,left,mid,i);
		}
		Node[index].merge(Node[2*index],Node[2*index+1]);
	}
	bool getValue() 
	{
		return Node[1].getvalue();
	}
};

int main() {
	char ch;
	int i,n,m,t,ele;
	t=1;
	while(scanf("%d",&n)==1&&n>0)
	{
		ch=getchar();
		scanf("%s",s);
		stree st(n);
		printf("Test %d:\n",t++);
		scanf("%d",&m);
		for(i=0;i<m;i++)
		{
			scanf("%d",&ele);
			if(ele==0)
			{
				if(st.getValue())printf("YES\n");
				else printf("NO\n");
			}
			else
			{
				ele--;
				st.update(ele);
			}
		}
	}
	return 0;
}