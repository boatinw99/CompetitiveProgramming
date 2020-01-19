#include<bits/stdc++.h>
using namespace std ;
const int N = 18 ,MAX = 1e9+7 ;
int n,k ;
int a[N][N],cst[N][N],dp[N][N],f[N];
void preprocess(int mask)
{
    int i,j,i1 ;
    memset(cst,0,sizeof cst);
    for(i=1;i<=n;i++)
    {
        memset(f,0,sizeof f);
        for(i1=i;i1<=n;i1++)
        {
            int sum=0;
            for(j=1;j<=n;j++)
            {
                f[j]+=a[i1][j];
                sum+=f[j];
                cst[i][i1]=max(cst[i][i1],sum);
                if((mask>>(n-j))&1)sum=0;
            }
        }
    }
}
int process(int mask)
{
    int i,j,cnt=-1 ;
    for(i=0;i<N;i++)for(j=0;j<N;j++)dp[i][j]=MAX ;
    for(i=0;i<N;i++)if((1<<i)&mask)cnt++;
    if(k-cnt<0)return MAX ;
    k++;
    dp[0][0]=0;
    for(i=1;i<=n;i++)
    {
        for(int i1=0;i1<i;i1++)
        {
            for(j=1;j<=k&&j<=n;j++)
            {
                dp[i][j]=min(dp[i][j],max(dp[i1][j-1],cst[i1+1][i]));
            }
        }
    }
    k--;
    return dp[n][k-cnt+1];
}
main()
{
    int i,j,ans=MAX ;
    cin >> n >> k ;
    int bits = 1<<(n-1);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)cin >> a[i][j] ;
    }
    for(i=0;i<bits;i++)
    {
        preprocess(i<<1|1);
        ans=min(ans,process(i<<1|1));
    }
    cout << ans ;
}
