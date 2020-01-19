#include<bits/stdc++.h>
using namespace std ;
const int N = 509 ;
int a[N][N],b[N][N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,i,j;
    cin >> n >> m ;
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin >> a[i][j];
    for(i=1;i<=n;i++)for(j=1;j<=m;j++)cin >> b[i][j];
    for(i=1;i<n;i++)
    {
        for(j=1;j<m;j++)
        {
            if(a[i][j]!=b[i][j])
            {
                a[i][j]^=1;
                a[i][j+1]^=1;
                a[i+1][j]^=1;
                a[i+1][j+1]^=1;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            if(a[i][j]!=b[i][j])
            {
                cout << "No" ;
                return 0 ;
            }
        }
    }
    cout << "Yes" ;
}
