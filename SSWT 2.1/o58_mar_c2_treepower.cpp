#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
typedef long long ll ;
#define fi first
#define se second
const int N = 1e5+9,md=9907 ;
vector<int> g[N];
int L[N],X[N],Y[N],Z[N],sub[N];
int sum1,mul1,sum2,mul2;
pii num[N]; ///dist0 dist1
bool vst[N];
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
    return u;
}
void dfs3(int u,int depth)
{
    if(depth>4)return ;
    if(depth==2)
    {
         mul2=(mul2+sum2*X[u])%md;
         sum2=(sum2+X[u])%md;
    }
    vst[u]++;
    num[u]={0,0};
    for(auto it:g[u])
    {
        if(!vst[it])
        {
            dfs3(it,depth+1);
            num[u].fi=(num[u].fi+X[it])%md;
            num[u].se=(num[u].se+num[it].fi)%md;
        }
    }
    if(depth==1)
    {
        for(auto it:g[u])
        {
            if(!vst[it])
            {
                num[it].se=(num[it].se+num[u].fi-X[it]+md)%md;
            }
        }
    }
    vst[u]=0;
}
void dfs4(int u,int depth,int ctd)
{
    if(depth>2)return ;
    if(depth==1)
    {
        int tmp = (mul1-(sum1-X[u]+md)*X[u]%md+(sum1-X[u]+md)*num[u].se+md)%md;
        L[u]=(L[u]+tmp)%md;
    }
    else L[u]=(L[u]+num[u].se*X[ctd])%md;
    vst[u]++;
    for(auto it:g[u])if(!vst[it])dfs4(it,depth+1,ctd);
    vst[u]=0;
}
void dcp(int u)
{
    dfs1(u);
    int ctd=dfs2(u,u,sub[u]);
    vst[ctd]++;
    sum1=mul1=sum2=mul2=0;
    for(auto it:g[ctd])
    {
        if(!vst[it])
        {
            mul1=(mul1+sum1*X[it])%md;
            sum1=(sum1+X[it])%md;
        }
    }
    for(auto it:g[ctd])if(!vst[it])dfs3(it,1);
    for(auto it:g[ctd])if(!vst[it])dfs4(it,1,ctd);
    L[ctd]=(L[ctd]+mul2)%md;
    //printf("aaa %d %d\n",ctd,L[ctd]);
    for(auto it:g[ctd])if(!vst[it])dcp(it);
}
main()
{
    int n,i,j,u,v ;
    cin >> n ;
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    for(i=1;i<=n;i++)
    {
        cin >> X[i] >> Y[i] >> Z[i] ;
        X[i]%=md;
        Y[i]%=md;
        Z[i]%=md;
    }
    dcp(1);
    int ans=0;
    for(i=1;i<=n;i++)ans=(ans+L[i]*Y[i]+Z[i])%md;
    cout << ans ;
}
