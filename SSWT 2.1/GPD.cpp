#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 3e5+9,LOG=31,mx=1<<30;
int L[N*LOG],R[N*LOG];
int n,id=1;
map<int,vector<pii> > g;
map<int,int> mp ;
void construct(int bit,int x,int m)
{
    if(bit==0)return ;
    if(x&bit)R[m]=++id,construct(bit>>1,x,R[m]);
    else L[m]=++id,construct(bit>>1,x,L[m]);
}
int update(int bit,int x,int m)
{
    int tmp = ++id ;
    if(bit==0)return tmp;
    R[tmp]=R[m],L[tmp]=L[m];
    if(x&bit)
    {
        if(!R[tmp])R[tmp]=++id,construct(bit>>1,x,R[tmp]);
        else R[tmp]=update(bit>>1,x,R[m]);
    }
    else
    {
        if(!L[tmp])L[tmp]=++id,construct(bit>>1,x,L[tmp]);
        else L[tmp]=update(bit>>1,x,L[m]);
    }
    return tmp ;
}
int findmax(int bit,int x,int m)
{
    if(bit==0)return 0;
    if(!L[m])return bit+findmax(bit>>1,x,R[m]);
    if(!R[m])return findmax(bit>>1,x,L[m]);
    if(x&bit)return findmax(bit>>1,x,L[m]);
    return bit+findmax(bit>>1,x,R[m]);
}
int findmin(int bit,int x,int m)
{
    if(!bit)return 0 ;
    if(!L[m])return bit+findmin(bit>>1,x,R[m]);
    if(!R[m])return findmin(bit>>1,x,L[m]);
    if(x&bit)return bit+findmin(bit>>1,x,R[m]);
    return findmin(bit>>1,x,L[m]);
}
void dfs(int u,int v)
{
    for(auto it:g[u])
    {
        if(it.fi!=v)
        {
            mp[it.fi]=update(mx,it.se,mp[u]);
            dfs(it.fi,u);
        }
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,R,x,i,j,u,v,ans=0,a,b,t ;
    cin >> n >> m >> R >> x ;
    mp[R]=1;
    construct(mx,x,1);
    for(i=1;i<n;i++)
    {
        cin >> u >> v >> x ;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    dfs(R,0);
    while(m--)
    {
        cin >> t >> u >> v ;
        t^=ans,u^=ans,v^=ans ;
        if(t==0)
        {
            cin >> x ;
            x^=ans ;
            mp[v]=update(mx,x,mp[u]);
        }
        else
        {
            a=findmin(mx,v,mp[u])^v;
            b=findmax(mx,v,mp[u])^v;
            cout << a << " " << b << '\n' ;
            ans=a^b ;
        }
    }
}
