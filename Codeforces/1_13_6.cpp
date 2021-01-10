#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int qs[N] ;
int dp[N];
main()
{
    int n,m,i,j,min1=1e9+5,max1=0,l,r,x  ;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d %d",&l,&r,&x);
        min1=min(min1,x);
        qs[l]+=x;
        qs[r+1]-=x;
        dp[1]=max(dp[1],l-1);
        dp[r+1]=n;
    }
    for(i=1;i<=n;i++)qs[i]+=qs[i-1];
    int q=0;
    for(i=1;i<=n;i++)
    {
        q=max(q,dp[i]);
        printf("%d ",dp[i]);
        if(i<=q)
        {
            //printf("%d ",qs[i]);
            max1=max(qs[i],max1);
        }
        else
        {
            //printf("%d ",qs[i]-min1);
            max1=max(max1,qs[i]-min1);
        }
    }
    printf("\n%d",max1);
}

