#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 33 ;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool water[N][N],vst[N][N];
int a[N][N];
int cc[N][N];
queue<pii> q;
vector<pair<int,pii> > grid ;
void clearq(int p)
{
    while(!q.empty())
    {
        int x=q.front().fi,y=q.front().se ;
        water[x][y]++;
        cc[x][y]=p;
        q.pop();
        for(int i=0;i<4;i++)
        {
            if(a[x+dx[i]][y+dy[i]]==0&&vst[x+dx[i]][y+dy[i]]==0)
            {
                vst[x+dx[i]][y+dy[i]]++;
                q.push({x+dx[i],y+dy[i]});
            }
        }
    }
}
main()
{
    int i,j,n,m ;
    cin >> n >> m ;
    for(i=0;i<N;i++)for(j=0;j<N;j++)a[i][j]=-1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin >> a[i][j] ;
        }
    }
    for(j=1;j<=m;j++)
    {
        if(a[1][j]==0&&vst[1][j]==0)
        {
            q.push({1,j});
            clearq(-1);
        }
        if(a[n][j]==0&&vst[n][j]==0)
        {
            q.push({n,j});
            clearq(-1);
        }
    }
    for(i=1;i<=n;i++)
    {
        if(a[i][0]==0&&vst[i][0]==0)
        {
            q.push({i,0});
            clearq(-1);
        }
        if(a[i][m]==0&&vst[i][m]==0)
        {
            q.push({i,m});
            clearq(-1);
        }
    }
    int cnt=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i][j]==0&&cc[i][j]==0)
            {
                q.push({i,j});
                clearq(cnt+1);
                cnt++;
            }
        }
    }
    if(cnt<=1)
    {
        cout << 0 ;
        return 0 ;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            bool chk=0;
            for(int d=0;d<4;d++)
            {
                if(cc[i+dx[d]][j+dy[d]]==-1)chk=1;
            }
            if(chk==0&&a[i][j]>0)grid.push_back({a[i][j],{i,j}});
        }
    }
    sort(grid.begin(),grid.end());
    for(auto it:grid)
    {
        printf("aaaaa %d\n",it.fi);
    }
}
