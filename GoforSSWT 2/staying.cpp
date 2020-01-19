#include<bits/stdc++.h>
using namespace std;
const int N = 1009,MOD=1e9+7;
vector<int> path[5];
vector<int>::iterator it ;
int dp[N][5][8]; /// day town bits
int k[5];
main()
{
    int n,ka,kb,kc,i,j,d,x,y,rest ;
    scanf("%d %d %d %d",&n,&k[1],&k[2],&k[4]);
    path[1].push_back(2); path[1].push_back(4);
    path[2].push_back(4); path[4].push_back(1);
    for(i=1;i<=k[1];i++)dp[i][1][1]=1;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=4;j*=2)
        {
            for(d=1;d<=7;d++)
            {
                if(dp[i][j][d]>0)
                {
                    for(it=path[j].begin();it!=path[j].end();it++)
                    {
                        for(rest=1;rest<=k[*it]&&i+rest<=n;rest++)
                        {
                            dp[i+rest][*it][d|*it]+=dp[i][j][d];
                            dp[i+rest][*it][d|*it]%=MOD;
                        }
                    }
                }
            }
        }
    }
    int ans=0;
    for(i=1;i<=4;i++)
    {
        ans+=dp[n][i][7];
        ans%=MOD;
    }
    printf("%d",ans);
}
