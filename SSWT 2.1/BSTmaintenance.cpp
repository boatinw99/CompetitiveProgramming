#include<bits/stdc++.h>
using namespace std ;
const int N = 3e5+9,LOG=log2(N)+1;
typedef long long ll ;
set<int> s ;
vector<int> g[N];
ll ans=0,sum[N],sump[N] ;
int a[N],par[N],sub[N],dist[N][LOG],cnt[N],rnk[N];
bool chld[N],vst[N];//lhs
void dfs1(int u)
{
    sub[u]=1;
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs1(it),sub[u]+=sub[it];
    vst[u]=0;
}
int dfs2(int u,int v,int sz)
{
    for(auto it:g[u])if(it!=v&&!vst[it]&&sub[it]>sz/2)
        return dfs2(it,u,sz);
    return u ;
}
void dfs3(int u,int depth,int cst)
{
    vst[u]++;
    dist[u][rnk[u]-depth]=cst;
    for(auto it:g[u])if(!vst[it])dfs3(it,depth,cst+1);
    vst[u]=0;
}
void decompose(int u,int pre,int depth)
{
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    rnk[ctd]=depth;
    vst[ctd]++;
    ///Compute dist[]
    par[ctd]=pre ;
    for(auto it:g[ctd])if(!vst[it])decompose(it,ctd,depth+1);
    dfs3(ctd,depth,0);
    vst[u]=0;
}
void update(int u)
{
    int x=u,pcnt=0;
    ll psum=0 ;
    for(int i=0;x;i++,pcnt=cnt[x],psum=sump[x],x=par[x])
    {
        ans+=1ll*dist[u][i]*(cnt[x]-pcnt)+sum[x]-psum;
    }
    x=u ;
    for(int i=0;x;i++,x=par[x])
    {
        cnt[x]++;
        sum[x]+=dist[u][i];
        sump[x]+=dist[u][i+1];
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,m ;
    cin >> n ;
    for(i=1;i<=n;i++)cin >> a[i] ;
    s.insert(a[1]);
    for(i=2;i<=n;i++)
    {
        auto it=s.lower_bound(a[i]);
        if(it==s.end()||(it!=s.end()&&chld[*it]))
        {
            ///R child
            it--;
            g[*it].emplace_back(a[i]);
            g[a[i]].emplace_back(*it);
        }
        else
        {
            ///L child
            g[*it].emplace_back(a[i]);
            g[a[i]].emplace_back(*it);
            chld[*it]++;
        }
        s.insert(a[i]);
    }
    decompose(1,0,1);
    for(i=1;i<=n;i++)
    {
        update(a[i]);
        cout << ans << '\n' ;
    }
}
