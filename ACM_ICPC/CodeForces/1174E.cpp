#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+9 , mod = 1e9+7 , LOG = log2(N)+1 ; 
int dp[N][LOG][2],n ; 
int pows(int a,int p)
{
    if(p==1)return a;
    return 1 ;
}
int f(int x,int y)
{
    return n/(1<<x)/pows(3,y);
}
void add(int &a,int b)
{
    a=(a+b)%mod ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    int M=log2(n); 
    dp[1][M][0]=1;
    if((1<<M)/2*3<=n)dp[1][M-1][1]=1;
    for(int i=1;i<n;i++)
    {
        for(int x=0;x<=M;x++)
        {
            for(int y=0;y<=1;y++)
            {
                if(f(x,y)-i>=1)add(dp[i+1][x][y],1ll*dp[i][x][y]*(f(x,y)-i)%mod);
                if(x>=1)add(dp[i+1][x-1][y],1ll*dp[i][x][y]*(f(x-1,y)-f(x,y))%mod);
                if(y==1)add(dp[i+1][x][y-1],1ll*dp[i][x][y]*(f(x,y-1)-f(x,y))%mod);
            }
        }
    }
    cout << dp[n][0][0] << '\n' ; 
    return 0 ;
}