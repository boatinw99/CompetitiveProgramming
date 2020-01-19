#include<bits/stdc++.h>
using namespace std ;
const int N = 2009;
typedef long long ll ;
ll a[N];
ll dp[N];
main()
{
    int n,k,i,j ;
    scanf("%d %d",&n,&k);
    ll bit,mask,x,sum ;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    for(bit=1;bit<2000*1e9;bit<<=1);
    mask=bit/2;
    bit--;
    for(mask;mask;mask>>=1)
    {
        x=bit-mask;
        for(i=1;i<=n;i++)
        {
            sum=a[i];
            dp[i]=INT_MAX;
            for(j=i;j>0&&sum<=x;j--,sum+=a[j])
            {
                if((sum|x)==x)
                {
                    dp[i]=min(dp[i],dp[j-1]+1);
                }
            }
        }
        if(dp[n]<=k)bit-=mask;
    }
    printf("%lld",bit);

}
