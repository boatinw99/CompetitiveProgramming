#include<bits/stdc++.h>
using namespace std ;
const int N = 1e3+9;
int dp[N][26][26];
char s[N];
main()
{
    int Q,i,j,n,m,x,y,t,r ;
    char c;
    scanf("%d",&Q);
    for(i=0;i<N;i++)
    {
        for(t=0;t<26;t++)
        {
            for(r=0;r<26;r++)
            {
                dp[i][t][r]=1e9;
            }
        }
    }

    while(Q--)
    {
        scanf("%s",&s);
        n=strlen(s);
        dp[0][0][0]=0;
        for(i=0;i<n;)
        {
           x=s[i]-'A';
           i++;
           for(t=0;t<26;t++)
           {
               for(r=0;r<26;r++)
               {
                   dp[i][t][x]=min(dp[i][t][x],dp[i-1][t][r]+
                            min(abs(x-r),26-abs(x-r)));
                   dp[i][x][r]=min(dp[i][x][r],dp[i-1][t][r]+
                            min(abs(t-x),26-abs(t-x)));
                   dp[i-1][t][r]=1e9;
               }
           }
        }
        int ans=INT_MAX;
        for(t=0;t<26;t++)
        {
            for(r=0;r<26;r++)
            {
                ans=min(ans,dp[n][t][r]);
                dp[n][t][r]=1e9;
            }
        }
        printf("%d\n",ans);
    }
}
