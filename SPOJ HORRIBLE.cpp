#include <bits/stdc++.h>
using namespace std;
int const MAXN = 100000 + 5;
struct node
{
	long long int sum;
	long long int number;
	long long int add;
	void assignleaf()
	{
		sum=0;
		number=1;
		add=0;
	}
	
	void merge(node& left,node& right)
	{
		add=0;
		number=left.number+right.number;
		sum=(left.add*left.number)+left.sum+(right.add*right.number)+right.sum;
	}
	
	void split(node& left,node& right)
	{
		if(add!=0)
		{
			sum+=number*add;
			left.add+=add;
			right.add+=add;
			add=0;
		}
	}
	
	long long int getvalue()
	{
		return(sum+(number*add));
	}
};
class stree
{
	public:
	long long int N;
	node *Node;
	stree(long long int n)
	{
		N=n;
		Node=new node[getSegmentTreeSize(n)];
		build_tree(0,n-1,1);
	}
	void build_tree(long long int begin,long long int end,long long int index)
	{
		if(begin==end)
		{
			Node[index].assignleaf();
			return;
		}
		long long int mid=(begin+end)/2;
		build_tree(begin,mid,2*index);
		build_tree(mid+1,end,2*index+1);
		Node[index].merge(Node[2*index],Node[2*index+1]);
	}
	
	node query(long long int index,long long int begin,long long int end,long long int left,long long int right)
	{
		if(begin>=left&&end<=right)
		{
			return Node[index];
		}
		long long int mid=(begin+end)/2;
		if(left>mid)
		{
			Node[index].split(Node[2*index],Node[2*index+1]);
			return query(2*index+1,mid+1,end,left,right);
		}
		if(right<=mid)
		{
			Node[index].split(Node[2*index],Node[2*index+1]);
			return query(2*index,begin,mid,left,right);
		}
		Node[index].split(Node[2*index],Node[2*index+1]);
		node leftchild=query(2*index,begin,mid,left,mid);
		node rightchild=query(2*index+1,mid+1,end,mid+1,right);
		node result;
		result.merge(leftchild,rightchild);
		return result;
	}
	void update(long long int i,long long int j,long long int val)
	{
		update_tree(1,0,N-1,i,j,val);
	}
	void update_tree(long long int index,long long int left,long long int right,long long int i,long long int j,long long int value)
	{
		if(left>=i&&right<=j)
		{
			Node[index].add+=value;
			return;
		}
		long long int mid=(left+right)/2;
		Node[index].split(Node[2*index],Node[2*index+1]);
		if(i>mid)
		{
			update_tree(2*index+1,mid+1,right,i,j,value);
		}
		else if(j<=mid)
		{
			update_tree(2*index,left,mid,i,j,value);
		}
		else
		{
			update_tree(2*index,left,mid,i,mid,value);
			update_tree(2*index+1,mid+1,right,mid+1,j,value);
		}
		Node[index].merge(Node[2*index],Node[2*index+1]);
	}
	long long int getSegmentTreeSize(int N) 
	{
		long long int x=(long)(ceil(log2(N)));
		long long int max_size=2*(long)pow(2,x)-1;
		return max_size;
	}
	long long int getValue(long long int lo, long long int hi) 
	{
		node result = query(1, 0, N-1, lo, hi);
		return result.getvalue();
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	long long int i,n,c,t,p,q,v;
	int ch;
	cin>>t;
	while(t--)
	{
		cin>>n>>c;
		stree st(n);
		for(i=0;i<c;i++)
		{
			cin>>ch>>p>>q;
			if(ch==0)
			{
				cin>>v;
				st.update(p-1,q-1,v);
			}
			else
			{
				cout<<st.getValue(p-1,q-1)<<endl;
			}
		}
	}
	return 0;
}