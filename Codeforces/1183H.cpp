#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll INF = 1e13 ;  
const int N = 109 , ALP = 27; 
int n ; 
bool mark[ALP];
ll dp[N][N];
char C[N];
void add(ll &a,ll b)
{
    a+=b;
    a=min(a,INF);
}
void solve(int idx)
{
    vector<int> V ;
    memset(mark,0,sizeof mark);
    for(int i=idx+1;i<=n;i++)
    {
        if(!mark[C[i]-'a']++)
        {
            V.push_back(i);
        }
    }
    dp[idx][1] = 1 ;
    while(!V.empty())   
    {
        int u = V.back();
        V.pop_back();
        if(!dp[u][1])
        {
            solve(u);
        }
        for(int i=1;i<=n+1;i++)
        {
            add(dp[idx][i],dp[u][i-1]);
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll k ; 
    cin >> n >> k ;
    for(int i=1;i<=n;i++)
    {
        cin >> C[i]; 
    }
    solve(0);
    ll ans = 0 ;
    for(int i=n+1;i>=1&&k;i--)
    {
        ll tmp = min(dp[0][i],k);
        k-=tmp;
        ans+=tmp*(n-i+1);
    }
    cout << (k?-1:ans) << '\n' ;
}