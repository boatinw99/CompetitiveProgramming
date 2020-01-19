#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 309,md = 1e9+9,B=3;
const ll inf=1e18 ;
ll dp[N][N];
int ans[N];
int F[B][B],c[B][B];
int M[B][B]={{1,1,0},{1,0,0},{0,1,0}};
void multi(int a[B][B],int b[B][B])
{
    int i,j,k ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)for(k=0;k<B;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%md;
    for(i=0;i<B;i++)for(j=0;j<B;j++)a[i][j]=c[i][j],c[i][j]=0;
}
void pow(int n)
{
    if(n==1)return ;
    pow(n/2);
    multi(F,F);
    if(n&1)multi(F,M);
}
int powap(int a,int p)
{
    if(p==0)return 1 ;
    if(p==1)return a ;
    int r = powap(a,p/2);
    r=1ll*r*r%md;
    if(p&1)r=1ll*r*a%md;
    return r ;
}
int query(int n)
{
    int i,j ;
    for(i=0;i<B;i++)for(j=0;j<B;j++)F[i][j]=M[i][j];
    if(n<=2)return n+1;
    pow(n-2);
    //printf("aaaa %d %d\n",3*F[0][0],2*F[0][1]);
    return (1ll*3*F[0][0]+2*F[0][1]-F[2][0]-F[2][1]+3*1ll*md)%md;
}
main()
{
    int n,m,i,j,k,u,v,wi,T,x ;
    cin >> n >> m ;
    for(i=0;i<N;i++)for(j=0;j<N;j++)dp[i][j]=inf ;
    for(i=0;i<N;i++)dp[i][i]=0;
    while(m--)
    {
        cin >> u >> v >> wi ;
        dp[u][v]=dp[v][u]=wi ;
    }
    for(k=1;k<=n;k++)for(i=1;i<=n;i++)for(j=1;j<=n;j++)
        dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)dp[i][j]%=md;
    cin >> T ;
    while(T--)
    {
        cin >> u >> k ;
        x=query(k);
        for(i=1;i<=n;i++)
        {
            ans[i]=(1ll*ans[i]+dp[u][i]+x)%md;
        }
    }
    for(i=1;i<=n;i++)cout << ans[i] << " " ;
}
