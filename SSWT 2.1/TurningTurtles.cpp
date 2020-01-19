#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9,LOG=log2(N)+1 ;
vector<pii> g[N]; /// terminate , drc ;
pii di[4]={{0,1},{0,-1},{1,0},{-1,0}};
pii drc[N][LOG] ;
int up[N][LOG],cst[N][LOG],tin[N],tout[N],expo2[N],depth[N],times=0;
bool visited[N];
char s[N];
void dfs(int u,int v)
{
    tin[u]=++times ;
    depth[u]=depth[v]+1;
    up[u][0]=v;
    for(int i=1;i<LOG;i++)
    {
        up[u][i]=up[up[u][i-1]][i-1];
        drc[u][i]={drc[u][0].fi,drc[up[u][i-1]][i-1].se};
        cst[u][i]=cst[u][i-1]+cst[up[u][i-1]][i-1]+
                (drc[u][i-1].se!=drc[up[u][i-1]][i-1].fi);
    }
    for(auto it:g[u])
    {
        if(it.fi!=v)drc[it.fi][0]={it.se^1,it.se^1},dfs(it.fi,u);
    }
    tout[u]=++times;
}
bool Islca(int u,int v)
{
    return tin[u]<=tin[v]&&tout[u]>=tout[v];
}
int findlca(int u,int v)
{
    if(Islca(u,v))return u ;
    if(Islca(v,u))return v ;
    for(int i=LOG-1;i>=0;i--)if(!Islca(up[u][i],v))u=up[u][i];
    return up[u][0] ;
}
pii blift(int u,int cnt)
{
    ///depth[u]>depth[lca]
    int dr=-1,x=-1 ;
    for(int i=0;i<LOG;i++)
    {
        if(expo2[i]&cnt)
        {
            if(dr!=drc[u][i].fi)x++;
            x+=cst[u][i];
            dr=drc[u][i].se;
            u=up[u][i];
        }
    }
    return {x,dr};
}
int qans(int u,int v)
{
    int lca=findlca(u,v);
    pii ql = blift(u,depth[u]-depth[lca]);
    pii qr=blift(v,depth[v]-depth[lca]);
    return max(0,ql.fi+qr.fi+((ql.se^1)!=qr.se));
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int n,m,i,j,u1,u2,v1,v2,T,d ;
    cin >> n >> m ;
    expo2[0]=1;
    for(i=1;i<LOG;i++)expo2[i]=expo2[i-1]*2;
    for(i=0;i<n;i++)for(j=1;j<=m;j++)cin >> s[i*m+j] ;
    for(i=1;i<=n*m;i++)if(s[i]=='#')for(d=0;d<4;d++)
    {
        int tmp = i+di[d].fi*m+di[d].se ;
        if(tmp>=1&&tmp<=n*m&&(i%m!=1||tmp!=i-1)&&(i%m!=0||tmp!=i+1)
           &&s[tmp]=='#')g[i].emplace_back(tmp,d);
    }
    for(i=1;i<=n*m;i++)
    {
        if(!visited[i]&&s[i]=='#')
        {
            dfs(i,i);
            break;
        }
    }
    cin >> T ;
    while(T--)
    {
        cin >> u1 >> u2 >> v1 >> v2 ;
        cout << qans((u1-1)*m+u2,(v1-1)*m+v2) << '\n' ;
    }
}
