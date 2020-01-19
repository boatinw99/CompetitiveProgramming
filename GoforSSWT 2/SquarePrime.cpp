#include<bits/stdc++.h>
using namespace std ;
const int N = 1e3 ;
int prime[N];
int dp[N],p=0,*range;
main()
{
    int i,j ;
    bool b=0 ;
    for(i=2;i<N;i++)
    {
        b=0 ;
        for(j=0;j<p&&prime[j]*prime[j]<=i;j++)
        {
            if(i%prime[j]==0)
            {
                b++;
                break;
            }
        }
        if(b==0)
        {
            dp[p]=i*i;
            prime[p++]=i;
        }
    }
    int l,r ;
    scanf("%d %d",&l,&r);
    b=0;
    for(i=0;i<p;i++)
    {
        if(dp[i]>=l&&dp[i]<=r)
        {
            b++;
            printf("%d ",dp[i]);
        }
    }
    if(b==0)printf("-1");
}
