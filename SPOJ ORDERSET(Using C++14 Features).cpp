/* Created by Anmol Varshney */

/* Commented Codes are for use in C++14 and in place of auto use typeof() */
#include<stdio.h>
#include<string.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/trie_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
#define INT_MIN -2147483647
#define INT_MAX 2147483647
#define INF 2000000000
#define INF_LL 9223372036854775807LL
#define PI acos(-1.0)
#define llu long long unsigned
#define ll long long int
#define ld long int
#define iter(i,a) for( typeof(a.begin()) i=a.begin();i!=a.end();i++)
#define REP(p,a,b) for(int p=a;p<b;p++)
#define mod 1000000007
#define getchar_unlocked getchar
#define pb(f) push_back(f)
#define pob(f) pop_back(f)
#define pf(f) push_front(f)
#define pof(f) pop_front(f)
#define mkp(a,b) make_pair(a,b)
#define fst first
#define snd second
#define pii pair<int,int>
#define ins(a) insert(a)
#define ok(a) order_of_key(a)
#define fbo(a) find_by_order(a)
#define pr(a) prefix_range(a) //Returns iterators to beginning and ending of vector of prefixes matched

typedef tree<
int,
null_type,
less<int>, // Comparator function
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

ordered_set X;

typedef trie<
string,
null_type,
trie_string_access_traits<>,
pat_trie_tag,
trie_prefix_search_node_update>
pref_trie;

pref_trie base;

int main() {
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    int q,ele;
    scanf("%d",&q);
    while(q--)
    {
        char temp=getchar();
        char ch=getchar();
        char enter=getchar();
        scanf("%d",&ele);
        switch(ch)
        {
            case 'I':X.ins(ele);
            break;
            case 'D':X.erase(ele);
            break;
            case 'K':
            if(ele>X.size())
                printf("invalid\n");
            else
                printf("%d\n",*X.fbo(ele-1));
            break;
            case 'C':printf("%d\n",X.ok(ele));
            break;
        }
    }
	return 0;
}
