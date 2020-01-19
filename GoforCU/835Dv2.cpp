#include<bits/stdc++.h>
using namespace std ;
string s="0",d;
const int N = 5009;
int qs[N];
int dp[N][N];
main()
{
    cin >> d;
    s+=d;
    int i,j,n=s.length()-1,x ;
    for(j=1;j<=n;j++)
    {
        dp[j][j]=1;
        ///odd(¤Õè)
        for(x=1;j-x>=1&&j+x<=n;x++)
        {
            if(s[j-x]==s[j+x])
            {
                dp[j-x][j+x]=1+dp[j-x][j-1];
            }
            else break;
        }
        ///even(¤Ùè)
        if(s[j]==s[j+1])
        {
            dp[j][j+1]=2;
            for(x=1;j-x>=1&&j+x+1<=n;x++)
            {
                if(s[j-x]==s[j+x+1])
                {
                    dp[j-x][j+x+1]=1+dp[j-x][j];
                }
                else break;
            }
        }

    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            qs[dp[i][j]]++;
        }
    }
    for(i=n;i>0;i--)qs[i]+=qs[i+1];
    for(i=1;i<=n;i++)printf("%d ",qs[i]);
}
