#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N = 1e6+9,MAX=1e9 ;
vector<char> a[N];
vector<int> dp[N][3];
queue<pair<pii,int> > q;///x,y,direction
int dx[3]={1,-1,0};
int dy[3]={0,0,1};
/// up down right
main()
{
    int n,m,s,i,j,k ;
    char c ;
    cin >> n >> m >> s ;
    for(i=1;i<=n;i++)
    {
        a[i].emplace_back('#');
        for(j=0;j<3;j++)dp[i][j].emplace_back(MAX);
        for(j=1;j<=m;j++)
        {
            cin >> c ;
            a[i].emplace_back(c);
            for(k=0;k<3;k++)dp[i][k].emplace_back(MAX);
        }
    }
    dp[s][1][0]=-1;
    q.push({{s,0},1});
    while(!q.empty())
    {
        int x=q.front().fi.fi,y=q.front().fi.se,drc=q.front().se;
        q.pop();
        if(y==m)
        {
            cout << dp[x][drc][y];
            return 0 ;
        }
        //printf("aa %d %d %d | %d\n",x,y,drc,dp[x][drc][y]);
        for(int d=0;d<3;d++)
        {
            int px=x+dx[d],py=y+dy[d];
            while(px>=1&&px<=n&&py>=1&&py<=m&&
            dp[x][drc][y]+1<dp[px][d][y]&&a[px][py]=='.')
            {
                //printf("gg");
                q.push({{px,py},d});
                dp[px][d][py]=dp[x][drc][y]+1;
                px+=dx[d],py+=dy[d];
            }
        }
    }
    cout << "-1" ;
}
