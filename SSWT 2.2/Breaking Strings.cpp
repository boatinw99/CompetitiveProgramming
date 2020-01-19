#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,int> pli ;
#define fi first
#define se second
const ll inf = 1e18 ;
const int N = 1009 ;
pli dp[N][N];
int a[N] ;
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,i,j,k,s,l,r ;
    while(cin >> k >> n)
    {
        for(i=1;i<=n;i++)cin >> a[i];
        n++;
        a[n]=k ;
        for(s=0;s<=n;s++)
        {
            for(l=0;l+s<=n;l++)
            {
                r=l+s ;
                if(s<2)
                {
                    dp[l][r]={0,l} ;
                    continue ;
                }
                int ml = dp[l][r-1].se , mr = dp[l+1][r].se ;
                dp[l][r]={inf,0} ;
                for(j=ml;j<=mr;j++)
                {
                    dp[l][r]=min(dp[l][r],{dp[l][j].fi+dp[j][r].fi+a[r]-a[l],j});
                }
            }
        }
        cout << dp[0][n].fi << '\n' ;
    }
}
