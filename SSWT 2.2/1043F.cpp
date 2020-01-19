#include<bits/stdc++.h>
using namespace std ;
const int N = 3e5+9 , mod=1e9+7 ;
int cnt[N],fact[N],inv[N],dp[N];
int pow2(int a,int m)
{
    if(m==0)return 1 ;
    int ret = pow2(a,m>>1);
    ret=1ll*ret*ret%mod;
    if(m&1)ret=ret*1ll*a%mod;
    return ret ;
}
void preprocess()
{
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=fact[i-1]*1ll*i%mod;
    for(int i=0;i<N;i++)inv[i]=pow2(fact[i],mod-2);
}
void sub(int &a,int b)
{
    a=(a-b+mod)%mod;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    preprocess();
    cin >> n ;
    for(int i=1,x ;i<=n;i++)
    {
        cin >> x ;
        cnt[x]++;
    }
    for(int i=1;i<N;i++)
    {
        for(int j=i+i;j<N;j+=i)cnt[i]+=cnt[j];
    }
    for(int ans=1;ans<=7;ans++)
    {
        memset(dp,0,sizeof dp);
        for(int i=N-1;i>=1;i--)
        {
            if(cnt[i]<ans)continue;
            dp[i]=1ll*fact[cnt[i]]*inv[ans]%mod*inv[cnt[i]-ans]%mod;
            //printf("aa %d %d (%d %d)\n",i,dp[i],ans,cnt[i]);
            for(int j=i+i;j<N;j+=i)
            {
                sub(dp[i],dp[j]);
            }
        }
        if(dp[1]>0)
        {
            cout << ans ;
            return 0 ;
        }
    }
    cout << "-1" ;
    return 0 ;
}
