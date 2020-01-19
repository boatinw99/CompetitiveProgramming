#include<bits/stdc++.h>
using namespace std ;
const int N = 109 , mod = 1e9+7 ;
int F[N][N],M[N][N],c[N][N],a[N],f[N];
void multi(int a[N][N],int b[N][N])
{
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)for(int k=0;k<N;k++)
        c[i][j]=(c[i][j]+a[i][k]*1ll*b[k][j])%mod ;
    for(int i=0;i<N;i++)for(int j=0;j<N;j++)a[i][j]=c[i][j],c[i][j]=0;
}
void pow(int n)
{
    if(n==0)return ;
    pow(n>>1);
    multi(F,F);
    if(n&1)multi(F,M);
}
int pow2(int a,int p)
{
    if(p==0)return 1 ;
    int ret = pow2(a,p>>1);
    ret=1ll*ret*ret%mod;
    if(p&1)ret=1ll*ret*a%mod;
    return ret ;
}
int decrement(int cnt1,int cnt0)
{
    return cnt1*cnt0%mod;
}
int increment(int cntin,int cntout)
{
    return cntin*cntout%mod;
}
int main()
{
    int n,k,cnt0=0,cnt1=0 ;
    cin >> n >> k ;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        cnt0+=(a[i]==0);
        cnt1+=(a[i]==1);
    }
    int cst = 0 ;
    for(int i=1;i<=cnt0;i++)cst+=a[i];
    int sz = cnt0;
    for(int i=0;i<=min(cnt1,sz);i++)
    {
        if(i-1>=0)
        {
            F[i][i-1]=decrement(i,i);
            printf("a %d \n",F[i][i-1]);
        }
        F[i][i]=i*(cnt1-i)+(sz-i)*(i);
        if(i+1<=min(cnt1,sz))
        {
            F[i][i+1]=increment(i,cnt1-i);
        }
    }
    pow(k);
    int ans = F[0][cst] ,sum = 0 ;
    for(int i=0;i<N;i++)sum=(sum+F[i][cst])%mod;
    cout << 1ll*ans*pow2(sum,mod-2)%mod;
}
