#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll prime=123457 ;
map<ll,int> m;
map<ll,int>::iterator it;
const int N = 1e5+9;
char s[N];
ll dp[256];
main()
{
    int w,n,i,j ;
    ll hash;
    scanf("%d ",&w);
    dp[0]=1;
    for(i=1;i<255;i++)dp[i]=dp[i-1]*prime;
    while(w--)
    {
        scanf("%s",&s);
        n=strlen(s);
        hash=0;
        for(i=0;i<n;i++)
        {
            hash+=dp[s[i]];
        }
        m[hash]++;
    }
    int max1=0;
    for(it=m.begin();it!=m.end();it++)
    {
        max1=max(max1,it->second);
    }
    printf("%d",max1);
}
