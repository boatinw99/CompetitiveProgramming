#include<bits/stdc++.h>
using namespace std ; 
const int N = 1e3+9 , mod = 998244353 , inf = 1e9 ;
int n,k,A[N];
int dp[N][N],pref[N];
void add(int &a,int b)
{
    a+=b;
    a%=mod;
}
int comp(int x)
{
    int l=1,ret=0;
    memset(pref,0,sizeof pref);
    pref[0]=1;
    for(int r=1;r<=n+1;r++)
    {
        while(A[r]-A[l]>=x)
        {
            for(int i=1;i<=k;i++)
            {
                add(pref[i],dp[i][l]);
            }
            l++;
        }
        for(int i=1;i<=k;i++)
        {
            dp[i][r]=pref[i-1];
        }
    }
    return pref[k] ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> k ;
    for(int i=1;i<=n;i++)
    {
        cin >> A[i] ;
    }
    A[n+1]=inf ;
    sort(A+1,A+1+n);
    int ans = 0 ;
    for(int x=1;x<=A[n];x++)
    {
        int ret = comp(x);
        if(!ret)break;
        //printf("%d \n",ret);
        add(ans,ret) ; 
    }
    cout << ans ; 
    return 0 ;
}