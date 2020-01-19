#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 , base = 8 , M = 1<<8 ;
int dp[1<<8][1<<8][10],ans[17],dist[M];
int getdist(int x)
{
    int cnt = 0 ;
    for(int i=base-1;i>=0;i--)if((1<<i)&x)cnt++;
    return cnt ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,x ;
    cin >> n >> m ;
    for(int i=0;i<M;i++)dist[i]=getdist(i);
    while(n--)
    {
        cin >> x ;
        memset(ans,0,sizeof ans);
        int l = x/M , r = x&255 ;
        for(int i=0;i<M;i++)
        {
            for(int j=0;j<=base;j++)ans[j+dist[r^i]]+=dp[l][i][j];
        }
        for(int i=0;i<M;i++)dp[i][r][dist[i^l]]++;
        for(int j=0;j<=m;j++)cout << ans[j] << " " ;
        cout << '\n' ;
    }
    return 0 ;
}
