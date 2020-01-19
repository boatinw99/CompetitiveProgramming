#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
const int N = 1<<20 , M = 1<<20 , bit = 20 , mod = 1e9+7 ;
int F[M],pw2[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    string s ;
    cin >> n >> m ;
    pw2[0]=1;
    for(int i=1;i<N;i++)
    {
        pw2[i]=pw2[i-1]*2%mod;
    }
    for(int i=0;i<N;i++)pw2[i]=(pw2[i]-1+mod)%mod ;
    for(int i=1;i<=n;i++)
    {
        cin >> s ;
        //reverse(s.begin(),s.end());    
        int mask = 0 ;
        for(int j=0;j<m;j++)
        {
            mask+=(s[j]-'0')*(1<<j);
        }
        F[mask]++;
    }
    int req = 0 ;
    cin >> s ;
    //reverse(s.begin(),s.end());
    for(int i=0;i<m;i++)req+=(s[i]-'0')*(1<<i);
    for(int i=0;i<bit;i++)
    {
        for(int mask=0;mask<M;mask++)
        {
            if(mask&(1<<i))F[mask]+=F[mask^(1<<i)];
        }
    }
    ll ans = 0 ;
    for(int i=0;i<=req;i++)
    {
        if((i|req)==req)
        {
            if(__builtin_popcount(i^req)&1)
            {
                ans=(ans-pw2[F[i]]+mod)%mod;
            }
            else ans=(ans+pw2[F[i]])%mod; 
        }
    }
    while(ans<0||ans>mod);
    cout << ans << '\n' ;
    return 0 ;
}