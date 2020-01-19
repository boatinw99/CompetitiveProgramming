#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 3e5+9 ;
map<pii,int> mp ;
stack<int> st ;
int u[N<<3],v[N<<3],o[N<<3],ans=0,p[N],sz[N];
char op[N<<3];
int find(int u)
{
    return u==p[u]?u:find(p[u]);
}
void Union(int u,int v)
{
    u=find(u);v=find(v);
    if(u==v)
    {
        if(sz[u]&1)ans++;
        return ;
    }
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
        if(op[l]=='?')cout << (ans==0?"yes":"no") << '\n' ;
        return ;
    }
    int now = st.size(),exans=ans;
    for(int i=mid+1;i<=r;i++)if(o[i]<l)Union(u[i],v[i]);
    solve(l,mid);
    rollback(now);
    ans=exans ;
    for(int i=l;i<=mid;i++)if(o[i]>r)Union(u[i],v[i]);
    solve(mid+1,r);
    rollback(now);
    ans=exans ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    cin >> n >> m ;
    for(int i=1;i<=n;i++)p[i]=i,sz[i]=1;
    for(int i=1;i<=2*m;i+=2)
    {
        int typ ;
        cin >> typ >> u[i] >> v[i] ;
        if(u[i]>v[i])swap(u[i],v[i]);
        pii x(u[i],v[i]);
        if(typ==1)mp[x]=i;
        else
        {
            o[i]=mp[x];
            o[o[i]]=i;
            mp.erase(x);
        }
        op[i+1]='?';
    }
    m<<=1;
    for(auto it:mp)
    {
        o[it.se]=m++;
        o[m]=it.se;
        tie(u[m],v[m])=it.fi;
    }
    solve(1,m);
    return 0 ;
}
