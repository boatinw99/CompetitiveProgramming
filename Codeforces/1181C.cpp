#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ;
#define fi first
#define se second 
const double pi = 3.141592653589 ; 
const ll INF = 1e18 ; 
const int N = 1e3+19 , mod = 1e9+7 , inf = 1e9 , AL = 30 ;
int qs[N][N][AL],A[N][N],n,m ;
int getval(int x1,int y1,int x2,int y2,int typ)
{
    return qs[x2][y2][typ]-qs[x1-1][y2][typ]-qs[x2][y1-1][typ]+qs[x1-1][y1-1][typ];
}
bool check(int x1,int y1,int x2,int y2)
{
    int typ = A[x1][y1]; 
    if(x1>x2)swap(x1,y1),swap(x2,y2);
    int area = (x2-x1+1)*(y2-y1+1);
    while(getval(x1,y1,x2,y2,typ)>area);
    return (getval(x1,y1,x2,y2,typ)==area);
}
int findd(int x,int y)
{
    int t = A[x][y] ;
    int l = x,r=n+1;
    while(l+1<r)
    {
        int mid = l+r >> 1 ; 
        if(check(x,y,mid,y))l=mid ;
        else r = mid ;
    }
    return l ;
}
ll query(int x,int y,int len)
{
    int t = A[x][y] ;
    int l = y , r = m+1 ; 
    if((check(x,y,x+len-1,y)==0)||(check(x+len,y,x+2*len-1,y)==0)||(check(x+2*len,y,x+3*len-1,y)==0))return 0 ;
    while(l+1<r)
    {
        int mid = l+r >> 1 ; 
        if(check(x,y,x+len-1,mid)&&check(x+len,y,x+2*len-1,mid)&&check(x+2*len,y,x+3*len-1,mid))l=mid;
        else r = mid ;
    }
    return l-y+1 ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            char c ;
            cin >> c ; 
            int x = c-'a' ;
            A[i][j]=x ;
        }
    }
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)for(int k=0;k<AL;k++)
    {
        qs[i][j][k]=qs[i][j-1][k]+qs[i-1][j][k]-qs[i-1][j-1][k]+(A[i][j]==k);
    }
    ll ans = 0 ;
    for(int x1=1;x1<=n;x1++)
    {
        for(int y1=1;y1<=m;y1++)
        {
            int dd = findd(x1,y1);
            int lenD = dd-x1+1; 
            if(x1+lenD*3-1<=n&&(A[x1+lenD][y1]!=A[x1+2*lenD][y1]))
            {
                ans+=query(x1,y1,lenD);
            }
        }
    }
    cout << ans << '\n' ; 
    return 0 ;
}