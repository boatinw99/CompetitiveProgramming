#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e5+9 , M = 1e6+9 , mod = 1e9+7 ; 
int cnt[M];
ll ans[M];
ll powap(int a,ll p)
{
    if(p==0)return 1 ;
    ll ret = powap(a,p>>1);
    ret = ret*ret%mod;
    if(p&1)ret = ret*a%mod ;
    return ret ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        int val ; 
        cin >> val ;
        cnt[val]++;
    }
    for(int i=1;i<M;i++)
    {
        for(int j=i+i;j<M;j+=i)
        {
            cnt[i]+=cnt[j];
        }
    }
    ll pr = 0 ; 
    for(int i=M-1;i>1;i--)
    {
        if(cnt[i]==0)continue ;
        ans[i]=cnt[i]*powap(2,cnt[i]-1)%mod;
        for(int j=i+i;j<M;j+=i)ans[i]=ans[i]-ans[j]+mod,ans[i]%=mod;
        pr+=ans[i]*i%mod;
        pr%=mod ; 
    }
    cout << pr << '\n' ;
    return 0 ;
}