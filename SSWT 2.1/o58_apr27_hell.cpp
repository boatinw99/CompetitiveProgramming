#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int B = 109 ,md = 1e6+3 ;
int dx[3]={-1,0,1};
int dy[3]={1,1,1};
int F[B][B],M[B][B],dp[B][B];
bool A[B][B];
bool vst[B][B];
int c[B][B];
int n ;
queue<pii> q ;
void multi(int a[B][B],int b[B][B])
{
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)for(int k=1;k<=n;k++)
        c[i][j]=(c[i][j]+1ll*a[i][k]*b[k][j])%md ;
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)
        a[i][j]=c[i][j],c[i][j]=0;
}
void pow2(int n)
{
    if(n==1)return ;
    pow2(n>>1);
    multi(F,F);
    if(n&1)multi(F,M);
}
void clearq()
{
    while(!q.empty())
    {
        int x=q.front().fi,y=q.front().se;
        q.pop();
        for(int i=0;i<3;i++)
        {
            if(A[dx[i]+x][y+1])
            {
                dp[dx[i]+x][y+1]=(dp[x][y]+dp[dx[i]+x][y+1])%md;
                if(vst[dx[i]+x][y+1]==0)
                {
                    vst[dx[i]+x][y+1]=1;
                    q.push({dx[i]+x,y+1});
                }
            }
        }
    }
}
main()
{
    int m,k,i,j ;
    cin >> n >> m >> k ;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)cin >> A[i][j] ;
    }
    for(i=1;i<=n;i++)
    {
        memset(dp,0,sizeof dp);
        memset(vst,0,sizeof vst);
        if(A[i][1]==0)continue ;
        dp[i][1]=1;
        q.push({i,1});
        clearq();
        for(j=1;j<=n;j++)
        {
            F[i][j]=M[i][j]=dp[j][m];
        }
    }
    pow2(k);
    for(i=1;i<=n;i++)
    {
        int ans=0 ;
        for(j=1;j<=n;j++)ans=(ans+F[i][j])%md;
        cout << ans << '\n';
    }
}
