#include<bits/stdc++.h>
using namespace std ;
const int N=1e5+9;
int a[N],dp[N];
multiset<int> s,q;
main()
{
    int n,e,l,i,j ;
    scanf("%d %d %d",&n,&e,&l);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(i=1,j=1;i<=n;i++)
    {
        s.insert(a[i]);
        dp[i]=N;
        while(*s.rbegin()-*s.begin()>e)
        {
            s.erase(s.find(a[j]));
            if(q.find(dp[j-1])!=q.end())
            q.erase(q.find(dp[j-1]));
            j++;
        }
        if(i-j+1>=l)
        {
            q.insert(dp[i-l]);
        }
        if(q.empty())dp[i]=N;
        else dp[i]=1+*q.begin();
    }
    printf("%d",(dp[n]>=N)?-1:dp[n]);
}
