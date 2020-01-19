#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 1e5+9 ;
int u[N<<1],v[N<<1],o[N<<1],p[N],sz[N],n ;
char op[N<<1];
map<pii,int> mp ;
stack<int> st ;
int find(int u)
{
    return u==p[u]?u:find(p[u]);
}
void Union(int u,int v)
{
    u=find(u);v=find(v);
    if(u==v)return ;
    if(sz[u]>sz[v])swap(u,v);
    sz[v]+=sz[u];
    p[u]=v;
    st.push(u);
}
void rollback(int t)
{
    while(st.size()>t)
    {
        int u = st.top();
        st.pop();
        sz[p[u]]-=sz[u];
        p[u]=u;
    }
}
void solve(int l,int r)
{
    if(l==r)
    {
        if(op[l]=='?')
        {
           cout << (find(u[l])==find(v[l])?"YES":"NO") << '\n' ;
        }
        return ;
    }
    int now = st.size() ;
    for(int i=mid+1;i<=r;i++)if(o[i]<l&&op[i]!='?')Union(u[i],v[i]);
    solve(l,mid);
    rollback(now);
    for(int i=l;i<=mid;i++)if(o[i]>r&&op[i]!='?')Union(u[i],v[i]);
    solve(mid+1,r);
    rollback(now);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m ;
    cin >> n >> m ;
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    for(int i=1;i<=m;i++)
    {
        string s ;
        cin >> s ;
        cin >> u[i] >> v[i] ;
        if(u[i]>v[i])swap(u[i],v[i]);
        pii x(u[i],v[i]);
        if(s[0]=='c')
        {
            op[i]='?';
            continue ;
        }
        op[i]='-';
        if(mp.count(x))
        {
            o[i]=mp[x];
            o[o[i]]=i;
            mp.erase(x);
        }
        else mp[x]=i;
    }
    for(auto it:mp)
    {
        o[it.se]=++m;
        o[m]=it.se;
        tie(u[m],v[m])=it.fi;
    }
    solve(1,m);
    return 0 ;
}
