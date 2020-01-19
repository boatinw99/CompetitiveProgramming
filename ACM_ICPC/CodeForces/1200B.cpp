#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,int> pli ;
typedef pair<ll,ll> pll ;
#define mid (l+r>>1)
#define fi first
#define se second
const ll INF = 1e18 ;
const int N = 109 , inf = 1e9 , mod = 1e9+7 ;
int n,m,k ;
int A[N];
int solve()
{
    for(int i=1;i<n;i++)
    {
        if(abs(A[i]-A[i+1])<=k||A[i]>A[i+1])
        {
            m+=A[i]-max(A[i+1]-k,0);
        }
        else 
        {
            m-=(A[i+1]-k)-A[i];
        }
        if(m<0)return 0 ;
    }
    return 1 ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int q ;
    cin >> q ;
    while(q--)
    {
        cin >> n >> m >> k ;
        for(int i=1;i<=n;i++)
        {
            cin >> A[i] ;
        }
        cout << (solve()==1?"YES":"NO") << '\n' ;
    }
    return 0 ;
}