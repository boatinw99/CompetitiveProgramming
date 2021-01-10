#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
const int N = 1e6+9 , mod = 1e9+7 ;
string s ; 
int n ; 
ll dp[N][4][4];
int check(int l,int m,int r)
{
    if(m==3)return 1 ;
    int cnt = 0 ;
    if(l==3)cnt++;
    if(r==3)cnt++;
    return m==cnt ; 
}
void recur(int idx,int x)
{
    ///idx -> i , state -> x 
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            dp[idx][x][j]+=dp[idx-1][i][x]*check(i,x,j);
            //if(check(i,x,j))printf("pass the check idx=%d -> %d %d %d \n",idx,i,x,j);
            dp[idx][x][j]%=mod ; 
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> s ;
    n = s.size() ;
    dp[0][0][0]=dp[0][0][1]=dp[0][1][3]=1;
    ///0,1,2 -> the amount of bomb , 3 is bomb
    for(int i=1;i<=n;i++)
    {
        char c = s[i-1];
        if(c=='?')
        {
            for(int j=0;j<4;j++)recur(i,j);
        }
        else if(c=='*')recur(i,3);
        else recur(i,c-'0');
    }
    cout << (dp[n][0][0]+dp[n][1][0]+dp[n][3][1])%mod ;
    return 0 ;
}