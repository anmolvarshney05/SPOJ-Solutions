#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
	string s;
	printf("Ready\n");
	while(getline(cin,s))
	{
		if((s[0]==' ')&&(s[1]==' '))break;
		if((s[0]=='p'&&s[1]=='q')||(s[0]=='q'&&s[1]=='p')||(s[0]=='d'&&s[1]=='b')||(s[0]=='b'&&s[1]=='d'))
		printf("Mirrored pair\n");
		else printf("Ordinary pair\n");
	}
	return 0;
}