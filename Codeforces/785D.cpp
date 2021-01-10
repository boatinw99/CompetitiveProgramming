#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
const int N = 2e5+9 , mod = 1e9+7 ; 
ll fact[N],inv[N];
int suf[N];
ll powap(ll a,ll p)
{
    if(p==0)return 1 ;
    ll ret = powap(a,p>>1);
    ret=ret*ret%mod;
    if(p&1)ret=ret*a%mod;
    return ret ; 
}
void pre_process()
{
    fact[0]=1;
    for(int i=1;i<N;i++)fact[i]=fact[i-1]*i%mod;
    inv[0]=1;
    for(int i=1;i<N;i++)inv[i]=powap(fact[i],mod-2);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    string s; 
    cin >> s ;
    for(int i=s.size()-1;i>=0;i--)
    {
        suf[i]=suf[i+1]+(s[i]==')');
    }
    pre_process();
    ll ans = 0 ;
    int x = 0 ;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
            x++;
            int y = suf[i+1];
            /// xxxx yyy -> (x+y-1 x) -> number of ways to push 1 in x positions
            // if y-pos have z || x-pos have x-z -> 0->z     
            //printf("pls %d %d \n",x,y);
            if(y>0)
            {
                ans+=fact[x+y-1]*inv[y-1]%mod*inv[x]%mod;
                ans%=mod;
            }
        }
    }
    cout << ans << '\n' ;
    return 0 ;
}