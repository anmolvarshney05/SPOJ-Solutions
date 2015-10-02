#include <bits/stdc++.h>
using namespace std;
struct node
{
	int number;
	int on;
	int toggle;
	void assignleaf()
	{
		number=1;
		on=0;
		toggle=0;
	}
	
	void merge(node& left,node& right)
	{
		number=left.number+right.number;
		if(left.toggle%2==0&&right.toggle%2==0)
		on=left.on+right.on;
		else if((left.toggle&1)&&(right.toggle&1))
		on=left.number-left.on+right.number-right.on;
		else if((left.toggle&1)&&right.toggle%2==0)
		on=left.number-left.on+right.on;
		else if((right.toggle&1)&&left.toggle%2==0)
		on=left.on+right.number-right.on;
		toggle=0;
	}
	
	void split(node& left,node& right)
	{
		if(toggle&1)
		{
			on=number-on;
			left.toggle+=toggle;
			right.toggle+=toggle;
			toggle=0;
		}
	}
	
	int getvalue()
	{
		if(toggle&1)return (number-on);
		return on;
	}
};
class stree
{
	public:
	int N;
	node *Node;
	stree(int n)
	{
		N=n;
		Node=new node[getSegmentTreeSize(n)];
		build_tree(0,n-1,1);
	}
	~stree()
	{
		delete[] Node;
	}
	void build_tree(int begin,int end,int index)
	{
		if(begin==end)
		{
			Node[index].assignleaf();
			return;
		}
		int mid=(begin+end)/2;
		build_tree(begin,mid,2*index);
		build_tree(mid+1,end,2*index+1);
		Node[index].merge(Node[2*index],Node[2*index+1]);
	}
	
	node query(int index,int begin,int end,int left,int right)
	{
		if(begin>=left&&end<=right)
		{
			return Node[index];
		}
		int mid=(begin+end)/2;
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
	void update(int i,int j)
	{
		update_tree(1,0,N-1,i,j);
	}
	void update_tree(int index,int left,int right,int i,int j)
	{
		if(left>=i&&right<=j)
		{
			Node[index].toggle+=1;
			return;
		}
		int mid=(left+right)/2;
		Node[index].split(Node[2*index],Node[2*index+1]);
		if(i>mid)
		{
			update_tree(2*index+1,mid+1,right,i,j);
		}
		else if(j<=mid)
		{
			update_tree(2*index,left,mid,i,j);
		}
		else
		{
			update_tree(2*index,left,mid,i,mid);
			update_tree(2*index+1,mid+1,right,mid+1,j);
		}
		Node[index].merge(Node[2*index],Node[2*index+1]);
	}
	int getSegmentTreeSize(int N) 
	{
		int size = 1;
		for (; size < N; size <<= 1);
		return size << 1;
	}
	int getValue(int lo,int hi) 
	{
		node result = query(1, 0, N-1, lo, hi);
		return result.getvalue();
	}
};

int main() {
		int i,n,m,ch,p,q;
		scanf("%d%d",&n,&m);
		stree st(n);
		for(i=0;i<m;i++)
		{
			scanf("%d%d%d",&ch,&p,&q);
			if(ch==0)
			{
				st.update(p-1,q-1);
			}
			else
			{
				printf("%d\n",st.getValue(p-1,q-1));
			}
		}
	return 0;
}