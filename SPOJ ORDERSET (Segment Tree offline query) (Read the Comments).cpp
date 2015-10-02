/*SPOJ ORDERSET (Segment Tree offline query) (Map gives only one key to an element, 
if assigned key multiple times last key is the final key)(Coordinate Compression using Maps, 
Count number of elements lesser than a given number is done by querying the Segment Tree in a normal way
( because segment tree stores the number of elements and they are sorted also)
Kth smallest element is found by binary searching the Segment tree (values to be searched made half every
time ) it searches the segment till it finds the segment which is completely filled and 
has the same length as the value we are searching for, value being updated every time)*/
#include <bits/stdc++.h>
#include<cstdio>
using namespace std;
#define gc getchar_unlocked
#define inp(a) scanint(a)
#define MAXN 200005
#define REP(i,a,b) for(int i=a;i<b;i++)
void scanint(int &x)
{
    register int c = gc(),mul=1;
    x = 0;
    for(;!( (c>=48 && c<=57) || c=='-' );c = gc());
    if(c=='-')
        mul=-1,c=gc();
    for(;c>47 && c<58;c = gc())
        {x = (x<<1) + (x<<3) + c - 48;}
    x=x*mul;
}
struct node
{
	 int number;
	void assignleaf()
	{
		number=0;
	}

	void merge(node& left,node& right)
	{
		number=left.number+right.number;
	}
    int getvalue()
    {
        return(number);
    }
}Node[4*MAXN];
int x[MAXN],num[MAXN];
map<int,int> m;
char op[MAXN][2];
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
		int mid=(begin+end)>>1;
		build_tree(begin,mid,index<<1);
		build_tree(mid+1,end,(index<<1)+1);
		Node[index].merge(Node[index<<1],Node[(index<<1)+1]);
	}

	node query(int index,int begin,int end,int left,int right)
	{
		if(begin>end||begin>right||end<left)
		return ((node){0});
		if(begin>=left&&end<=right)
		{
			return Node[index];
		}
		int mid=(begin+end)>>1;
		node leftchild=query(index<<1,begin,mid,left,right);
		node rightchild=query((index<<1)+1,mid+1,end,left,right);
		node result;
		result.merge(leftchild,rightchild);
		return result;
	}
	int search(int index,int i,int j,int val)
	{
	    if(Node[index].number<val)
        {
            return -1;
        }
        if(((j-i+1)==val))
        {
            return j;
        }
        int mid=(i+j)>>1;
        int left=Node[index<<1].number;
        int right=Node[(index<<1)+1].number;
        if(left>=val)
            return search((index<<1),i,mid,val);
        else
            return search((index<<1)+1,mid+1,j,val-left);
	}
	void update(int i,int j,int val)
	{
		update_tree(1,0,N-1,i,j,val);
	}
	void update_tree(int index,int left,int right, int i,int j,int val)
	{
		if(left>j||right<i||left>right)
		return;
		if(left>=i&&right<=j)
		{
			Node[index].number=val;
			return;
		}
		int mid=(left+right)>>1;
		update_tree(index<<1,left,mid,i,j,val);
		update_tree((index<<1)+1,mid+1,right,i,j,val);
		Node[index].merge(Node[index<<1],Node[(index<<1)+1]);
	}
	 int getValue(int lo, int hi)
	{
		node result = query(1, 0, N-1, lo, hi);
		return result.number;
	}
};

int main() {
	int q,i;
	inp(q);
	for(i=0;i<q;i++)
	{
	    scanf("%s",op[i]);
	    inp(x[i]);
	    num[i]=x[i];
	}
	sort(num,num+q);
	for(i=0;i<q;i++)
	{
	    m[num[i]]=i;
	}
	stree st(q);
	for(i=0;i<q;i++)
	{
	    int nodeindex=m[x[i]];
	    switch(op[i][0])
	    {
	        case 'I':st.update(nodeindex,nodeindex,1);
	        break;
	        case 'D':st.update(nodeindex,nodeindex,0);
	        break;
	        case 'K':
	        if((x[i]<=0||Node[1].number<x[i]))
	        	printf("invalid\n");
	        else
                printf("%d\n",num[st.search(1,0,q-1,x[i])]);
            break;
            case 'C':
                if(nodeindex==0)
                	printf("0\n");
                else 
                	printf("%d\n",st.getValue(0,nodeindex-1));
                break;
	    }
	}
	cout<<endl;
	return 0;
}
