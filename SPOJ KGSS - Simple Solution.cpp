#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long int m;
	long long int msum;
	
	void assignleaf(long long int x)
	{
		m=x;
		msum=0;
	}
	
	void merge(node& left,node& right)
	{
		if(left.m>right.m)
		{
			m=left.m;
		}
		else
		{
			m=right.m;
		}
	
		if(m==right.m)
		{
			if(left.m>right.msum)
			msum=left.m;
			else
			msum=right.msum;
		}
		else
		{
			if(right.m>left.msum)
			msum=right.m;
			else
			msum=left.msum;
		}
	}
		
		long long int getvalue()
		{
			return(m+msum);
		}
};

class stree
{
	public:
	int N;
	node* Node;
	stree(long long int a[],int n)
	{
		N=n;
		Node=new node[getSegmentTreeSize(n)];
		build_tree(a,0,n-1,1);
	}
	~stree()
	{
		delete[] Node;
	}
	void build_tree(long long int a[],int begin,int end,int index)
	{
		if(begin==end)
		{
			Node[index].assignleaf(a[begin]);
			return;
		}
		int mid=(begin+end)/2;
		build_tree(a,begin,mid,2*index);
		build_tree(a,mid+1,end,2*index+1);
		Node[index].merge(Node[2*index],Node[2*index+1]);
	}
	
	node query(int index,int begin,int end,int left,int right)
	{
		if(begin>end||begin>right||end<left)
		return ((node){0,0});
		if(begin>=left&&end<=right)
		{
			return Node[index];
		}
		int mid=(begin+end)/2;
		node leftchild=query(2*index,begin,mid,left,right);
		node rightchild=query(2*index+1,mid+1,end,left,right);
		node result;
		result.merge(leftchild,rightchild);
		return result;
	}
	void update(long long i,long long int j)
	{
		update_tree(1,0,N-1,i,j);
	}
	void update_tree(int index,int left,int right,long long int i,long long int value)
	{
		if(left==i&&right==i)
		{
			Node[index].m=value;
			Node[index].msum=0;
			return;
		}
		int mid=(left+right)/2;
		if(i>mid)
		update_tree(2*index+1,mid+1,right,i,value);
		if(i<=mid)
		update_tree(2*index,left,mid,i,value);
		Node[index].merge(Node[2*index],Node[2*index+1]);
	}
	long int getSegmentTreeSize(int N) 
	{
		long x=(long)(ceil(log2(N)));
		long max_size=2*(long)pow(2,x)-1;
		return max_size;
	}
	long long int getValue(int lo, int hi) 
	{
		node result = query(1, 0, N-1, lo, hi);
		return result.getvalue();
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,q,x,y;
	long long int x1,y1;
	char ch;
	cin>>n;
	long long int a[n];
	for(int i=0;i<n;i++)
	cin>>a[i];
	stree st(a,n);
	cin>>q;
	for(int i=0;i<q;i++)
	{
		cin>>ch;
		if(ch=='Q')
		{
			cin>>x>>y;
			cout<<st.getValue(x-1,y-1)<<endl;
		}
		else
		{
			cin>>x1>>y1;
			st.update(x1-1,y1);
		}
	}
	return 0;
}