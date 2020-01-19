#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mid (l+r>>1)
const int N = 1e5+9 ,LOG = log2(N)+1;
const ll inf = 1e11 ;
int f[N],pos[N];
ll qs[N];
vector<ll> cc ;
void update(int i,int cst)
{
    for(;i;i-=i&-i)f[i]+=cst;
}
int getsum(int i)
{
    int x = 0 ;
    for(;i<N;i+=i&-i)x+=f[i];
    return x ;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,sz ;
    ll k,l,r ;
    cin >> n >> k ;
    for(i=1;i<=n;i++)
    {
        cin >> qs[i] ;
        qs[i]+=qs[i-1];
        cc.emplace_back(qs[i]);
    }
    sort(cc.begin(),cc.end());
    cc.resize(unique(cc.begin(),cc.end())-cc.begin());
    for(i=1;i<=n;i++)
    {
        auto it=lower_bound(cc.begin(),cc.end(),qs[i])-cc.begin()+1;
        pos[i]=it;
    }
    l = -inf , r = inf ;
    while(l+1<r)
    {
        ll sum = 0 ;
        for(i=1;i<=n;i++)update(pos[i],1);
        for(i=1;i<=n;i++)
        {
            auto it = lower_bound(cc.begin(),cc.end(),qs[i-1]+mid)-cc.begin()+1;
            sum+=getsum(it);
            update(pos[i],-1);
        }
        if(sum<k)r=mid;
        else l=mid ;
    }
    cout << l ;
}
