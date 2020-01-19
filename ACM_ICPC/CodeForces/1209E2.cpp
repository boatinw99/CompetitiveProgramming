#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 13 , M = 2009 ; 
vector<pii> V ; 
int A[N][M],n,m ;
int dp[1<<N][N],pref[1<<N][M];
void re()
{
    V.clear();
    for(int i=1;i<=n;i++)
    {
        for(int mask=0;mask<(1<<n);mask++)
        {
            pref[mask][i]=dp[mask][i]=0;
        }
    }
}
int getmax(int x,int mask)
{
    int ret = 0 ;
    for(int shift=0;shift<n;shift++)
    {
        int sum = 0 ;
        for(int i=0;i<n;i++)
        {
            int idx = (i+shift)%n ; 
            if((1<<idx)&mask)
            {
                sum+=A[i][x];
            }
        }
        ret = max(ret,sum) ;        
    }
    return ret ; 
}
void precomp(int x,int col)
{
    for(int i=0;i<(1<<n);i++)
    {
        pref[i][col] = getmax(x,i);
    }
}
void comp(int x,int col)
{
    /// col x 
    for(int mask=0;mask<(1<<n);mask++)
    {
        for(int submask=mask;;submask=(submask-1)&mask)
        {
            dp[mask][col]=max(dp[mask][col],dp[submask][col-1]+pref[mask^submask][col]);
            if(!submask)break;
        }
    }

}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ;
    while(T--)
    {
        re();
        cin >> n >> m ; 
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin >> A[i][j] ;
            }
        }
        for(int j=0;j<m;j++)
        {
            int mx = 0 ;
            for(int i=0;i<n;i++)
            {
                mx = max(mx,A[i][j]);
            }
            V.emplace_back(mx,j);
        }
        sort(V.begin(),V.end(),greater<pii>());
        for(int i=0;i<min(n,int(V.size()));i++)
        {
            precomp(V[i].se,i+1);
            comp(V[i].se,i+1);
        }
        int ans = 0 ;
        for(int i=0;i<(1<<n);i++)
        {
            ans = max(ans,dp[i][min(n,int(V.size()))]);
        }
        cout << ans << '\n' ; 
    }
    return 0 ;
}