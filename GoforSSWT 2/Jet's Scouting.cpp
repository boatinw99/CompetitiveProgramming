#include<bits/stdc++.h>
using namespace std ;
const int N=309;
char a[N][N];
int dp[N][N][4];
bool b[N][N][4];
queue<pair<pair<int,int>,int> > q;
pair<int,int> dix[4][2]={{{0,1},{0,-1}},{{1,0},{-1,0}},
{{-1,-1},{1,1}},{{1,-1},{-1,1}}};
int ter[4]={1,0,3,2};
///LR UD LU RU
main()
{
    int n,m,k,i,j,x,y,d,dx,dy,x1,y1 ;
    scanf("%d %d %d",&n,&m,&k);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf(" %c",&a[i][j]);
            if(a[i][j]=='J')
            {
                b[i][j][0]=1;
                b[i][j][1]=1;
                b[i][j][2]=1;
                b[i][j][3]=1;
                q.push({{i,j},0});
                q.push({{i,j},1});
                q.push({{i,j},2});
                q.push({{i,j},3});
            }
        }
    }
    int p;
    while(!q.empty())
    {
        x=q.front().first.first ;
        y=q.front().first.second;
        d=q.front().second;
        q.pop();
        p=ter[d];
        for(i=0;i<2;i++)
        {
            dx=dix[p][i].first; dy=dix[p][i].second;
            x1=x+dx; y1=y+dy;
            for(;x1>0&&x1<=n&&y1>0&&y1<=m;x1+=dx,y1+=dy)
            {
                if(b[x1][y1][p]==1||a[x1][y1]=='#')
                {
                    break;
                }
                dp[x1][y1][p]=dp[x][y][d]+1;
                b[x1][y1][p]=1;
                q.push({{x1,y1},p});
            }
        }
    }
    int max1=INT_MAX;
    while(k--)
    {
        scanf("%d %d",&x,&y);
        max1=INT_MAX;
        for(i=0;i<4;i++)if(dp[x][y][i]>0)max1=min(max1,dp[x][y][i]);
        printf("%d\n",max1!=INT_MAX?max1-1:-1);
    }
}
