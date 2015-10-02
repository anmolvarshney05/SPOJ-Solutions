#include <bits/stdc++.h>
using namespace std;
struct node
{
	long long int m;
	long long int msum;
	
	void assignleaf(long long int x)
	{
		msum=m=x;
	}
	
	void merge(node& left,node& right)
	{
		m=max(left.m,right.m);
		msum=max(left.msum,max(right.msum,left.m+right.m));
	}
	
	long long int getvalue()
	{
		return(msum);
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
		//if(begin>end||begin>right||end<left)
		//return ((node){0,0});
		int mid=(begin+end)/2;
		if(begin>=left&&end<=right)
		{
			return Node[index];
		}
		if(left>mid)
		{
			return query(2*index+1,mid+1,end,left,right);
		}
		if(right<=mid)
		{
			return query(2*index,begin,mid,left,right);
		}
		node leftchild=query(2*index,begin,mid,left,mid);
		node rightchild=query(2*index+1,mid+1,end,mid+1,right);
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
			Node[index].msum=value;
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