#include <bits/stdc++.h>
using namespace std;
int const MAXN = 50000 + 5;
struct node
{
	long long int leftsum;
	long long int rightsum;
	long long int rightleftsum;
	long long int maxsum;
	long long int sum;
	void assignleaf(long long int x)
	{
		leftsum=x;
		rightsum=x;
		rightleftsum=x;
		maxsum=x;
		sum=x;
	}
	
	void merge(node& left,node& right)
	{
		sum=left.sum+right.sum;
		leftsum=max(left.leftsum,left.sum+right.leftsum);
		rightsum=max(right.rightsum,right.sum+left.rightsum);
		rightleftsum=left.rightsum+right.leftsum;
		maxsum=max(right.maxsum,max(left.maxsum,max(sum,max(leftsum,max(rightsum,rightleftsum)))));
	}
	
	/*void split(node& left,node& right)
	{
		if(add!=0)
		{
			sum+=number*add;
			left.add+=add;
			right.add+=add;
			add=0;
		}
	}*/
	
	long long int getvalue()
	{
		return(maxsum);
	}
};
node Node[4*MAXN];
long long int a[MAXN];
class stree
{
	public:
	long long int N;
	stree(long long int arr[],long long int n)
	{
		N=n;
		build_tree(arr,0,n-1,1);
	}
	void build_tree(long long int arr[],long long int begin,long long int end,long long int index)
	{
		if(begin==end)
		{
			Node[index].assignleaf(arr[begin]);
			return;
		}
		long long int mid=(begin+end)/2;
		build_tree(arr,begin,mid,2*index);
		build_tree(arr,mid+1,end,2*index+1);
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
			//Node[index].split(Node[2*index],Node[2*index+1]);
			return query(2*index+1,mid+1,end,left,right);
		}
		if(right<=mid)
		{
			//Node[index].split(Node[2*index],Node[2*index+1]);
			return query(2*index,begin,mid,left,right);
		}
		//Node[index].split(Node[2*index],Node[2*index+1]);
		node leftchild=query(2*index,begin,mid,left,mid);
		node rightchild=query(2*index+1,mid+1,end,mid+1,right);
		node result;
		result.merge(leftchild,rightchild);
		return result;
	}
	/*void update(long long int i,long long int j,long long int val)
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
	}*/
	long long int getValue(long long int lo, long long int hi) 
	{
		node result = query(1, 0, N-1, lo, hi);
		return result.getvalue();
	}
};

int main() {
	long long int i,n,m,p,q;
		scanf("%lld",&n);
		for(i=0;i<n;i++)
		scanf("%lld",&a[i]);
		stree st(a,n);
		scanf("%lld",&m);
		for(i=0;i<m;i++)
		{
			scanf("%lld%lld",&p,&q);
			printf("%lld\n",st.getValue(p-1,q-1));
		}
	return 0;
}
