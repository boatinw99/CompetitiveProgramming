#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 4009,K=809,inf=1e9;
int dp[K][N],a[N][N],cst[N][N];
void compute(int i,int l,int r,int optl,int optr)
{
    if(l>r)return ;
    pii bst={inf,0};
    int m = min(optr,mid);
    for(int j=optl;j<=m;j++)
    {
        bst=min(bst,{dp[i-1][j]+cst[j+1][mid],j});
    }
    dp[i][mid]=bst.fi ;
    int opt=bst.se ;
    compute(i,l,mid-1,optl,opt);
    compute(i,mid+1,r,opt,optr);
}
main()
{
    int n,k,i,j ;
    scanf("%d %d\n",&n,&k);
    char buffer[10000];
    for(i=1;i<=n;i++)
    {
        gets(buffer);
        for(j=1;j<=n;j++)a[i][j]=buffer[2*(j-1)]-'0';
    }
    for(i=n;i>=1;i--)
    {
        for(j=i+1;j<=n;j++)
        {
            cst[i][j]=cst[i][j-1]+cst[i+1][j]-cst[i+1][j-1]+a[i][j];
        }
    }
    for(i=1;i<=n;i++)dp[0][i]=inf ;
    for(i=1;i<=k;i++)compute(i,1,n,0,n-1);
    printf("%d",dp[k][n]);
}
