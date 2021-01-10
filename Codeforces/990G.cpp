#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 2e5+9 , M = 200001;
vector<pii> factor[N];
vector<int> divisor[N],g[N];
ll ans[N],gcd[N],tmp[N],post[N];
bool vst[N];
int sieve[N],clr[N],n,sub[N] ;
void getdivisor(int idx,int val,int cur)
{
    if(cur==factor[idx].size())
    {
        divisor[idx].push_back(val);
        return ; 
    }
    for(int i=0,mul=1;i<=factor[idx][cur].se;i++,mul*=factor[idx][cur].fi)
    {
        getdivisor(idx,val*mul,cur+1);
    }
}
void pre_compute()
{
    sieve[1]=1;
    for(int i=2;i<N;i++)
    {
        if(sieve[i]==0)    
        {
            for(int j=i;j<N;j+=i)
            {
                if(!sieve[j])sieve[j]=i;
            }
        }
    }
    for(int i=1;i<N;i++)
    {
        int cur = i ;
        while(cur>1)
        {
            int div = sieve[cur],cnt=0 ;
            while(cur%div==0)
            {
                cur/=div;
                cnt++;
            }
            factor[i].push_back({div,cnt});
        }
    }
    for(int i=1;i<N;i++)
    {
        getdivisor(i,1,0);
        sort(divisor[i].begin(),divisor[i].end(),greater<int>());
    }
}
void compute_ans(int x)
{
    for(auto it:divisor[x])
    {
        ans[it]+=gcd[it];
        post[it]+=gcd[it];
    }
}
void add(int x,int cst)
{
    for(auto it:divisor[x])
    {
        gcd[it]+=cst;
    }
}
void dfs0(int u)
{
    sub[u]=1;
    vst[u]++;
    for(auto it:g[u])
    {
        if(!vst[it])dfs0(it),sub[u]+=sub[it];
    }
    vst[u]=0;
}
int dfs1(int u,int v,int sz)
{
    for(auto it:g[u])
    {
        if(it!=v&&!vst[it]&&sub[it]>sz/2)return dfs1(it,u,sz);
    }
    return u ;
}
void dfs_ans(int u,int gc)
{
    vst[u]++;
    gc=__gcd(gc,clr[u]);
    compute_ans(gc);
    for(auto it:g[u])
    {
        if(!vst[it])
        {
            dfs_ans(it,gc);
        }
    }
    vst[u]=0;
}
void dfs_add(int u,int gc,int cst)
{
    vst[u]++;
    gc=__gcd(gc,clr[u]);
    add(gc,cst);
    for(auto it:g[u])
    {
        if(!vst[it])
        {
            dfs_add(it,gc,cst);
        }
    }
    vst[u]=0;
}
void decompose(int u)
{
    dfs0(u);
    int ctd = dfs1(u,u,sub[u]);
    vst[ctd]++;
    add(clr[ctd],1);
    ans[clr[ctd]]++;
    for(auto it:g[ctd])
    {
        if(!vst[it])
        {
            dfs_ans(it,0);
            dfs_add(it,clr[ctd],1);
        }
    }
    add(clr[ctd],-1);
    for(auto it:g[ctd])
    {
        if(!vst[it])dfs_add(it,clr[ctd],-1);
    }
    for(auto it:g[ctd])
    {
        if(!vst[it])
        {
            decompose(it);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    pre_compute();
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> clr[i];
    }
    for(int i=1,u,v ;i<n;i++)
    {
        cin >> u >> v; 
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    decompose(1);
    for(int i=M-1;i>=1;i--)
    {
        for(int j=1;j<divisor[i].size();j++)
        {
            int it = divisor[i][j];
            ans[it]-=post[i];
            post[it]-=post[i];
        }
    }
    for(int i=1;i<M;i++)
    {
        if(ans[i])
        {
            cout << i << " " << ans[i] << '\n' ;
        }
    }
    return 0 ;
}