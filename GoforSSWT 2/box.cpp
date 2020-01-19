#include<bits/stdc++.h>
using namespace std ;
const int N = 39 ;
char s[N][N];
int a[N][N];
queue<pair<int,int> > q;
pair<int,int> d[4]={{1,0},{-1,0},{0,1},{0,-1}};
bool b[N][N];
main()
{
    int n,m,i,j,x,y,d1 ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf(" %c",&s[i][j]);
        }
    }
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            if(s[i][j]==s[i][j+1]&&s[i][j]==s[i+1][j]&&
               s[i][j]==s[i+1][j+1]&&s[i][j]=='.')
            {
                a[i][j]=1;
            }
        }
    }
    for(j=1;j<m;j++)if(a[1][j]==1)q.push({1,j}),b[1][j]++;
    while(!q.empty())
    {
        x=q.front().first; y=q.front().second;
        q.pop();
        for(d1=0;d1<4;d1++)
        {
            if(a[x+d[d1].first][y+d[d1].second]==1&&
               b[x+d[d1].first][y+d[d1].second]==0)
            {
                b[x+d[d1].first][y+d[d1].second]++;
                q.push({x+d[d1].first,y+d[d1].second});
            }
        }
    }
    for(j=1;j<m;j++)
    {
        if(b[n-1][j]==1)
        {
            printf("yes");
            return 0 ;
        }
    }
    printf("no");
}
