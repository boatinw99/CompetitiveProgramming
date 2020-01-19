#include<bits/stdc++.h>
using namespace std ;
const int md = 1e9+7 ,B = 59 ;
int b=0;
int dx[8]={1,1,1,-1,-1,-1,0,0};
int dy[8]={1,0,-1,1,0,-1,1,-1};
int F[B][B],M[B][B],z[B][B];
int dp[B][B];
bool visited[B];
void multi(int x[B][B],int y[B][B])
{
    int i,j,k ;
    for(i=0;i<b;i++)for(j=0;j<b;j++)for(k=0;k<b;k++)
        z[i][j]=(z[i][j]+x[i][k]*1ll*y[k][j])%md ;
    for(i=0;i<b;i++)for(j=0;j<b;j++)x[i][j]=z[i][j],z[i][j]=0;
}
void pow(int n)
{
    if(n==1)return ;
    pow(n/2);
    multi(F,F);
    if(n&1)multi(F,M);
}
void construct(int x,int y)
{
    int sz=y-x>>1,i,j ;
    for(i=0;i<=sz;i++)dp[x+i][x]=dp[x][x+i]=dp[x+i][y]=dp[x][y-i]=
        dp[y][x+i]=dp[y-i][x]=dp[y][y-i]=dp[y-i][y]=b+i;
    b+=sz+1;
    if(x+1>=y)return ;
    construct(x+1,y-1);
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T,n,i,j,k,m,x,y,u,v ;
    cin >> T ;
    while(T--)
    {
        cin >> m >> x >> y >> n ;
        b=0;
        construct(1,m);
        k=dp[x][y];
        memset(F,0,sizeof F);
        memset(M,0,sizeof M);
        for(i=0;i<B;i++)visited[i]=0;
        for(i=1;i<=m+1>>1;i++)for(j=1;j<=m+1>>1;j++){
            u=dp[i][j];
            if(!visited[u]++)
            for(int d=0;d<8;d++)
            {
                if(i+dx[d]>=1&&i+dx[d]<=m&&j+dy[d]>=1&&j+dy[d]<=m)
                {
                    v=dp[i+dx[d]][j+dy[d]];
                    F[v][u]++; M[v][u]++;
                }
            }
        }
        pow(n);
        int ans=0;
        for(i=0;i<b;i++)ans=(ans+F[i][k])%md;
        cout << ans << '\n' ;
    }
}
