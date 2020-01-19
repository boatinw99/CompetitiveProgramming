#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e3+9 , mod = 1e9+7 ; 
int a[N],b[N],n,d,m,compul; /// bit compulsory 
ll dp[N][N],pw10[N];
bool bad(int i,int val)
{
    if(i==n&&d==0)return 0 ;
    if((i%2==compul)&&val!=d)return 1 ;
    if((i%2!=compul)&&val==d)return 1 ;
    return 0 ;
}
int check(int a[])
{
    int remainder = 0 ;
    for(int i=n;i>=1;i--)
    {
        if(bad(i,a[i]))return 0 ;
        remainder=((remainder*10)+a[i])%m;
    }
    return remainder==0 ; 
}
void add(int i,int dig)
{
    ll val = dig*pw10[i-1]%m;
    for(int j=0;j<m;j++)
    {
        dp[i][(val+j)%m]+=dp[i-1][j];
        dp[i][(val+j)%m]%=mod ;
    }
}
void pre_process()
{
    pw10[0]=1;
    for(int i=1;i<N;i++)pw10[i]=pw10[i-1]*10%m;
    dp[0][0] = 1 ;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<=9;j++)
        {
            if(!bad(i,j))add(i,j);
        }
        /*
        if(i%2==compul)
        {
            add(i,d);///dp[i][] <- add with d 
        }
        else 
        {
            for(int j=0;j<d;j++)add(i,j);
            for(int j=d+1;j<=9;j++)add(i,j);
        }*/
    }
}
ll comp(int a[])
{
    ll ans = check(a);
    ll val = 0 ;
    for(int i=n;i>=1;i--)
    {
        for(int j=0;j<a[i];j++)
        {
            if(!bad(i,j))
            {
                ll tmp = (val+j*pw10[i-1])%m;
                ans+=dp[i-1][(m-tmp)%m];
                ans%=mod;
            }
        }
        val+=a[i]*pw10[i-1];
        val%=m;
        if(bad(i,a[i])) 
        {
            //printf("ret = %lld\n",ans);
            return ans ; 
        }
    }
    return ans ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    string s,t ;
    cin >> m >> d >> s >> t ;
    reverse(s.begin(),s.end());
    reverse(t.begin(),t.end());
    n = s.size();
    if(n&1)compul = 0 ;
    else compul = 1 ;
    pre_process();
    for(int i=0;i<n;i++)a[i+1]=s[i]-'0',b[i+1]=t[i]-'0';
    //comp(b);
    cout << (comp(b)-comp(a)+check(a)+mod)%mod << '\n' ;
    return 0;
}