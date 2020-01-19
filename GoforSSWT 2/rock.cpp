#include<bits/stdc++.h>
using namespace std ;
const int N = 109;
int a[N],dp[N][N];
void rock(int i,int j)
{
    if(i+1==j)
    {
        dp[i][j]=max(a[i],a[j]);
        return ;
    }
    if(dp[i][j]>0)return ;
    rock(i+1,j-1);
    dp[i][j]=max(a[i],a[j])+dp[i+1][j-1];
    rock(i+2,j);
    dp[i][j]=max(dp[i][j],dp[i+2][j]+a[i]);
    rock(i,j-2);
    dp[i][j]=max(dp[i][j],dp[i][j-2]+a[j]);
}
main()
{
    int n,i,j;
    scanf("%d",&n);
    for(i=1;i<=2*n;i++)
    {
        scanf("%d",&a[i]);
    }
    rock(1,2*n);
    printf("%d",dp[1][2*n]);
}
