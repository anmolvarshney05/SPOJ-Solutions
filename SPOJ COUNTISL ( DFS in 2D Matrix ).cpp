/* Created by Anmol Varshney */

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
#define ARRAY_SIZE(arr) sizeof(arr)/sizeof(arr[0])
bool visited[201][201];
char M[201][201];
static int rowincrement[]={-1,-1,-1,0,0,1,1,1};
static int columnincrement[]={-1,0,1,-1,1,-1,0,1};

void DFS(int row,int column,int m,int n)
{
    visited[row][column]=true;
    for(int i=0;i<8;i++)
    {
        if(row+rowincrement[i]>=0&&row+rowincrement[i]<m&&column+columnincrement[i]>=0&&column+columnincrement[i]<n&&M[row+rowincrement[i]][column+columnincrement[i]]=='#'&&!visited[row+rowincrement[i]][column+columnincrement[i]])
        {
            DFS(row+rowincrement[i],column+columnincrement[i],m,n);
        }
    }
}

int countislands(int m,int n)
{
    int result=0;
    memset(visited,0,sizeof(visited[0][0])*201*201);
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(M[i][j]=='#'&&!visited[i][j])
            {
                DFS(i,j,m,n);
                result++;
            }
        }
    }
    return result;
}
int main() {
    //freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int m,n;
        scanf("%d%d",&m,&n);
        char ch=getchar();
        for(int i=0;i<m;i++)
        {
           scanf("%s",M[i]);
        }
        printf("%d\n",countislands(m,n));
    }
    return 0;
}
