#include<bits/stdc++.h>
using namespace std ;
const int N = 15009;
char s[N];
typedef long long ll ;
const ll prime = 1234567 ;
int l=0,r ;
ll dp[300];
map<ll,int> ma ;
map<ll,int> ::iterator it;
main()
{
    int n,m,i,j ;
    ll sub,hash ;
    scanf("%d %d",&n,&m);
    scanf("%s",s);
    r=n+1 ;
    dp[0]=1;
    for(i=1;i<300;i++)
    {
        dp[i]=dp[i-1]*prime ;
    }
    while(l+1<r)
    {
        int mid=(l+r)/2 ;
        sub = 1 ;
        hash = 0 ;
        for(i=0;i<mid;i++)sub*=prime ;
        for(i=0;i<mid;i++)
        {
            hash+=s[i] ;
            hash*=prime ;
        }
        ma[hash]++;
        for(i=mid;i<n;i++)
        {
            hash-=s[i-mid]*sub ;
            hash+=s[i];
            hash*=prime ;
            ma[hash]++;
        }
        bool b = 0 ;
        for(it=ma.begin();it!=ma.end();it++)
        {
            if(it->second>=m)
            {
                b++;
                break ;
            }
        }
        if(b)
        {
            l=mid;
        }
        else r=mid;
        ma.clear();
    }
    printf("%d",l);
}
