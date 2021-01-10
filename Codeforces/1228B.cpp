#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<ll,int> pli ;
typedef pair<int,ll> pil ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll INF = 1e18 ;
const int N = 1e3+9 , inf = 1e9 , mod = 1e9+7 ;
int n,m ;
int b[N][N];
int powap(int a,int p)
{
    if(p==0)return 1 ;
    int ret = powap(a,p>>1);
    ret=1ll*ret*ret%mod;
    if(p&1)ret=1ll*ret*a%mod;
    return ret ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    int u ;
    bool non = 0 ;
    for(int i=1;i<=n;i++)
    {
        cin >> u ;
        for(int j=1;j<=u;j++)
        {
            b[i][j]=1;
        }
        b[i][u+1]=2 ;
    }
    for(int j=1;j<=m;j++)
    {
        cin >> u ; 
        for(int i=1;i<=u;i++)
        {
            if(b[i][j]==2)
            {
                non=1;
            }
            b[i][j]=1;
        }
        if(b[u+1][j]==1)
        {
            non = 1 ;
        }
        b[u+1][j]=2;
    }
    int cnt = 0 ; 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(b[i][j]==0)cnt++;
        }
    }
    if(non)
    {
        cout << "0" << '\n';
        return 0 ;
    } 
    cout << powap(2,cnt) << '\n' ;
    return 0 ; 
}