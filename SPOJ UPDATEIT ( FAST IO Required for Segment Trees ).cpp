#include <bits/stdc++.h>
using namespace std;
int const MAXN = 100000 + 5;
#define gc getchar_unlocked
#define pc putchar_unlocked
inline int scan()
{
	register int c=gc();
	int x=0;
	for(;(c<48||c>57);c=gc());
	for(;(c>47&&c<58);c=gc()){x= (x<<1) + (x<<3) + c-48;}
	return x;
}	
 
inline void print(int n)
{
	int N=n,rev,count=0;
	rev=N;
	if(N==0){pc('0');return;}
	while((rev%10)==0){count++;rev/=10;}
	rev=0;
	while(N!=0){rev= (rev<<3)+(rev<<1)+N%10;N/=10;}
	while(rev!=0){pc(rev%10+'0');rev/=10;}
	while(count--){pc('0');}
	pc('\n');
}
struct node
{
	int sum;
	int number;
	int add;
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
	
	int getvalue()
	{
		return(sum+(number*add));
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
	void update(int i,int j,int val)
	{
		update_tree(1,0,N-1,i,j,val);
	}
	void update_tree(int index,int left,int right,int i,int j,int value)
	{
		if(left>=i&&right<=j)
		{
			Node[index].add+=value;
			return;
		}
		int mid=(left+right)/2;
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
	int getValue(int lo, int hi) 
	{
		node result = query(1, 0, N-1, lo, hi);
		return result.getvalue();
	}
};

int main() {
	int i,n,u,t,r,l,val,q;
	t=scan();
	while(t--)
	{
		n=scan();
		u=scan();
		stree st(n);
		for(i=0;i<u;i++)
		{
			l=scan();
			r=scan();
			val=scan();
			st.update(l,r,val);
		}
		q=scan();
		for(i=0;i<q;i++)
		{
			val=scan();
			print(st.getValue(val,val));
		}
	}
	return 0;
}