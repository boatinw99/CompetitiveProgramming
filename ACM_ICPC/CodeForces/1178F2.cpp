#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first 
#define se second 
#define mid (l+r>>1)
const int N = 509 , M = 1e6+9 , mod = 998244353 , inf = 1e9+9 ; 
int dp[N][N],col[N],A[M],val[N],sp[M];
pii st[M<<4];
bool imp = 0 ; 
vector<int> V[N];
pii operate(pii lhs,pii rhs)
{
    return {max(lhs.fi,rhs.fi),min(lhs.se,rhs.se)};
}
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]={sp[l],A[l]};
        return ; 
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=operate(st[m<<1],st[m<<1|1]);
}
pii getmax(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return {0,inf} ;
    if(l>=x&&r<=y)return st[m] ;
    return operate(getmax(l,mid,x,y,m<<1),getmax(mid+1,r,x,y,m<<1|1));
}
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
    for(int i=n;i>=1;i--)
    {
        dp[i][i]=val[col[i]];
        for(int j=i+1;j<=n;j++)
        {
            int x = getmin(i,j);
            int R = getr(x,j) , L = getl(i,x) ;
            dp[i][j]=1ll*L*R%mod*val[col[x]]%mod;
        }
    }
    return dp[1][n] ;  
}
int dfs(int l,int r)
{
    if(l>r)return 1 ;
    vector<int> U ; 
    for(int i=l;i<=r;)
    {
        int x = A[i] ;
        val[x]=1;
        for(int j=0;j+1<(int)V[x].size();j++)
        {
            int ret = dfs(V[x][j]+1,V[x][j+1]-1);
            val[x]=1ll*val[x]*ret%mod ;
        }
        U.push_back(A[i]);
        i=V[x].back()+1;
    }
    int n = U.size();
    for(int i=0;i<n;i++)
    {
        col[i+1]=U[i];
    }
    return comp(n) ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ; 
    cin >> n >> m ; 
    for(int i=1;i<=m;i++)
    {
        cin >> A[i] ; 
        V[A[i]].push_back(i);
    }
    for(int i=1;i<=m;i++)
    {
        sp[i]=V[A[i]].back();
    }
    construct(1,m,1);
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j+1<(int)V[i].size();j++)
        {
            pii ret = getmax(1,m,V[i][j]+1,V[i][j+1]-1,1);
            if(ret.fi>V[i][j+1]||ret.se<i)
            {
                imp++;
                break;
            }    
        }
    }
    if(imp)cout << "0" << '\n' ;
    else cout << dfs(1,m) << '\n' ;
    return 0 ;
}