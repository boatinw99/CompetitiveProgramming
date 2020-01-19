#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> pli ;
#define fi first
#define se second
const ll inf = 1e18 ;
const int N = 8009 , K = 809;
ll a[N],qs[N],dp[K][N];
void compute(int i,int l,int r,int optx,int opty)
{
    if(l>r)return ;
    pli bst = {inf,0};
    int mid=l+r>>1;
    for(int j=optx;j<=min(mid-1,opty);j++)
    {
        bst=min(bst,{dp[i-1][j]+(qs[mid]-qs[j])*(mid-j),j});
    }
    dp[i][mid]=bst.fi ;
    int opt = bst.se ;
    compute(i,l,mid-1,optx,opt);
    compute(i,mid+1,r,opt,opty);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,k,i,j ;
    cin >> n >> k ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        qs[i]=qs[i-1]+a[i];
    }
    for(i=1;i<=n;i++)dp[0][i]=inf ;
    for(i=1;i<=k;i++)compute(i,1,n,0,n-1);
    cout << dp[k][n] ;
}
