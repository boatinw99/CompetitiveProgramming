#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> pli ;
#define mid (l+r>>1)
#define fi first
#define se second
const ll inf = 1e14 ;
const int N = 5009 ;
ll dp[N][N],cst[N][N],a[N];
void compute(int i,int l,int r,int optx,int opty)
{
    if(l>r)return ;
    pli bst = {-inf,0};
    for(int j=optx;j<=min(opty,mid);j++)
    {
        bst=max(bst,{dp[i-1][j]+cst[j+1][mid],j});
    }
    dp[i][mid]=bst.fi ;
    int opt=bst.se ;
    compute(i,l,mid-1,optx,opt);
    compute(i,mid+1,r,opt,opty);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T,i,j,n,m,k ;
    cin >> T ;
    for(i=1;i<N;i++)dp[0][i]=-inf ;
    while(T--)
    {
        cin >> n >> k ;
        for(i=1;i<=n;i++)cin >> a[i] ;
        for(i=1;i<=n;i++)
        {
            cst[i][i]=a[i];
            for(j=i+1;j<=n;j++)cst[i][j]=cst[i][j-1]|a[j];
        }
        for(i=1;i<=k;i++)compute(i,1,n,0,n-1);
        cout << dp[k][n] << '\n' ;
    }

}
