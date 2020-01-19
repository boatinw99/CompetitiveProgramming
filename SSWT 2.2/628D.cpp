#include<bits/stdc++.h>
using namespace std ;
const int N = 2009 , mod = 1e9+7 ;
int pows[N],dp[N][9][N],tmp[N];///len | first digit | mod
int m,d,n;
void add(int &a,int b)
{
    a+=b;
    a%=mod;
}
bool Iscount(string s)
{
    for(int i=0;i<n;i+=2)
    {
        if(s[i]-'0'==d)return 0 ;
    }
    for(int i=1;i<n;i+=2)
    {
        if(s[i]-'0'!=d)return 0;
    }
    return 1 ;
}
void pre_process()
{
    pows[0]=1;
    for(int i=1;i<N;i++)pows[i]=10ll*pows[i-1]%mod;
    dp[0][0][0]=1;
    for(int i=1;i<N;i++)
    {
        memset(tmp,0,sizeof tmp);
        for(int k=0;k<m;k++)for(int j=0;j<10;j++)add(tmp[k],dp[i-1][j][k]);
        if((n&1)==(i&1))
        {
            for(int j=0;j<10;j++)for(int k=0;k<m;k++)
            add(dp[i][j][(1ll*j*pows[i-1]+k)%m],tmp[k]);
        }
        else for(int k=0;k<m;k++)add(dp[i][d][(1ll*d*pows[i-1]+k)%m],tmp[k]);
    }
}
int solve(string s)
{
    int rmn = 0 ;
    int ans = 1 ;
    for(int ii=0;ii<n;ii++)
    {
        int i = n-ii;
        int use = s[ii] ;
        if(ii&1)
        {
            if(s[ii]-'0'<d)break;
            use = d ;
        }
        else
        {

        }
        rmn = (rmn+1ll*use*pows[i-1])%mod;
    }
    return ans ;
}
int main()
{
    string s,t ;
    cin >> m >> d ;
    cin >> s >> t ;
    n=s.size();
    pre_process();
    cout << (solve(t)-solve(s)+Iscount(s)+mod)%mod << '\n' ;
    return 0 ;
}
