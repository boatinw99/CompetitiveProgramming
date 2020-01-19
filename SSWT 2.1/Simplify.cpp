#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
typedef long long ll ;
#define fi first
#define se second
const int N = 4e4+9 , md = 1e9+7 ;
vector<pair<int,pii> > g ;
int rnk[N],par[N];
int find(int u){return u==par[u]?u:par[u]=find(par[u]);}
int Union(int x,int y)
{
    int px=find(x),py=find(y);
    if(px==py)return 0 ;
    if(rnk[x]<=rnk[y])rnk[x]+=rnk[y],par[py]=px;
    else rnk[y]+=rnk[x],par[px]=py;
    return 1 ;
}
int main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,i,j,m,u,v,x ;
    ll ans=0,psble=1;
    cin >> n >> m ;
    for(i=1;i<=n;i++)par[i]=i;
    for(i=1;i<=m;i++)
    {
        cin >> u >> v >> x ;
        g.push_back({x,{u,v}});
    }
    sort(g.begin(),g.end());
    for(i=0;i<m;)
    {
        int cnt=0,times=0;
        set<pii> cntE;
        for(j=i;j<m&&g[i].fi==g[j].fi;j++)
        {
            int px=find(g[j].se.fi),py=find(g[j].se.se);
            if(px>py)swap(px,py);///px,py
            if(px!=py)
            {
                cntE.insert({px,py});
                times++;
            }
        }
        for(;i<j;i++)cnt+=Union(g[i].se.fi,g[i].se.se);
        ans+=cnt*g[i-1].fi;
        if(times==2&&cnt==1)psble=psble*2%md;
        if(times==3)
        {
            if(cnt==1||cnt==2&&cntE.size()==3)psble=psble*3%md;
            if(cnt==2&&cntE.size()==2)psble=psble*2%md;
        }
    }
    cout << ans << " " << psble ;
}
