#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int dp[N],ans[N],par[N];
main()
{
    int n,k,i,j,x,y,l ;
    scanf("%d %d",&n,&l);
    for(i=0;i<=l;i++)dp[i]=INT_MAX;
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        for(j=0;j<=l;j++)
        {
            if(abs(x-j)+y+i<dp[j])
            {
                dp[j]=abs(x-j)+y+i;
                par[j]=i;
            }
        }
    }
    for(i=0;i<=l;i++)
    {
        ans[par[i]]++;
    }
    for(i=1;i<=n;i++)
    {
        printf("%d\n",ans[i]);
    }
}
