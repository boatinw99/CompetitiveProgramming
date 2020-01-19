#include<bits/stdc++.h>
using namespace std ;
const int N = 20;
int b[4][N];
int ans=0,n;
void dfs(int i,int j)
{
    if(i<1||i>3||j<1||j>n+1)
    {
        return ;
    }
    if(j==n+1)
    {
        ans++;
        return ;
    }
    if(b[i][j+1]==0)
    {
        b[i][j+1]++;
        dfs(i,j+1);
        b[i][j+1]=0;
    }
    if(b[i][j-1]==0)
    {
        b[i][j-1]++;
        dfs(i,j-1);
        b[i][j-1]=0;
    }
    if(b[i+1][j+1]==0)
    {
        b[i+1][j+1]++;
        dfs(i+1,j+1);
        b[i+1][j+1]=0;
    }
    if(b[i+1][j-1]==0)
    {
        b[i+1][j-1]++;
        dfs(i+1,j-1);
        b[i+1][j-1]=0;
    }
    if(b[i-1][j+1]==0)
    {
        b[i-1][j+1]++;
        dfs(i-1,j+1);
        b[i-1][j+1]=0;
    }
    if(b[i-1][j-1]==0)
    {
        b[i-1][j-1]++;
        dfs(i-1,j-1);
        b[i-1][j-1]=0;
    }
}
main()
{
    int i;
    scanf("%d",&n);
    for(i=1;i<=3;i++)
    {
        b[1][i]++;
        dfs(1,i);
        b[1][i]=0;
    }
    printf("%d",ans);
}
