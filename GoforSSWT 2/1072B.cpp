#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
int OR[N];
int AND[N];
int dp[N][4][4];
void pr(int n,int i,int j)
{
    int d;
    if(n==0)return ;
    for(d=0;d<4;d++)
    {
        if(dp[n-1][d][i]==1)
        {
            pr(n-1,d,i);
            break;
        }
    }
    printf("%d ",i);
}
main()
{
    int n,i,j,d,q;
    scanf("%d",&n);
    for(i=1;i<n;i++)scanf("%d",&OR[i]);
    for(i=1;i<n;i++)scanf("%d",&AND[i]);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            dp[0][i][j]=1;
        }
    }
    for(d=1;d<n;d++)
    {
        for(i=0;i<4;i++)
        {
            for(j=0;j<4;j++)///dp[q][i] -> dp[i][j];
            {
                for(q=0;q<4;q++)
                {
                    if((i|j)==OR[d]&&(i&j)==AND[d]&&dp[d-1][q][i]==1)
                    {
                        dp[d][i][j]=1;
                        break;
                    }
                }
            }
        }
    }
    for(i=0;i<4;i++)
    {
        for(j=0;j<4;j++)
        {
            if(dp[n-1][i][j]==1)
            {
                printf("YES\n");
                pr(n-1,i,j);
                printf("%d",j);
                return 0 ;
            }
        }
    }
    printf("NO");

}
