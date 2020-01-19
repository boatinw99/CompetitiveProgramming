#include<bits/stdc++.h>
using namespace std ;
const int N = 109,MOD=1e9+7 ;
typedef long long ll ;
int pre[N],posp[N];
int in[N],posi[N];
ll dp[N][N];
void findans(int l1,int r1,int l2,int r2)
{
    int l,r,i,j,k;
    //printf("%d %d | %d %d \n",l1,r1,l2,r2);
    if(l1>=r1)
    {
        dp[l1][r1]=1;
        return ;
    }
    if(pre[l1]==in[l2])///no leftmost
    {
        dp[l1][l1]=1;
        findans(l1+1,r1,l2+1,r2);
        for(j=l1+1;j<=r1;j++)
        {
            dp[l1][j]=(dp[l1][j]+2*dp[l1+1][j])%MOD ;
            //printf("b %d %d -> %d\n",l1,j,dp[l1][j]);
        }
        for(j=l1+1;j<=r1;j++)
        {
            for(k=j+1;k<=r1;k++)
            {
                dp[l1][k]=(dp[l1][k]+dp[l1+1][j]*dp[j+1][k])%MOD;
               // printf("c %d %d %d-> %d\n",l1,j,k,dp[l1][k]);
            }
        }
    }
    else
    {
        l=l1+1; r=posi[pre[l1]];
        if(l1+1==r1)
        {
            dp[l1][r1]=1;
            //printf("jjj %d %d\n",l1,r1);
            return ;
        }
        else
        {
            findans(l1+1,r-l2+l1,l2,r-1);///leftmost
        }
        findans(r-l2+l1+1,r1,r+1,r2);
        dp[l1][r-l2+l1]=dp[l1+1][r-l2+l1];
        for(j=r-l2+l1+1;j<=r1;j++)
        {
            dp[l1][j]=(dp[l1][j]+
                       ((dp[l1][r-l2+l1]*dp[r-l2+l1+1][j])%MOD)*2)
                       %MOD;
        }
        for(j=r-l2+l1+1;j<=r1;j++)
        {
            for(k=j+1;k<=r1;k++)
            {
                dp[l1][k]=(dp[l1][k]+
                    dp[l1][r-l2+l1]*((dp[r-l2+l1+1][j]*dp[j+1][k])%MOD)
                           )%MOD;
            }
        }
    }
}
main()
{
    int n,i,j,x,y,k,x1 ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&pre[i]);
        pre[i]++;
        posp[pre[i]]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&in[i]);
        in[i]++;
        posi[in[i]]=i;
    }
    findans(1,n,1,n);
    printf("%lld",dp[1][n]);
}
