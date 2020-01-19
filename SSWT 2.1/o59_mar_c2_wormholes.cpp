#include<bits/stdc++.h>
using namespace std ;
const int K = 61,MAX=1e9 ;
struct node
{
    int x,y ;
};
node a[K];
int f[K][K];
int dist(node u,node v)
{
    return abs(u.x-v.x)+abs(u.y-v.y);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j,k ;
    cin >> n >> m ;
    for(i=0;i<K;i++)for(j=0;j<K;j++)f[i][j]=MAX;
    for(i=1;i<=n;i++)
    {
        cin >> a[i*2-1].x >> a[i*2-1].y >> a[i*2].x >> a[i*2].y ;
        f[i*2-1][i*2]=0;
        f[i*2][i*2-1]=0;
    }
    n*=2;
    for(i=1;i<=n;i++)for(j=1;j<=n;j++)
    {
        f[i][j]=min(f[i][j],dist(a[i],a[j]));
    }
    for(k=1;k<=n;k++)
    {
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    while(m--)
    {
        node t1,t2 ;
        cin >> t1.x >> t1.y >> t2.x >> t2.y ;
        int ans=dist(t1,t2) ;
        for(i=1;i<=n;i++)
        {
            for(j=1;j<=n;j++)
            {
                ans=min(ans,f[i][j]+dist(t1,a[i])+dist(a[j],t2));
            }
        }
        cout << ans << '\n' ;
    }
}
