#include<bits/stdc++.h>
using namespace std ;
const int q = 5 ;
const int N = 1e5+9 ;
const int MOD = 1e6+3;
int a[q]={1,5,10,25,50};
int dp[N];
main()
{
    int m,x,i,j ;
    scanf("%d",&m);
    dp[0]=1;
    for(i=0;i<q;i++)
    {
        for(j=a[i];j<N;j++)
        {
            dp[j]+=dp[j-a[i]];
            dp[j]%=MOD;
        }
    }
    while(m--)
    {
        scanf("%d",&x);
        printf("%d\n",dp[x]);
    }
}
