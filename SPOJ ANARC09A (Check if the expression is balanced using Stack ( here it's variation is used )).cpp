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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin>>s;
	int counter = 1;
	while(s[0]!='-')
	{
	    int count=0;
	    printf("%d. ",counter);
	    counter++;
		stack<char> st;
		for(int i=0;i<s.size();i++)
        {
            if(s[i]=='{')
                st.push(s[i]);
            else if (st.size()==0&&s[i]=='}')
            {
            	count++;
            	st.push('{');
            }
            else
            {
                st.pop();
            }
        }
        if(st.size()!=0)
        {
        	count+=st.size()/2;
        }
        printf("%d\n",count);
		cin>>s;
	}
	return 0;
}
