#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 2e3+9 ,inf = 1e9;
int n,m,A[N][N],qs[N][N];
ll nm ;
int getsum(int x,int y,int mul)
{
    x=(x-1)%(n<<1)+1;
    y=(y-1)%(m<<1)+1;
    if(mul==1)return qs[x][y];
    else return (x*y)-qs[x][y];
}
ll dfs(int x1,int y1,int sz,int x,int y,int mul)
{
    if(sz==2)
    {
        return getsum(x,y,mul);
    }
    ll r = 1ll*n*(x1+sz/2-1) , c = 1ll*m*(y1+sz/2-1) ;
    int typ = 0 ;
    if(c<y)typ++,mul*=-1;
    if(r<x)typ+=2,mul*=-1;
    ll ret = 0 ;
    if(typ==0);
    else
    {
        int tmp = sz/4 ;
        ll rr = 1ll*n*(x1-1)+1 , cc = 1ll*m*(y1-1)+1 ;
        if(typ==1)
        {
            ret+=1ll*(x-rr+1)*tmp*m;
        }
        else if(typ==2)
        {
            ret+=1ll*(y-cc+1)*tmp*n;
        }
        else
        {
            ret+=1ll*(x-rr+1)*tmp*m+1ll*(y-c)*tmp*n;
        }
    }
    if(typ&1)y1+=sz/2;
    if(typ>=2)x1+=sz/2;
    ll ans = ret+dfs(x1,y1,sz>>1,x,y,mul);
    return ans ; 
}
ll solve(int x,int y)
{
    if(x<=0||y<=0)return 0 ;
    ll ans = dfs(1,1,1<<30,x,y,1);
    return ans ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int q ;
    cin >> n >> m >> q ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c ;
            cin >> c ;
            A[i][j]=A[i+n][j+m]=c-'0';
            A[i][j+m]=A[i+n][j]=A[i][j]^1;
        }
    }
    nm=n*m;
    for(int i=1;i<=n*2;i++)
    {
        for(int j=1;j<=m*2;j++)
        {
            qs[i][j]=qs[i-1][j]+qs[i][j-1]-qs[i-1][j-1]+A[i][j];
        }
    }
    while(q--)
    {
        int x1,y1,x2,y2 ;
        cin >> x1 >> y1 >> x2 >> y2 ;
        cout << solve(x2,y2)-solve(x2,y1-1)-solve(x1-1,y2)+solve(x1-1,y1-1) << '\n' ;
    }
    return 0 ;
}