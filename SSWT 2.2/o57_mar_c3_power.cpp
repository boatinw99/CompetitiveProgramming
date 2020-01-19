#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 4e5+9 ;
vector<int> g[N];
int a[N],depth[N],n,dp[N],pos[N],add[N],p=1,cst[N],qs[N];
int st[N<<2];
bool cycle[N],vst[N];
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=cst[l];
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
int findmax(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0;
    if(l>=x&&r<=y)return st[m];
    return max(findmax(l,mid,x,y,m<<1),findmax(mid+1,r,x,y,m<<1|1));
}
pii dfs0(int u,int v)
{
    depth[u]=depth[v]+1;
    vst[u]++;
    for(auto it:g[u])
    {
        if(!vst[it])
        {
            pii ret = dfs0(it,u);
            if(ret.se>0){pos[p++]=u,cycle[u]++;}
            if(ret.se<0)return ret ;
            if(ret.fi==u)return {u,-1};
            if(ret.se!=0)return ret ;
        }
        else if(it!=v)
        {
            cycle[u]++;
            pos[p++]=u;
            return {it,1};
        }
    }
    return {0,0};
}
void dfs1(int u,int v)
{
    pii mx = {0,0};
    dp[u]=a[u];
    for(auto it:g[u])
    {
        if(it!=v)
        {
            dfs1(it,u);
            if(dp[it]>mx.fi)
            {
                mx.se=mx.fi;
                mx.fi=dp[it];
            }
            else if(dp[it]>mx.se)mx.se=dp[it];
        }
    }
    dp[u]+=mx.fi+mx.se ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,u,v,ans=0 ;
    cin >> n ;
    for(i=1;i<=n;i++)cin >> a[i] ;
    for(i=1;i<=n;i++)
    {
        cin >> u >> v ;
        u++;
        v++;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    int root = dfs0(1,1).fi ;
    memset(vst,0,sizeof vst);
    for(i=1;i<=n;i++)
    {
        if(cycle[i]==0)continue ;
        int mx1=0,mx2=0,mx3=0 ;
        for(auto it:g[i])
        {
            if(!cycle[it])
            {
                dfs1(it,i);
                if(dp[it]>mx1)
                {
                    mx3=mx2;
                    mx2=mx1;
                    mx1=dp[it];
                }
                else if(dp[it]>mx2)
                {
                    mx3=mx2;
                    mx2=dp[it];
                }
                else if(dp[it]>mx3)mx3=dp[it];
            }
        }
        dp[i]=mx1+a[i];
        add[i]=mx2;
        ans=max(ans,mx1+mx2+mx3+a[i]);
    }
    reverse(pos+1,pos+p);
    p--;
    int sum=0;
    for(i=1;i<=p;i++)pos[i+p]=pos[i];
    p<<=1;
    for(i=1;i<=p;i++)
    {
        qs[i]=qs[i-1]+dp[pos[i]];
        cst[i]=qs[i]+add[pos[i]];
    }
    construct(1,p,1);
    for(i=1;i+p/2-1<=p;i++)
    {
        ans=max(ans,findmax(1,p,i+1,i+p/2-1,1)+add[pos[i]]-qs[i-1]);
    }
    cout << ans ;
}
