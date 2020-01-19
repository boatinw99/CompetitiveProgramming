#include<bits/stdc++.h>
using namespace std ;
typedef vector<int> vi;
const int N = 1e5+9 , LOG = log2(N)+1, K = 11 ;
vi G[N];
vi P[N];
int up[N][LOG];
vi MIN[N][LOG];
vi s,g ;
int tin[N],tout[N];
int times=0;
vi re(vi x,vi y)
{
    vi a ;
    int i=0,j=0,k,size1=x.size(),size2=y.size();
    ///i,size1
    ///j,size2
    for(k=0;k<10;k++)
    {
        if(i==size1&&j==size2)
        {
            return a;
        }
        if(i==size1)
        {
            a.emplace_back(y[j++]);
        }
        else if(j==size2)
        {
            a.emplace_back(x[i++]);
        }
        else if(x[i]<y[j])
        {
            a.emplace_back(x[i++]);
        }
        else a.emplace_back(y[j++]);
    }
    return a ;
}
void dfs(int u,int v)
{
    vi ::iterator it ;
    tin[u]=++times;
    up[u][0]=v;
    MIN[u][0]=re(P[u],P[N-1]);
    for(int i=1;i<LOG;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        MIN[u][i]=re(MIN[u][i-1],MIN[up[u][i-1]][i-1]);
    }
    for(it:G[u])
    {
        if(it!=v)
        {
            up[it][0]=u;
            dfs(it,u);
        }
    }
    tout[u]=++times;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
vi findlca(int u,int v)
{
    vi ans ;
    int LCA=0 ;
    if(Islca(u,v))LCA=u;
    if(Islca(v,u))LCA=v,swap(u,v);
    if(LCA==u)
    {
        for(int i=LOG-1;i>=0;i--)
        {
            if(!Islca(up[v][i],u))
            {
                ans=re(ans,MIN[v][i]);
                v=up[v][i];
            }
        }
        ans=re(ans,MIN[v][1]);
        return ans ;
    }
    int u1=u ;
    for(int i=LOG-1;i>=0;i--)
    {
        if(!Islca(up[u1][i],v))
        {
            ans=re(ans,MIN[u1][i]);
            u1=up[u1][i];
        }
    }
    ans=re(ans,MIN[u1][1]);
    for(int i=LOG-1;i>=0;i--)
    {
        if(!Islca(up[v][i],u))
        {
            ans=re(ans,MIN[v][i]);
            v=up[v][i];
        }
    }
    ans=re(ans,MIN[v][0]);
    return ans ;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,i,j,k,u,v,T,size,x ;
    vi ans ;
    vi ::iterator it ;
    cin >> n >> m >> T ;
    for(i=1;i<n;i++)
    {
        cin >> u>> v;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    for(i=1;i<=m;i++)
    {
        cin >> u ;
        P[u].emplace_back(i);
    }
    for(i=1;i<=n;i++)sort(P[i].begin(),P[i].end());
    dfs(1,1);
    while(T--)
    {
        cin >> u>> v>>size;
        if(u==v)
        {
            ans=re(P[u],P[N-1]);
        }
        else ans=findlca(u,v);
        x=ans.size();
        cout << min(size,x) << " ";
        for(it:ans)
        {
            cout << it << " ";
            size--;
            if(size==0)break;
        }
        cout << '\n';
    }
}
