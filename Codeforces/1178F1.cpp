#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first 
#define se second 
const int N = 509 , M = 1e6+9 , mod = 998244353 , inf = 1e9+9 ; 
int dp[N][N],col[N],A[M];
void add(int &a,int b)
{
    a=(a+b)%mod ; 
}
int getmin(int l,int r)
{
    pii mn = {inf,0};   
    for(int i=l;i<=r;i++)
    {
        mn=min(mn,{col[i],i});
    }
    return mn.se ; 
}
int get(int l,int r)
{
    if(l>r)return 1 ;
    return dp[l][r] ;
}
int getl(int l,int r)
{
    int ret = 0 ;
    for(int i=r;i>=l;i--)
    {
        add(ret,1ll*get(i,r-1)*get(l,i-1)%mod);
    }
    return ret ; 
}
int getr(int l,int r)
{
    int ret = 0 ;
    for(int i=l;i<=r;i++)
    {
        add(ret,1ll*get(l+1,i)*get(i+1,r)%mod);
    }
    return ret ; 
}
int comp(int n)
{
    int ans = 0 ;
    for(int i=n;i>=1;i--)
    {
        dp[i][i] = 1 ;
        for(int j=i+1;j<=n;j++)
        {
            int x = getmin(i,j);
            int R = getr(x,j) , L = getl(i,x) ;
            dp[i][j]=1ll*L*R%mod;
            ///printf("aaa %d %d | %d %d %d\n",i,j,L,R,x);
        }
    }
    return dp[1][n] ;  
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ; 
    cin >> n >> m ; 
    for(int i=1;i<=m;i++)
    {
        cin >> A[i] ; 
    }
    for(int i=1;i<=n;i++)col[i]=A[i];
    cout << comp(n) << '\n' ; 
    return 0 ;
}