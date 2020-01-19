#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e5+9,apb='t'-'a'+2;///Alphabet
int mask[1<<apb],sub[N],a[N];
ll ans[N],cnt[N];
bool vst[N];
vector<int> g[N];
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
void dfs3(int u,int bits)
{
    bits^=a[u];
    cnt[u]+=mask[bits];
    for(int i=0,tmp=1;i<apb;i++,tmp<<=1)
    {
        cnt[u]+=mask[bits^tmp];
    }
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs3(it,bits);
    vst[u]=0;
}
void dfs4(int u,int bits,int add)
{
    bits^=a[u];
    mask[bits]+=add;
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs4(it,bits,add);
    vst[u]=0;
}
ll dfs5(int u)
{
    vst[u]++;
    for(auto it:g[u])if(!vst[it])cnt[u]+=dfs5(it);
    ll tmp = cnt[u];
    ans[u]+=cnt[u];
    cnt[u]=0;
    vst[u]=0;
    return tmp ;
}
void dcp(int u)
{
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    vst[ctd]++;
    mask[0]++;
    for(auto it:g[ctd])if(!vst[it])dfs4(it,0,1);
    for(auto it:g[ctd])
    {
        if(!vst[it])
        dfs4(it,0,-1),dfs3(it,a[ctd]),dfs4(it,0,1);
    }
    ///mask (i->BeforeRoot)
    mask[0]--;
    cnt[ctd]+=mask[a[ctd]];
    for(int i=0,tmp=1;i<apb;i++,tmp<<=1)
    {
        cnt[ctd]+=mask[a[ctd]^tmp];
    }
    ll tmp = dfs5(ctd);
    ans[ctd]-=tmp/2;
    ans[ctd]++;
    vst[ctd]++;
    for(auto it:g[ctd])if(!vst[it])dfs4(it,0,-1);
    for(auto it:g[ctd])if(!vst[it])dcp(it);
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,i,j,u,v ;
    char c ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=1;i<=n;i++)
    {
        cin >> c;
        a[i]=1<<(c-'a');
    }
    dcp(1);
    for(i=1;i<=n;i++)
    {
        cout << ans[i] << " " ;
    }
}
