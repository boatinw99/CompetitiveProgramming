#include<stdio.h>
typedef long long ll ;
#define mid (l+r>>1)
const int N = 5009,inf=1e9;
int a[N],dp[N][N];
inline bool cmp(int x1,int x2,int y1,int y2)
{
    if(y1==y2||x1==0)return 0 ;
    if(x1==x2||y1==0)return 1 ;
    ll mx = 1ll*(a[x2]-a[x1])*(y2-y1);
    ll my = 1ll*(a[y2]-a[y1])*(x2-x1);
    return mx>=my;
}
int main()
{
    int n,i,j,x,y,ans=0 ;
    scanf("%d",&n);
    a[0]=inf ;
    for(i=1;i<=n;i++)scanf("%d",&a[i]) ;
    for(i=1;i<=n;i++)
    {
        dp[i][1]=i ;
        for(j=i-1;j>=1;j--)
        {
            x=j,y=i ;
            int l=1,r=y ;
            while(l+1<r)
            {
                if(cmp(dp[x][mid],x,x,y))l=mid ;
                else r=mid ;
            }
            if(cmp(x,y,dp[y][l+1],y))dp[y][l+1]=x;
        }
        for(j=i;j>=1;j--)if(cmp(dp[i][j+1],i,dp[i][j],i))dp[i][j]=dp[i][j+1];
    }
    for(i=n;i>=ans;i--)
    {
        for(j=i;j>=ans;j--)if(dp[i][j])
        {
            ans=j ;
            break;
        }
    }
    printf("%d",ans);
}
