#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9;
char s[N];
ll dp[N][1<<4];
char key[256];
main()
{
    int n,Q,l,r,i,j,k,mask,p ;
    scanf("%d %s %d",&n,&s,&Q);
    ///Pre-process
    key['E']=0; key['V']=1; key['O']=2; key['L']=3;
    for(i=0;i<n;i++)
    {
       k=key[s[i]];
       for(j=0;j<1<<4;j++)
       {
           dp[i+1][j]=dp[i][j];
       }
       dp[i+1][1<<k]++;
       mask=0;
       for(p=k+1;p<=3;p++)
       {
           mask+=1<<p;
           dp[i+1][mask|(1<<k)]+=dp[i][mask];
       }
    }
    ll a[1<<4];
    while(Q--)
    {
        scanf("%d %d",&l,&r);
        for(k=1;k<=8;k*=2)
        {
            a[k]=dp[r][k]-dp[l-1][k];
        }
        mask=1;
        a[3]=dp[r][3]-dp[l-1][3]-(dp[l-1][2]*a[1]);
        a[7]=dp[r][7]-dp[l-1][7]-(dp[l-1][4]*a[3])-(dp[l-1][6]*a[1]);
        a[15]=dp[r][15]-dp[l-1][15]-(dp[l-1][8]*a[7])-
        (dp[l-1][12]*a[3])-(dp[l-1][14]*a[1]);
        printf("%lld\n",a[15]);
    }
}
