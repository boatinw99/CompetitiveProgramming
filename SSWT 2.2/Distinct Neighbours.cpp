#include<bits/stdc++.h>
using namespace std ;
const int N = 759, mod = 1e9+7;
vector<int> v ;
int a[N],dp[N][N],comb[N][N];
void pre_process()
{
    comb[0][0]=1;
    for(int i=1;i<N;i++)
    {
        comb[i][0]=1;
        for(int j=1;j<N;j++)
        {
            comb[i][j]=(comb[i-1][j-1]+comb[i-1][j])%mod;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    pre_process();
    int n ;
    cin >> n ;
    for(int i=1,x ;i<=n;i++)
    {
        cin >> x ;
        a[x]++;
    }
    for(int i=1;i<=n;i++)if(a[i])v.push_back(a[i]);
    int m = v.size();
    sort(v.begin(),v.end(),greater<int>());
    dp[0][*v.begin()-1]=1;
    int sz = 0 ;
    for(int i=0;i<m-1;i++)
    {
        sz+=v[i];
        for(int j=0;j<=n/2;j++)
        {
            if(!dp[i][j])continue ;
            for(int k=1;k<=v[i+1];k++)
            {
                for(int l=0;l<=min(k,j);l++)
                {
                    int krmn = sz+1-j ;
                    int numL = comb[j][l];
                    int numK = comb[krmn][k-l];
                    int add = 1ll*numL*numK%mod*comb[v[i+1]-1][k-1]%mod;
                    add=1ll*add*dp[i][j]%mod;
                    dp[i+1][j-l+v[i+1]-k]+=add;
                    dp[i+1][j-l+v[i+1]-k]%=mod ;
                }
            }
        }
    }
    cout << dp[m-1][0] ;
    return 0 ;
}
