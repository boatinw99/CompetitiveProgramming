#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
typedef long long ll ;
#define fi first
#define se second
const int N = 1e3+9,M=1e5 ;
const ll MAX = 1e18 ;
struct edge
{
    int x,y;
    ll wi;
    int erased;
};
ll dist[N][2];
edge E[M];
pii par[N]; ///par , edge
vector<pii> g[N];
priority_queue<pair<ll,pii>> pq ; ///dist PassorNot
main()
{
    ios::sync_with_stdio(false);
    int n,m,i,j,s,t,u,v ;
    pii ans={0,0};
    ll L ;
    cin >> n >> m >> L >> s >> t;
    for(i=1;i<=m;i++)
    {
        cin >> E[i].x >> E[i].y >> E[i].wi ;
        if(E[i].wi==0)E[i].wi=1,E[i].erased=i;
        g[E[i].x].emplace_back(E[i].y,i);
        g[E[i].y].emplace_back(E[i].x,i);
    }
    for(i=0;i<N;i++)
    {
        par[i].fi=-1;
        dist[i][0]=dist[i][1]=1e18;
    }
    dist[s][1]=0; ///pass , notpass
    for(pq.push({0,{0,s}});!pq.empty();)
    {
        u=pq.top().se.se;
        ll d=pq.top().fi*-1;
        int pass=pq.top().se.fi*-1;
        pq.pop();
        int tmp1=0 ;
        if(pass==0)tmp1=1;
        if(dist[u][tmp1]!=d)continue ;
        if(u==t&&tmp1==1)break;
        if(u==t&&tmp1==0&&ans.fi==0)ans={pass,d};
        for(auto it:g[u])
        {
            ll tmp = d+E[it.se].wi;
            if(tmp<dist[it.fi][0]&&(E[it.se].erased!=0||pass!=0))
            {
                dist[it.fi][0]=tmp;
                par[it.fi]={u,it.se} ;
                int tmp2=pass;
                if(pass==0)tmp2=E[it.se].erased;
                pq.push({-tmp,{-tmp2,it.fi}});
            }
            else if(tmp<dist[it.fi][1]&&E[it.se].erased==0&&pass==0)
            {
                dist[it.fi][1]=tmp;
                pq.push({-tmp,{0,it.fi}});
            }
        }
    }

    if(dist[t][1]<1ll*L)
    {
        cout << "NO" ;
        return 0 ;
    }
    else if(dist[t][1]>1ll*L&&dist[t][0]>1ll*L)
    {
        cout << "NO";
        return 0 ;
    }
    else if(dist[t][1]==1ll*L)
    {
        cout << "YES" << '\n' ;
        for(int j=1;j<=m;j++)
        cout << E[j].x << " " << E[j].y << " " << E[j].wi << '\n';
        return 0;
    }
    bool vst[N];
    memset(vst,0,sizeof vst);
    for(i=1;i<=m;i++)
    {
        if(E[i].erased)E[i].wi=MAX;
    }
    while(par[t].fi!=-1&&t!=s&&!vst[par[t].fi])
    {
        if(par[t].se==ans.fi)E[par[t].se].wi=L-ans.se+1;
        else if(E[par[t].se].erased)E[par[t].se].wi=1;
        vst[t]++;
        t=par[t].fi;
    }
    cout << "YES" << '\n' ;
    for(int j=1;j<=m;j++)
        cout << E[j].x << " " << E[j].y << " " << E[j].wi << '\n';
}
