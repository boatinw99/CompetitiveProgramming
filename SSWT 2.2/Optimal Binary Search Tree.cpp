#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 309 ,inf = 1e9 ;
pii dp[N][N];
int a[N],qs[N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,k,l,r ;
    while(cin >> n)
    {
        for(i=1;i<=n;i++)
        {
            cin >> a[i];
            qs[i]=qs[i-1]+a[i];
        }
        for(k=0;k<=n;k++)
        {
            for(l=1;l+k<=n;l++)
            {
                r=l+k ;
                if(k<1)
                {
                    dp[l][r]={0,l};
                    continue ;
                }
                int ml = dp[l][r-1].se , mr = dp[l+1][r].se ;
                dp[l][r]={inf,0} ;
                for(j=ml;j<=mr;j++)
                {
                    dp[l][r]=min(dp[l][r],{dp[l][j-1].fi+dp[j+1][r].fi+
                                 qs[r]-qs[l-1]-a[j],j});
                }
            }
        }
        cout << dp[1][n].fi << '\n' ;
    }
}
