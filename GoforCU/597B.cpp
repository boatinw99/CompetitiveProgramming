#include<bits/stdc++.h>
using namespace std ;
map<int,int> m;
map<int,int> ::iterator itm;
vector<pair<int,int> > v;
vector<pair<int,int> > ::iterator it;
const int N = 1000009;
int dp[N];
main()
{
    int n,i,j,x,y,k=1 ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        v.push_back({x,y});
        m[x]++; m[y]++;
    }
    sort(v.begin(),v.end());
    i=1;
    for(itm=m.begin();itm!=m.end();itm++,i++)
    {
        itm->second=i;
    }
    int max1= 0;
    for(it=v.begin();it!=v.end();it++)
    {
        x=it->first ;y=it->second ;
        itm=m.lower_bound(x);
        x=itm->second;
        itm=m.lower_bound(y);
        y=itm->second;
        for(k;k<x;k++)dp[k]=max(dp[k],dp[k-1]);
        dp[y]=max(dp[y],dp[x-1]+1);
        max1=max(max1,dp[y]);
    }
    printf("%d",max1);
}
