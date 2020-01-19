#include<bits/stdc++.h>
using namespace std ;
const int N = 3009 ;
int st[N][N],ed[N][N],qs1[N][N],qs2[N][N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,x1,x2,y1,y2 ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2 ;
        st[x1][y1]++;
        ed[x2][y2]++;
        qs1[x2][y1]++;///end to (1,n)
        qs2[x1][y2]++;
    }
    for(i=N-4;i>=1;i--)for(j=N-4;j>=1;j--)
        st[i][j]+=st[i][j+1]+st[i+1][j]-st[i+1][j+1];
    for(i=1;i<N;i++)for(j=1;j<N;j++)ed[i][j]+=ed[i-1][j]+ed[i][j-1]-ed[i-1][j-1];
    for(i=N-4;i>=1;i--)for(j=1;j<N;j++)
        qs1[i][j]+=qs1[i+1][j]+qs1[i][j-1]-qs1[i+1][j-1];
    for(i=1;i<N;i++)for(j=N-4;j>=1;j--)
        qs2[i][j]+=qs2[i-1][j]+qs2[i][j+1]-qs2[i-1][j+1];
    for(i=1;i<=m;i++)
    {
        cin >> x1 >> y1 >> x2 >> y2 ;
        int ans = 0 ;
        ans+=ed[N-5][y1-1]+ed[x1-1][N-5]-ed[x1-1][y1-1];
        ans+=st[x2+1][1]+st[1][y2+1]-st[x2+1][y2+1];
        ans-=qs1[x2+1][y1-1]+qs2[x1-1][y2+1];
        cout << n-ans << '\n' ;
    }
}
