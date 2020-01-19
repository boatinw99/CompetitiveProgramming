#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> pli ;
#define fi first
#define se second
const ll inf = 1e18 ;
const int N = 1e5+9 , K = 11 ;
ll dp[K][N],a[N],sum2[N],qs[N];
void compute(int i,int l,int r,int x,int y)
{
    if(l>r)return ;
    pli bst = {inf,0};
    int mid = l+r>>1 ;
    for(int j=x;j<=min(y,mid);j++)
    {
        bst=min(bst,{dp[i-1][j]+sum2[mid]-sum2[j]-(qs[mid]-qs[j])*(j+1),j});
    }
    dp[i][mid]=bst.fi;
    int m = bst.se ;
    compute(i,l,mid-1,x,m);
    compute(i,mid+1,r,m,y);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,k,i,j ;
    cin >> n >> k ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        qs[i]=qs[i-1]+a[i];
        sum2[i]=sum2[i-1]+a[i]*i;
    }
    for(i=1;i<=n;i++)dp[0][i]=inf ;
    for(i=1;i<=k;i++)compute(i,1,n,0,n-1);
    cout << dp[k][n];
}
