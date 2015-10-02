/* Created by Anmol Varshney */

/*
Game Theory - First Identify the winning states and try to build smaller bigger states from it like if ans is known for 1,2,3 try to find for 4,5 etc.
Now if any state can be reduced to a losing state(here if the player plays first and ends up on his losing state that means he wins because the he started
on the losing state for our answer but now the other plays starts from there. Fill up the array for the MAX limit and display the answer.
*/

/*INCLUDE_HEADERS*/
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
/*END HEADERS*/
using namespace std;
#define MAX 1000001
bool ans[MAX];
int main() {
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	int k,l,m;
	scanf("%d%d%d",&k,&l,&m);
	ans[0]=false;
	ans[1]=true;
	for(int i=2;i<MAX;i++)
    {
        ans[i]=false;
        if(ans[i-1]==false)ans[i]=true;
        else if((i-k)>=0&&ans[i-k]==false)ans[i]=true;
        else if((i-l)>=0&&ans[i-l]==false)ans[i]=true;
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d",&k);
        if(ans[k])printf("A");
        else printf("B");
    }
	return 0;
}
