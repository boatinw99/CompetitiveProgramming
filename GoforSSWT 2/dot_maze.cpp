#include<bits/stdc++.h>
using namespace std ;
stack<int> ans;
stack<pair<int,int> > query;
const int N = 409;
bool rock[N][N];
bool pass[N][N];
queue<pair<int,int> > q;
int pr=0;
int dix[4]={0,0,1,-1};
int diy[4]={1,-1,0,0};
void clearq(int n,int m)
{
    int x,y,i,j,x1,y1  ;
    while(!q.empty())
    {
        pr++; x=q.front().first;  y=q.front().second;
        q.pop();
        for(i=0;i<4;i++)
        {
            x1=x+dix[i]; y1=y+diy[i];
            if(x1<0||x1>n||y1<0||y1>m||rock[x1][y1]==1||
               pass[x1][y1]==1)
            continue;
            pass[x1][y1]++;
            q.push({x+dix[i],y+diy[i]});
        }
    }
}
main()
{
    int n,m,Q,x,y,i,j ;
    scanf("%d %d %d",&n,&m,&Q);
    while(Q--)
    {
        scanf("%d %d",&x,&y);
        rock[x][y]++;
        query.push({x,y});
    }
    for(i=0;i<n;i++)
    {
        if(rock[i][0]==0)
        {
            pass[i][0]++;
            q.push({i,0});
        }
        if(rock[i][m-1]==0)
        {
            pass[i][m-1]++;
            q.push({i,m-1});
        }
    }
    for(j=0;j<m;j++)
    {
        if(rock[0][j]==0&&pass[0][j]==0)
        {
            pass[0][j]++;
            q.push({0,j});
        }
        if(rock[n-1][j]==0&&pass[n-1][j]==0)
        {
            pass[n-1][j]++;
            q.push({n-1,j});
        }
    }
    clearq(n-1,m-1);
    ///
    int x1,y1;
    while(!query.empty())
    {
        x=query.top().first;
        y=query.top().second;
        query.pop();
        bool b=0;
        rock[x][y]=0;
        for(i=0;i<4;i++)
        {
            x1=x+dix[i]; y1=y+diy[i];
            if(x1<0||x1>=n||y1<0||y1>=m||rock[x1][y1]==1||
               pass[x1][y1]==0)continue;
            b++;
            break;
        }
        if(x==0||x==n-1||y==0||y==m-1)b++;
        if(b)pass[x][y]++,q.push({x,y});
        ans.push(pr);
        clearq(n-1,m-1);
    }
    while(!ans.empty())
    {
        printf("%d\n",ans
               .top());
        ans.pop();
    }
}
