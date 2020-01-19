#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9,MOD=1e9+7;
typedef long long ll ;
pair<int,int> a[N];
stack<pair<int,ll> > st;
ll bi[N];
void update(int in,ll co)
{
    for(;in;in-=in&-in)
    {
        bi[in]=(co+bi[in])%MOD;
    }
}
ll findset(int in)
{
    ll x=0;
    for(;in<N;in+=in&-in)
    {
        x+=bi[in];
        x%=MOD;
    }
    return x;
}
main()
{
    int n,i,j ;
    ll x,ans=0 ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d %d",&a[i].first,&a[i].second);
    sort(a+1,a+1+n);
    for(i=1;i<=n;i++)
    {
        if(a[i].first!=a[i-1].first)
        {
            while(!st.empty())
            {
                update(st.top().first,st.top().second);
                st.pop();
            }
        }
        x=findset(a[i].second+1);
        ans+=(x+1);
        ans%=MOD;
        st.push({a[i].second,x+1});
    }
    printf("%lld",ans);
}
