#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<ll,ll> pll ;
#define fi first
#define se second 
const ll PRM = 1e9+7  ;
const int N = 2e6+9;
int n,k,kmp[N];
int span[N],ans[N],upd[N];
char s[N];
pll val[N];
pll powPR[N];
pll pr = {37,79};
void construct()
{
    powPR[0]={1,1};
    for(int i=1;i<=n;i++)
    {
        val[i].fi = (val[i-1].fi*pr.fi + s[i])%PRM;
        val[i].se = (val[i-1].se*pr.se + s[i])%PRM; 
        powPR[i].fi=(powPR[i-1].fi*pr.fi)%PRM ;
        powPR[i].se=(powPR[i-1].se*pr.se)%PRM ;
    }
}
inline pll gethash(int l,int r)
{
    int len = r-l+1 ; 
    return {(val[r].fi - val[l-1].fi*powPR[len].fi+PRM*PRM)%PRM,(val[r].se - val[l-1].se*powPR[len].se +PRM*PRM)%PRM};
}
int furthest(int R)
{
    int l = R-1,r = n+1;
    while(l+1<r)
    {
        int mid = l+r >> 1 ;
        int len = mid-R+1;
        if(gethash(R,mid)==gethash(1,len))l=mid;
        else r = mid ; 
    } 
    return l ; 
}
void update(int l,int r)
{
    upd[l]++;
    upd[r+1]--;
}
void upall()
{
    int cnt = 0 ;
    for(int i=1;i<=n;i++)
    {
        cnt+=upd[i];
        ans[i]=min(cnt,1);
    }
}
int main()
{
    string c ; 
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> k ;
    cin >> c ;
    for(int i=0;i<n;i++)s[i+1]=c[i];
    construct();
    for(int i=1;i<=n;i++)
    {
        int j=1;
        for(;j<=n;j+=i)
        {
            if(gethash(j,j+i-1)!=gethash(1,i))
            {
                break ; 
            }
        }
        span[i]=j-1;
    }
    if(n==1&&k==1)update(1,1);
    for(int i=1;i<=n;i++)
    {
        if(1ll*i/k*k==i&&span[i/k]>=i)
        {
            int x = i/k ; 
            int fur = furthest(i+1);
            update(i,min(fur,i+x));  
        }
    }
    upall();
    for(int i=1;i<=n;i++)cout << ans[i] ;
    return 0 ; 
}