#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se escond 
const int N = 1e3+9 , mod = 1e9+7 , K = 53 , inf = 1e9 ; 
int dp[N][K],A[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,X,Y,Z;
    cin >> n ;
    cin >> X >> Y >> Z ;
    for(int i=0;i<N;i++)for(int j=0;j<K;j++)dp[i][j]=inf;
    for(int i=1;i<=n;i++)
    {
        cin >> A[i] ;
    }
    dp[0][0]=0;
    int ans = INT_MAX ; 
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<K;j++)
        {
            for(int a=0;a<=j;a++)
            {
                int gone = j-a;
                for(int b=0;b+a<K;b++)
                {
                    if(a+b>=A[i])
                    dp[i][a+b]=min(dp[i][a+b],dp[i-1][j]+Y*a+gone*Z+b*X+b*Y);
                }
            }
        }
    }
    for(int i=A[n];i<K;i++)
    {
        ans=min(ans,dp[n][i]);
    }
    //printf("check %d \n",dp[1][3]);
    cout << ans << '\n' ;
    return 0 ;
}