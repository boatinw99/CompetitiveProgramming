#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 5009 ,inf = 1e9 ;
int dp[N][N],cst[N][N],a[N];
void compute(int i,int l,int r,int optx,int opty)
{
    if(l>r)return ;
    int mid = l+r>>1;
    pii bst = {inf,0};
    for(int j=optx;j<=min(opty,mid-1);j++)
    {
        bst=min(bst,{dp[i-1][j]+cst[j+1][mid],j});
    }
    dp[i][mid]=bst.fi ;
    int opt = bst.se ;
    compute(i,l,mid-1,optx,opt);
    compute(i,mid+1,r,opt,opty);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,k,i,j ;
    cin >> n >> k ;
    for(i=1;i<=n;i++)cin >> a[i] ;
    for(i=n;i>=1;i--)
    {
        for(j=i+1;j<=n;j++)
        {
            cst[i][j]=cst[i][j-1]+cst[i+1][j]-cst[i+1][j-1]+(a[i]>a[j]);
        }
    }
    for(i=1;i<=n;i++)dp[0][i]=inf ;
    for(i=1;i<=k;i++)compute(i,1,n,0,n-1);
    cout << dp[k][n];
}
