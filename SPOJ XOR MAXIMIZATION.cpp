#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    
    scanf("%d",&n);
    
    vector<long long> v;
    long long x;
    for(int i=0;i<n;i++)
    {
            scanf("%lld",&x);
            v.push_back(x);
    }
    
    sort(v.rbegin(),v.rend());
    
    long long int sig=1;
    
    while(sig<=v[0])
    sig<<=1;
    
    sig>>=1;
    
    for(int t=0;sig>=1;sig>>=1)
    {
            int i=t;
            
            while(i<n && (v[i]&sig)==0)
            i++;
            
            if(i>=n)
            continue;
            
            swap(v[t],v[i]);
            
            for(int j=t+1;j<n;++j)
            {
                    if((v[j]&sig)!=0)
                    v[j]=v[j]^v[t];
            }
            
            t++;
            
    }
    
    long long int result=0;
    
    for(int q=0;q<n;q++)
    {
            if((result^v[q])>result)
            result=result^v[q];
    }
    
    printf("%lld\n",result);
    
    return 0;
}