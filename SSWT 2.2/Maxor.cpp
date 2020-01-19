#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 , bit = 17 , M = 1<<bit ;
int a[N],mx[M],dp[M][bit+1],n;
bool submask[M];
bool chk(int i,int j)
{
    return (1<<j)&i ;
}
int neg(int x)
{
    return (M-1)^x ;
}
int maxor()
{
    for(int i=1;i<=n;i++)submask[a[i]]++;
    for(int i=M-1;i>=0;i--)for(int j=0;j<bit;j++)
        if(chk(i,j)&&submask[i])submask[i-(1<<j)]++;
    for(int i=0;i<M;i++)
    {
        if(submask[i])mx[i]=i;
        for(int j=0;j<bit;j++)
        {
            if(chk(i,j))mx[i]=max(mx[i],mx[i-(1<<j)]);
        }
    }
    int ret = 0 ;
    for(int i=1;i<=n;i++)ret = max(ret,a[i]|mx[neg(a[i])]);
    return ret ;
}
ll getans(int best)
{
    for(int i=1;i<=n;i++)dp[a[i]][bit-1]++;
    for(int i=M-1;i>=0;i--)
    {
        for(int j=bit-1;j>=0;j--)
        {
            dp[i][j]+=dp[i][j+1];
            if(!chk(i,j))
            {
                dp[i][j]+=dp[i+(1<<j)][j];
            }
        }
    }
    ll ans = 0 ;
    for(int i=1;i<=n;i++)
    {
        ans+=dp[best-a[i]][0];
        ans-=(a[i]==best);
    }
    return ans/2 ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++) cin >> a[i] ;
    int best = maxor();
    cout << best << " " << getans(best) ;
}
