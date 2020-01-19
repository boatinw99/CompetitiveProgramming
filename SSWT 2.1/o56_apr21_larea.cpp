#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 309 ;
ll a[N][N];
ll qs[N][N];///up down
ll dp1[N][N];///left down
ll dp2[N][N];///left up
ll dp3[N][N];///right down
ll dp4[N][N];///right up
int n,m ;
void compute(int up,int down)
{
    ll sum = 0 ;
    for(int j=1,l=1;j<=m;j++)
    {
        sum+=qs[down][j]-qs[up-1][j];
        while(sum<0&&l<=j)
        {
            sum-=qs[down][l]-qs[up-1][l];
            l++;
        }
        dp1[up][j]=max(dp1[up][j],sum);
        dp2[down][j]=max(dp2[down][j],sum);
    }
    sum = 0 ;
    for(int j=m,r=m;j>=1;j--)
    {
        sum+=qs[down][j]-qs[up-1][j];
        while(sum<0&&r>=j)
        {
            sum-=qs[down][r]-qs[up-1][r];
            r--;
        }
        dp3[up][j]=max(dp3[up][j],sum);
        dp4[down][j]=max(dp4[down][j],sum);
    }

}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j ;
    cin >> n >> m ;
    for(j=0;j<=m;j++)qs[0][j]=0 ;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=m;j++)
        {
            cin >> a[i][j];
            qs[i][j]=(qs[i-1][j]+a[i][j]);
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=i;j<=n;j++)
        {
            compute(i,j);
        }
    }
    ll ans = 0 ;
    for(i=0;i<=n;i++)
    {
        for(j=0;j<=m;j++)
        {
            ans=max(ans,dp1[i][j]+dp3[i][j+1]);
            ans=max(ans,dp2[i][j]+dp4[i][j+1]);
        }
    }
    cout << ans ;

}
