#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+9;
typedef long long ll ;
vector<int> key ;
vector<int>::iterator it ;
ll bi1[N],bi2[N];
int a[N];
void update(int in,ll co1,ll co2)
{
    for(;in>0;in-=in&-in)
    {
        bi1[in]+=co1;
        bi2[in]+=co2;
    }
}
pair<ll,ll> sum(int in)
{
    ll x=0,y=0;
    for(;in<N;in+=in&-in)
    {
        x+=bi1[in];
        y+=bi2[in];
    }
    return {x,y};
}
main()
{
    int n,i,j ;
    pair<ll,ll> co;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        key.push_back(a[i]);
    }
    ll ans = 0;
    sort(key.begin(),key.end());
    for(i=1;i<=n;i++)
    {
        it=lower_bound(key.begin(),key.end(),a[i]);
        j=it-key.begin()+1;
        co=sum(j+1);
        ans+=co.second;
        update(j,1,co.first);
    }
    printf("%I64d",ans);
}
