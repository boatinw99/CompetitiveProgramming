#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ;
typedef long long ll ;
vector<pair<int,ll> > path[N];
vector<ll>key;
vector<ll>::iterator itkey;
queue<ll> q;
ll bi[N];
ll ans=0,all=0,k ;
void update(int i,int co)
{
    for(;i<N;i+=i&-i)bi[i]+=co;
}
ll sum(int i)
{
    ll x=0;
    for(;i;i-=i&-i)x+=bi[i];
    return x;
}
void findkey(int u,int v,ll wi)
{
    vector<pair<int,ll> >::iterator it ;
    key.push_back(wi);
    for(it=path[u].begin();it!=path[u].end();it++)
        if(it->first!=v)
        findkey(it->first,u,wi+it->second);
}
void dfs(int u,int v,ll wi)
{
    int t;
    vector<pair<int,ll> > ::iterator it ;
    while(all>k)
    {
        all-=q.front();
        q.pop();
    }
    t=upper_bound(key.begin(),key.end(),k-wi)-key.begin();
    t--;
    ans+=sum(t);
    ans+=(long long)q.size();
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(it->first!=v)
        {
            all+=it->second;
            q.push(it->second);
            dfs(it->first,u,wi+it->second);
        }
    }
    while(!q.empty())
    {
        all-=q.front();
        q.pop();
    }
    t=lower_bound(key.begin(),key.end(),wi)-key.begin();
    update(t,1);
}
main()
{
    int n,u,v,wi,x,y,i,j ;
    scanf("%d %lld",&n,&k);
    for(i=1;i<n;i++)
    {
        scanf("%d %d %lld",&u,&v,&wi);
        path[u].push_back({v,wi});
        path[v].push_back({u,wi});
    }
    for(i=1;i<=n;i++)
    {
        if(path[i].size()==1)x=i;
        if(path[i].size()>=3)
        {
            break;
        }
    }
    if(i<=n)x=i;
    findkey(x,x,0);
    key.push_back(INT_MIN);
    sort(key.begin(),key.end());
    dfs(x,x,0);
    printf("%lld",ans);
}
