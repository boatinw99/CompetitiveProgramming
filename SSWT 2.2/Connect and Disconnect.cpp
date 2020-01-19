#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 3e5+9 ;
int p[N],sz[N] ;
stack<int> st ;
int o[N<<1],u[N<<1],v[N<<1],ans,n,m ;
char op[N<<1];
map<pii,int> mp ;
int find(int u)
{
    while(u!=p[u])u=p[u];
    return u ;
}
void Union(int u,int v)
{
    u=find(u);v=find(v);
    if(u==v)return ;
    if(sz[u]>sz[v])swap(u,v);
    p[u]=v;
    sz[v]+=sz[u];
    st.push(u);
    ans--;
}
void rollbax(int t)
{
    while(st.size()>t)
    {
        int u = st.top(); st.pop();
        sz[p[u]]-=sz[u];
        p[u]=u;
        ans++;
    }
}
void solve(int l,int r)
{
    if(l==r)
    {
        if(op[l]=='?')printf("%d\n",ans);
        return ;
    }
    int now = st.size();
    for(int i=mid+1;i<=r;i++)if(o[i]<l)Union(u[i],v[i]);
    solve(l,mid);
    rollbax(now);
    for(int i=l;i<=mid;i++)if(o[i]>r)Union(u[i],v[i]);
    solve(mid+1,r);
    rollbax(now);
}
int main()
{
    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);
    scanf("%d %d",&n,&m);
    if(!m)return 0 ;
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++)
    {
        scanf(" %c",&op[i]);
        if(op[i]=='?')continue ;
        scanf("%d %d",&u[i],&v[i]);
        if(u[i]>v[i])swap(u[i],v[i]);
        pii x(u[i],v[i]);
        if(mp.count(x))
        {
            o[i]=mp[x];
            o[o[i]]=i;
            mp.erase(x);
        }
        else mp[x]=i ;
    }
    for(auto it:mp)
    {
        o[it.se]=++m;
        o[m]=it.se;
        op[m]='-';
        tie(u[m],v[m])=it.fi;
    }
    ans = n ;
    solve(1,m);
}
