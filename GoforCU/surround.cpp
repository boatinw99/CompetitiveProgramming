#include<bits/stdc++.h>
using namespace std ;
const int N = 1009;
int a[N][N];
bool b[N][N];
int n,m,max1=0 ;
int di[8][2]={{0,1},{0,-1},{1,0},{-1,0},{-1,-1},{-1,1},{1,-1},{1,1}};
queue<pair<int,int> > q;
void bfs(int x,int y)
{
    int co=0,d,i,j,x1,y1,x2,y2 ;
    q.push({x,y});
    b[x][y]++;
    x1=x; y1=y; x2=x;  y2=y;
    while(!q.empty())
    {
        co++;
        x=q.front().first; y=q.front().second;
        x1=min(x1,x); y1=min(y1,y); x2=max(x2,x); y2=max(y2,y);
        q.pop();
        for(d=0;d<8;d++)
        {
            i=di[d][0]; j=di[d][1];
            if(x+i>=1&&x+i<=n&&y+j<=m&&y+j>=1&&
                    a[x+i][y+j]==1&&!b[x+i][y+j]++)
            {
                q.push({x+i,y+j});
            }
        }
    }
    if(x1!=1&&y1!=1&&x2!=n&&y2!=m&&co==(x2-x1+1)*(y2-y1+1))
    {
        max1=max(max1,co);
    }
}
main()
{
    int i,j ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i][j]&&!b[i][j])
            {
                bfs(i,j);
            }
        }
    }
    printf("%d",max1>0?max1:-1);
}
