#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pii ;
#define fi first
#define se second
const ll inf = 1e16 ;
const int N = 1e5+9 ;
vector<pii> g[N];
priority_queue<pii,vector<pii>,greater<pii> > pq;
ll dist[N][2],mx[N];
bool bq[N];
void dijks(int u,int bl)
{
    pq.push({0,u});
    dist[u][bl]=0;
    while(!pq.empty())
    {
        pii x = pq.top();
        pq.pop();
        if(dist[x.se][bl]!=x.fi)continue ;
        for(auto it:g[x.se])
        {
            if(dist[x.se][bl]+it.se<dist[it.fi][bl])
            {
                dist[it.fi][bl]=dist[x.se][bl]+it.se;
                pq.push({dist[it.fi][bl],it.fi});
            }
        }
    }
}
int main()
{
    int n,m,a,b,c,d ;
    cin >> n >> m ;
    for(int i=1,u,v,x;i<=m;i++)
    {
        cin >> u >> v >> x ;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    cin >> a >> b >> c >> d ;
    for(int i=0;i<N;i++)dist[i][0]=dist[i][1]=mx[i]=inf ;
    dijks(a,0);
    dijks(b,1);
    ll mn = dist[b][0];
    for(int i=1;i<=n;i++)
    {
        if(dist[i][0]+dist[i][1]==mn)bq[i]++;
    }
    pq.push({0,c});
    mx[c]=0;
    while(!pq.empty())
    {
        pii x = pq.top();
        pq.pop();
        if(mx[x.se]!=x.fi)continue ;
        //printf("aa %lld %lld \n",x.fi,x.se);
        for(auto it:g[x.se])
        {
            if(!bq[it.fi]&&x.fi+it.se<mx[it.fi])
            {
                mx[it.fi]=mx[x.se]+it.se;
                pq.push({mx[it.fi],it.fi});
            }
        }
    }
    cout << (mx[d]==inf?-1:mx[d]) << '\n' ;
    return 0 ;
}
