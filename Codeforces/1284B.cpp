#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second 
const ll INF = 1e18 ; 
const int N = 1e6+9 , inf = 2e9 , mod = 1e9+7 ;
pii A[N]; // min max ; 
ll f[N];
bool comp[N];
void update(int x)
{
    for(;x;x-=x&-x)
    {
        f[x]++;
    }
}
int getsum(int x)
{
    int sum = 0 ;
    for(;x<N;x+=x&-x)
    {
        sum+=f[x];
    }
    return sum ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,cntascent=0;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        int len ; 
        cin >> len ; 
        bool ascent = 0 ;
        A[i]={inf,-inf};
        for(int j=1;j<=len;j++)
        {
            int val ; 
            cin >> val ;
            val++; 
            if(val>A[i].fi)ascent++;
            A[i].fi = min(A[i].fi,val);
            A[i].se = max(A[i].se,val);
        }
        if(ascent)
        {
            cntascent++;
        }
        else update(A[i].se),comp[i]++;
    }
    ll ans = 1ll*2*cntascent*n-(1ll*cntascent*cntascent) ;
    for(int i=1;i<=n;i++)
    {
        if(comp[i])
        {
            ans+=getsum(A[i].fi+1);
        }
    }
    cout << ans << '\n' ;
    return 0 ;
}