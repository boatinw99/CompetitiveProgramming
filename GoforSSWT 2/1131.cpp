#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+9,MOD=2553 ;
char s[N];
int dp1[N],dp2[N];///same , not-same
main()
{
    int i,n,j,ans=0,pr ;
    ///Pre-process
    dp1[1]=1; dp1[2]=2; dp2[2]=1;
    for(i=3;i<N;i++)
    {
        dp1[i]=(2*dp1[i-1]+2*dp2[i-1])%MOD;
        dp2[i]=dp1[i-1];
    }
    scanf("%d",&n);
    for(i=2;i<n+2;i++)
    {
        scanf(" %c",&s[i]);
    }
    for(i=2;i<n+2;i++)
    {
        if(s[i]=='R')
        {
            if(s[i-1]=='P'&&s[i-2]=='P');
            else if(s[i-1]=='P'&&s[i-2]!='P')ans+=dp1[n-i+2];
            else ans+=dp1[n-i+2]+dp2[n-i+2];
        }
        else if(s[i]=='S')
        {
            if(s[i-1]=='P'&&s[i-2]=='P');
            else if(s[i-1]=='P'&&s[i-2]!='P')ans+=dp1[n-i+2];
            else ans+=dp1[n-i+2]+dp2[n-i+2];
            if(s[i-1]=='R'&&s[i-2]=='R');
            else if(s[i-1]=='R'&&s[i-2]!='R')ans+=dp1[n-i+2];
            else ans+=dp1[n-i+2]+dp2[n-i+2];
        }
        ans%=MOD;
    }
    printf("%d",ans+1);
}
