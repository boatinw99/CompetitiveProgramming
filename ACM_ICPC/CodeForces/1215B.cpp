#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll INF = 1e18 ; 
const int N = 2e5+9 , inf = 2e9 , mod = 1e9+7 ;
int A[N],f[N];
map<ll,ll> mp ; 
vector<pll> V ;
void update(int i,int cnt)
{
    for(;i<N;i+=i&-i)
    {
        f[i]+=cnt;
    }
}
int getsum(int i)
{
    int sum = 0 ;
    for(;i;i-=i&-i)
    {
        sum+=f[i];
    }
    return sum ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    ll ans1=0,ans2=0;
    int mul=1 ;
    int sum1=1,sum2=0 ;
    for(int i=1;i<=n;i++)
    {
        cin >> A[i] ;
        if(A[i]>0)
        {
            mul*=1;
        }
        else mul*=-1;
        if(mul==1)
        {
            ans1+=sum2;//-
            ans2+=sum1;//+
        }
        else 
        {
            ans1+=sum1;
            ans2+=sum2;
        }
        sum1+=(mul==1);
        sum2+=(mul==-1);
    }
    cout << ans1 << " " << ans2 << '\n' ;
    return 0 ;
}