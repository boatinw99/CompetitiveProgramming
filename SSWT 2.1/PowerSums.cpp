#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 309,md = 1e9+7 ;
int e[N],p[N],inv[N];
int c[N*2][N],r[N][N];
int a[N],f[N*2];
int n ;
void pow(ll x)
{
    int i,j;
    if(x<2*n)
    {
        for(i=0;i<n;i++)a[i]=c[x][i];
        return ;
    }
    pow(x/2);
    for(i=0;i<n;i++)for(j=0;j<n;j++)f[i+j]=(f[i+j]+1ll*a[i]*a[j])%md;
    for(i=n;i<2*n;i++)for(j=0;j<n;j++)f[j]=(f[j]+1ll*f[i]*c[i][j])%md;
    for(i=0;i<n;i++)a[i]=f[i];
    memset(f,0,sizeof f);
    if(x&1)
    {
        int g=a[n-1];
        for(i=n-1;i>0;i--)a[i]=(a[i-1]+1ll*g*c[n][i])%md;
        a[0]=1ll*g*c[n][0]%md;
    }
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T,i,j,q,mul ;
    ll x ;
    cin >> T ;
    while(T--){
        cin >> n >> q ;
        for(i=1;i<=n;i++)cin >> p[i];
        memset(e,0,sizeof e);
        e[0]=1; e[1]=p[1]; inv[1]=1;
        for(i=2;i<=n;i++){
            inv[i]=md-1ll*(md/i)*inv[md%i]%md;
            for(j=i-1,mul=1;j>=0;j--,mul*=-1){
                e[i]=(e[i]+1ll*mul*e[j]*p[i-j])%md;
            }
            e[i]=1ll*e[i]*inv[i]%md;
        }
        for(i=0;i<n;i++)c[i][i]=1;
        for(j=n-1,mul=1;j>=0;j--,mul*=-1)c[n][j]=(mul*e[n-j]+md)%md;
        for(i=n+1;i<2*n;i++){
            int g=c[i-1][n-1];
            for(j=n-1;j;j--)
                c[i][j]=(c[i-1][j-1]+1ll*g*c[n][j])%md;
            c[i][0]=1ll*g*c[n][0]%md;
        }
        while(q--){
            cin >> x ;
            memset(a,0,sizeof a);a[0]=1;
            x=(x-1)%(md-1);
            pow(x);
            int ans=0 ;
            for(i=0;i<n;i++)ans=(ans+1ll*a[i]*p[i+1])%md;
            cout << ans << " " ;
        }
        cout << '\n' ;
    }
}
