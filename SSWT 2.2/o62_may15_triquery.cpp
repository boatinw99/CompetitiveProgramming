#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2009 ;
int n,m ;
int a[N][N];
pii bd[N][N];
ll f[N][N],f1[N][N<<1];
void update(int x,int y,int cst)
{
    for(int i=x;i>0;i-=i&-i)
    {
        for(int j=y;j>0;j-=j&-j)
        {
            f[i][j]+=cst ;
        }
    }
}
void update1(int x,int y,int cst)
{
    for(int i=x;i<=n;i+=i&-i)
    {
        for(int j=y;j>0;j-=j&-j)
        {
            f1[i][j]+=cst;
        }
    }
}
ll getsum1(int x1,int y1)
{
    ll sum = 0 ;
    //printf("aa %d %d \n",x1,y1);
    ///if(x1==0||y1==0)return sum ;
    int x=bd[x1][y1].fi;
    int y=bd[x1][y1].se;
    ///if(x==0||y==0)return sum ;
    for(int i=x;i>0;i-=i&-i)
    {
        for(int j=y;j<=2*n;j+=j&-j)sum+=f1[i][j];
    }
    return sum ;
}
ll getsum(int x,int y)
{
    ll sum = 0 ;
    for(int i=x;i<=n;i+=i&-i)
    {
        for(int j=y;j<=n;j+=j&-j)
        {
            sum+=f[i][j];
        }
    }
    return sum ;
}
ll query(int x,int y,int L)
{
    int l = y-L+1;
    if(L==1)
    {
        return a[x][y]/2;
    }
    pii tmp = {x-L+2,y};
    ll ans = 0 ;
    ans+=(getsum1(x,l)-getsum1(x,l+1)-getsum1(x-L,l+L)+getsum1(x-L,l+L+1))/2;
//return ans;
    ans+=getsum1(x,l+1)-getsum1(tmp.fi-1,y+1)-getsum(tmp.fi,y+1)+getsum(x+1,y+1);
    return ans ;
}
void pre_process()
{
    int k=1;
    for(int i=1;i<=n;i++,k++)
    {
        int dist = i ;
        for(int j=1;i-j>=0&&j<=n;j++)
        {
            bd[i-j+1][j]={dist,k};
            dist--;
        }
    }
    for(int j=2;j<=n;j++,k++)
    {
        int x = j ,dist = n;
        for(int i=n;i>=1&&x<=n;i--)
        {
            bd[i][x++]={dist,k};
            dist--;
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    pre_process();
    for(int i=1;i<=m;i++)
    {
        int typ,r,c,v;
        cin >> typ >> r >> c >> v ;
        if(typ==2)
        {
            int dif = v-a[r][c];
            update(r,c,dif);
            update1(bd[r][c].fi,bd[r][c].se,dif);
            a[r][c]=v;
        }
        else
        {
            cout << query(r,c,v) << '\n' ;
        }
    }
    return 0 ;
}
