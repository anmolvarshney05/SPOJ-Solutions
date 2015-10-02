#include <stdio.h>
unsigned long a[100001];
unsigned long func(unsigned long n)
{
	if(n<12)return n;
	else if(n>12 && n<=100000 && a[n]!=0)
	{
		return a[n];
	}
	else 
	{
	 return(func(n/2)+func(n/3)+func(n/4));	
	}
}

int main(void) {
	long int i;
	for(i=0;i<100001;i++)
	{
		a[i]=0;
		a[i]=func(i);
	}
	unsigned long ans,n;
	while(scanf("%lu",&n)!=EOF)
	{
		ans=func(n);
		printf("%lu\n",ans);
	}
	return 0;
}
