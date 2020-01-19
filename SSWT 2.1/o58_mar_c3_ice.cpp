#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ;
struct node
{
    int sz,town,now ;
    bool operator<(const node &tmp)const
    {
        if(sz!=tmp.sz)return sz<tmp.sz;
        return town>tmp.town ;
    }
};
priority_queue<node> pq ;
vector<pii> g[N];
int vst[N];
pii ans[N];
bool etravel[N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,x,u,v ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        if(!x)pq.push({0,0,i});
        else pq.push({x,i,i});
        vst[i]=x;
    }
    for(i=1;i<=m;i++)
    {
        cin >> u >> v >> x ;
        g[u].emplace_back(v,x);
        g[v].emplace_back(u,x);
    }
    while(!pq.empty())
    {
        node tmp = pq.top();
        pq.pop();
        if(vst[tmp.now]!=tmp.sz||etravel[tmp.now])continue ;
        ans[tmp.now]={tmp.sz,tmp.town};
        etravel[tmp.now]=1;
        for(auto it:g[tmp.now])
        {
            if(tmp.sz-it.se>=vst[it.fi])
            {
                vst[it.fi]=tmp.sz-it.se;
                pq.push({tmp.sz-it.se,tmp.town,it.fi});
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        cout << ans[i].se << " " << ans[i].fi << '\n' ;
    }
}
