#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 2e5+9 ;
vector<int> g[N];
vector<int> artp ; ///articulation point
int dist[N],low[N],times=1 ;
int vst[N],n,l=1;
queue<pii> q ;
void dfs(int u,int v)
{
    dist[u]=low[u]=++times;
    bool b=0 ;
    for(auto it:g[u])
    {
        if(it!=v)
        {
            if(dist[it]==0)
            {
                dfs(it,u);
                vst[u]=max(vst[u],vst[it]);
                low[u]=min(low[u],low[it]);
                if(vst[it]==1&&dist[u]<=low[it]&&!b)
                {
                    b++;
                    artp.emplace_back(u);
                }
            }
            else
            {
                low[u]=min(low[u],dist[it]);
            }
        }
    }
}
void clearq()
{
    while(!q.empty())
    {
        int x=q.front().fi;
        int y=q.front().se ;
        q.pop();
        if(y==artp[l])
        {
            dist[l]=x;
            l++;
        }
        if(l==artp.size())return ;
        for(auto it:g[y])
        {
            if(vst[it]==0)
            {
                vst[it]++;
                q.push({x+1,it});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,i,j,L,u,v  ;
    cin >> n >> m >> L ;
    vst[n]=1;
    for(i=1;i<=m;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dfs(1,1);
    artp.pop_back();
    if(artp.empty())
    {
        cout << 0 ;
        return 0 ;
    }
    memset(vst,0,sizeof vst);
    vst[artp[0]]++;
    vst[n]++;
    vst[1]++;
    memset(dist,0,sizeof dist);
    q.push({0,artp[0]});
    clearq();
    int sum = 0,tmp=L*2,ans=1;
    for(i=0;i<(int)artp.size();i++)
    {
        sum+=dist[i]-dist[i-1];
        if(sum>tmp)
        {
            ans++;
            sum=0;
        }
    }
    cout << ans ;
}
