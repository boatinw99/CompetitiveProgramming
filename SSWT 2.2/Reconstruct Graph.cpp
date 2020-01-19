#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 , mod = 1e9+7 ;
int rnk[N];
vector<int> g[N],comp[N];
int pow2(int a,ll p)
{
    if(p==0)return 1 ;
    int ret = pow2(a,p>>1);
    ret=1ll*ret*ret % mod ;
    if(p&1)ret=1ll*ret*a % mod ;
    return ret ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,u,v ;
    bool im = 0 ;
    ///pow2[0]=1;
    ///for(int i=1;i<N;i++)pow2[i]=pow2[i-1]*2 %mod;
    cin >> n >> m ;
    for(int i=1;i<=n;i++)cin >> rnk[i] ,comp[rnk[i]].emplace_back(i);
    for(int i=2;i<=n;i++)if(rnk[i]==0)im++;
    for(int i=1;i<=m;i++)
    {
        cin >> u >> v ;
        if(rnk[u]<rnk[v])swap(u,v);
        if(abs(rnk[u]-rnk[v])>1)im++;
        g[u].emplace_back(v);
    }
    for(int i=1;i<n;i++)if(!comp[i].empty()&&comp[i-1].empty())im++;
    if(im)
    {
        cout << "0" ;
        return 0 ;
    }
    int ans = 1 ;
    ll  all = 0 ;
    for(int i=1;!comp[i].empty();i++)
    {
        int pre=comp[i-1].size(),now=comp[i].size();
        ll same=0;
        for(auto it:comp[i])
        {
            int add = 0 ;
            for(auto it1:g[it])
            {
                if(rnk[it]==rnk[it1])same++;
                else add++;
            }
            if(add==0)ans=1ll*ans*(pow2(2,pre)-1)%mod;
            else ans=1ll*ans*(pow2(2,pre-add))%mod;
        }
        all+=now*1ll*(now-1)/2-same;
        if(all>=mod-1)all-=mod-1 ;
    }
    cout << 1ll*ans*pow2(2,all)%mod ;
    return 0 ;
}
