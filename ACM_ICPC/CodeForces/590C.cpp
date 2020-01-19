#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 1e3+9 , inf = 1e7 ;
queue<pair<pii,int>> q ;
pii d[4]={{0,1},{0,-1},{1,0},{-1,0}};
int a[N][N];
int dp[N][N][4] ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ; 
    cin >> n >> m ;
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=1;k<=3;k++)dp[i][j][k]=inf+9 ; 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c ;
            cin >> c ;
            if(c=='#')a[i][j]=-1;
            else if(c=='.');
            else a[i][j]=c-'0',q.push({{i,j},c-'0'}),dp[i][j][c-'0']=0;
        }
    }
    for(;!q.empty();)
    {
        pair<pii,int> now = q.front(); q.pop();
        for(int i=0;i<4;i++)
        {
            int x1 = d[i].fi+now.fi.fi;
            int y1 = d[i].se+now.fi.se;
            if(x1>=1&&x1<=n&&y1>=1&&y1<=m&&dp[x1][y1][now.se]>=inf&&a[x1][y1]!=-1)
            {
                dp[x1][y1][now.se]=dp[now.fi.fi][now.fi.se][now.se]+1;
                q.push({{x1,y1},now.se});
            }
        }
    }
    int ans = inf;
    int mn13 = inf , mn12 = inf ,mn23 = inf ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i][j]==1)mn13=min(mn13,dp[i][j][3]-1),mn12=min(mn12,dp[i][j][2]-1);
            if(a[i][j]==2)mn23=min(mn23,dp[i][j][3]-1);
            ans=min(ans,dp[i][j][1]+dp[i][j][2]+dp[i][j][3]-2);
            //printf("checkpls i=%d j=%d 1=%d 2=%d 3=%d -> ans=%d\n",i,j,dp[i][j][1],dp[i][j][2],dp[i][j][3],ans);
        }
    }
    ans = min({ans,mn13+mn23,mn12+mn13,mn12+mn23});
    //printf("check %d %d %d\n",mn12,mn13,mn23);
    if(ans>=n*m)cout << "-1" << '\n' ;
    else cout << ans << '\n' ;
    return 0 ;
}