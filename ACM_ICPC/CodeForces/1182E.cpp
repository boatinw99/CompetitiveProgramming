#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ; 
#define fi first
#define se second
const ll INF = 1e18 ; 
const int N = 1e5+9 , mod = 1e9+7 , inf = 1e9 ,md=1e9+6;
ll F[5][5]={{1,1,1,1,1},{1,0,0,0,0},{0,1,0,0,0},{0,0,0,1,1},{0,0,0,0,1}},M[5][5],tmp[5][5];
ll pow2(ll a,ll p)
{
    if(p==0)return 1 ;
    ll ret = pow2(a,p>>1);
    ret=ret*ret%mod ;
    if(p&1)ret=ret*a%mod ;
    return ret ;
}
void multi(ll A[5][5],ll B[5][5])
{
    for(int i=0;i<5;i++)for(int j=0;j<5;j++)for(int k=0;k<5;k++)tmp[i][j]=(tmp[i][j]+A[i][k]*B[k][j])%(mod-1);
    for(int i=0;i<5;i++)for(int j=0;j<5;j++)A[i][j]=tmp[i][j],tmp[i][j]=0 ;
}
void pow(ll n)
{
    if(n==1)return ;
    pow(n>>1);
    multi(F,F);
    if(n&1)multi(F,M);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll n,f1,f2,f3,c,cnt1,cnt2,cnt3,ans=0;
    cin >> n >> f1 >> f2 >> f3 >> c ;
    for(int i=0;i<5;i++)for(int j=0;j<5;j++)M[i][j]=F[i][j]; 
    pow(n-3);
    cnt3 = pow2(f3,F[0][0]);
    cnt2 = pow2(f2,F[0][1]);
    cnt1 = pow2(f1,F[0][2]); 
    ll c2 = pow2(c,2*F[0][4]);
    ans=cnt1*cnt2%mod*cnt3%mod*c2%mod ;
    cout << ans << '\n' ;
    return 0 ;
}