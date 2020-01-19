#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> pli ;
#define mid (l+r>>1)
#define fi first
#define se second
const ll inf = 1e18 ;
const int N = 5009 ;
ll dp[N][N],cst[N][N],pos[N],wi[N],dist[N][N];
void precompute(int i,int l,int r,int x,int y)
{
    if(l>r)return ;
    pli bst={inf,0};
    for(int j=x;j<=min(mid,y);j++)
    {
        bst=min(bst,{dist[j][i]+dist[j][mid],j});
    }
    cst[i][mid]=bst.fi ;
    int m = bst.se ;
    precompute(i,l,mid-1,x,m);
    precompute(i,mid+1,r,m,y);
}
void compute(int i,int l,int r,int x,int y)
{
    if(l>r)return ;
    pli bst = {inf,0};
    for(int j=x;j<=min(mid-1,y);j++)
    {
        bst=min(bst,{dp[i-1][j]+cst[j+1][mid],j});
    }
    dp[i][mid]=bst.fi ;
    int m = bst.se ;
    compute(i,l,mid-1,x,m);
    compute(i,mid+1,r,m,y);
}
int main()
{
    //ios::sync_with_stdio(false),cin.tie(0);
    int n,k,i,j ;
    scanf("%d %d",&n,&k);
    for(i=1;i<=n;i++)
    {
        scanf("%lld %lld",&pos[i],&wi[i]);
    }
    for(i=1;i<=n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
            dist[i][j]=dist[i][j-1]+(pos[j]-pos[i])*wi[j];
        }
        for(j=i-1;j>=1;j--)
        {
            dist[i][j]=dist[i][j+1]+(pos[i]-pos[j])*wi[j];
        }
    }
    for(i=1;i<=n;i++)dp[0][i]=inf ;
    for(i=1;i<=n;i++)precompute(i,i,n,i,n);
    for(i=1;i<=k;i++)compute(i,1,n,0,n-1);
    printf("%lld",dp[k][n]);
    return 0 ;
}
