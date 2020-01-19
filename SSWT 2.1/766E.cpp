///16mins
///N*logN*logMAX
///1sub
#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9,MAX=1e6,LOG=log2(MAX)+1 ;
vector<int> g[N];
int a[N],sub[N],cnt[N];
int num=0;
bool vst[N];
ll ans=0 ;
void update(int x)
{
    for(int i=0,bit=1;bit<=MAX;bit<<=1,i++)
    {
        if(bit&x)cnt[i]++;
    }
}
void getsum(int x)
{
    for(int i=0,bit=1;bit<=MAX;bit<<=1,i++)
    {
        if(bit&x)ans+=1ll*(num-cnt[i])*bit;
        else ans+=1ll*cnt[i]*bit;
    }
}
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
void dfs3(int u,int cst)
{
    vst[u]++;
    cst^=a[u];
    getsum(cst);
    for(auto it:g[u])if(!vst[it])dfs3(it,cst);
    vst[u]=0;
}
void dfs4(int u,int cst)
{
    vst[u]++;
    num++;
    cst^=a[u];
    update(cst);
    for(auto it:g[u])if(!vst[it])dfs4(it,cst);
    vst[u]=0;
}
void dcp(int u)
{
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    vst[ctd]++;
    num++;
    update(a[ctd]);
    for(auto it:g[ctd])
    {
        if(!vst[it])
        {
            dfs3(it,0);
            dfs4(it,a[ctd]);
        }
    }
    num=0;
    for(int i=0;i<LOG;i++)cnt[i]=0;
    for(auto it:g[ctd])if(!vst[it])dcp(it);
}
main()
{
    ios::sync_with_stdio(false);
    int n,i,j,u,v ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        ans+=a[i];
    }
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    dcp(u);
    cout << ans ;
}
