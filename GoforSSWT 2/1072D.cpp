#include<bits/stdc++.h>
using namespace std ;
const int N = 2009;
char s[N][N];
int dp[N][N],k;
bool b[N][N];
stack<pair<int,int> > st,st1;
void backtrack(int i,int j)
{
    if(i==1&&j==1)
    {
        printf("a");
        return ;
    }
    if(dp[i-1][j]<=dp[i][j-1])
    {
        backtrack(i-1,j);
    }
    else
    {
        backtrack(i,j-1);
    }
    if(dp[i][j]>k)
    {
        printf("%c",s[i][j]);
    }
    else printf("a");
}
main()
{
    int n,i,j,x,y,max1=0;
    scanf("%d %d",&n,&k);
    for(i=0;i<=n;i++)
    {
        dp[i][0]=1e9;
        dp[0][i]=1e9;
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            scanf(" %c",&s[i][j]);
        }
    }
    dp[0][1]=0;
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            dp[i][j]=min(dp[i-1][j],dp[i][j-1]);
            if(s[i][j]!='a')dp[i][j]++;
            if(dp[i][j]<=k&&max1<i+j-2)
            {
                max1=i+j-2;
                x=i; y=j;
            }
        }
    }
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=n;j++)
        {
            if(dp[i][j]<=k&&i+j-2==max1)
            {
                st.push({i,j});
            }
        }
    }
    if(st.empty())st.push({1,1}),printf("%c",s[1][1]);
    else
    for(i=0;i<=max1;i++)
    {
        printf("a");
    }
    char c;
    while(!st.empty())
    {
        c='z';
        while(!st.empty())
        {
            x=st.top().first; y=st.top().second;
            if(x==n&&y==n)return 0 ;
            st.pop();
            if(y+1<=n&&!b[x][y+1]++)
            c=min(c,s[x][y+1]),st1.push({x,y+1});
            if(x+1<=n&&!b[x+1][y]++)
            c=min(c,s[x+1][y]),st1.push({x+1,y});
        }///
        printf("%c",c);
        while(!st1.empty())
        {
            x=st1.top().first; y=st1.top().second;
            st1.pop();
            if(s[x][y]==c)
            {
                st.push({x,y});
            }
        }
    }
}
