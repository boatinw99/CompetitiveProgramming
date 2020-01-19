#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 3e5+9,md=N/2,K=15e5+9 ;
vector<int> g[N];
int a[N],sub[N],di[K];
ll dist[N],numb[N];
bool vst[N];
ll ans=0;
void update(ll *f,int i,int cst)
{
    for(;i;i-=i&-i)f[i]+=cst ;
}
ll getsum(ll *f,int i)
{
    ll x=0;
    for(;i<N;i+=i&-i)x+=f[i];
    return x ;
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
    for(auto it:g[u])if(!vst[it]&&it!=v&&sub[it]>sz/2)
        return dfs2(it,u,sz);
    return u ;
}
void dfs3(int u,int sum,int cst)
{
    sum+=a[u];
    ans+=getsum(numb,md-sum)*cst+getsum(dist,md-sum);
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs3(it,sum,cst+1);
    vst[u]=0;
}
void dfs4(int u,int sum,int cst,int add)
{
    sum+=a[u];
    update(dist,md+sum,add*cst);
    update(numb,md+sum,add);
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs4(it,sum,cst+1,add);
    vst[u]=0;
}
void decompose(int u)
{
    dfs1(u);
    int ctd = dfs2(u,u,sub[u]);
    vst[ctd]++;
    update(numb,a[ctd]+md,1);
    for(auto it:g[ctd])
    {
        if(!vst[it])
        {
            dfs3(it,0,2);
            dfs4(it,a[ctd],1,1);
        }
    }
    for(auto it:g[ctd])if(!vst[it])dfs4(it,a[ctd],1,-1);
    update(numb,a[ctd]+md,-1);
    for(auto it:g[ctd])if(!vst[it])decompose(it);
}
void preprocess()
{
    for(int i=2;i<K;i++)
    {
        if(di[i]==0)
        {
            for(int j=i;j<K;j+=i)
            {
                di[j]=i ;
            }
        }
    }
}
int dvs(int x)
{
    while(x>1)
    {
        int tmp=di[x],cnt=0;
        for(;x%tmp==0;x/=tmp,cnt++);
        if((tmp&1)&&(cnt&1))return -1;
    }
    return 1 ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,u,v,i,j,x ;
    cin >> n ;
    preprocess();
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=1;i<=n;i++)
    {
        cin >> x ;
        a[i]=dvs(x);
        ans+=(a[i]==1);
    }
    decompose(1);
    cout << ans ;
}
