#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int md = 163577857,LOG=31,N=50009,B=101,inf=2e9 ;
int pow2[LOG];
int p[N];
int F[LOG][B][B];
int f[B];
int qs[B];
int bs ;
int powap(int a,int p)
{
    if(p==1)return a ;
    int r=powap(a,p/2);
    r=1ll*r*r%md;
    if(p&1)r=1ll*r*a%md ;
    return r ;
}
int query(int n)
{
    int ans[B],temp[B],i,j,d,k ;
    if(n<=bs)return qs[n];
    memset(temp,0,sizeof temp);
    for(i=0;i<bs;i++)ans[i]=f[bs-i-1];
    ans[bs]=f[bs];
    n-=bs;
    for(d=0;d<LOG;d++)if(pow2[d]&n){
        for(i=0;i<=bs;i++)for(j=0;j<=bs;j++)
                temp[i]=(temp[i]+1ll*F[d][i][j]*ans[j])%md ;
        for(i=0;i<=bs;i++)ans[i]=temp[i],temp[i]=0;
    }
    return ans[bs];
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int i,j,n,m,k,d,h,x,K,am ;
    ll ans = 0 ;
    pow2[0]=1;
    for(i=1;i<LOG;i++)pow2[i]=pow2[i-1]*2;
    cin >> n >> h >> x >> K ;
    bs=K;
    for(i=1;i<=n;i++)cin >> p[i];
    sort(p+1,p+1+n);
    for(i=0;i<bs;i++)
    {
        cin >> f[i];
        f[i]%=md ;
    }
    for(i=1;i<=bs;i++)qs[i]=(qs[i-1]+f[i-1])%md;
    f[bs]=qs[bs];
    ///store F[0][][]
    for(j=0;j<bs;j++)
    {
        cin >> F[0][0][j];
        F[0][0][j]%=md ;
        F[0][bs][j]=F[0][0][j];
    }
    for(i=1;i<bs;i++)F[0][i][i-1]=1;
    F[0][bs][bs]=1;
    for(d=1;d<LOG;d++)for(i=0;i<=bs;i++)for(j=0;j<=bs;j++)for(k=0;k<=bs;k++)
        F[d][i][j]=(F[d][i][j]+1ll*F[d-1][i][k]*F[d-1][k][j])%md ;
    am=query(h);
    ///sliding
    int l=-inf;
    for(i=1;i<=n;i++)
    {
        l=p[i]-x+1;
        if(l<=0)ans=(ans+query(p[i])+am-query(l+h-1)+md)%md;
        else ans=(ans+query(p[i])-query(l-1)+md)%md;
    }
    cout << ans*1ll*powap(am,md-2)%md  ;
}
