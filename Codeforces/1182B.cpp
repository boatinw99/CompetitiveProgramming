#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
typedef pair<ll,ll> pll ; 
#define fi first
#define se second
const ll INF = 1e18 ; 
const int N = 509 , mod = 1e9+7 , inf = 1e9 ;
char A[N][N];
int n,m; 
void split(int x,int y,int dx,int dy)
{
    if(dy==0)
    {
        for(;x<=n&&x>0;x+=dx)
        {
            if(A[x][y]=='.')
            {
                return ;
            }          
            A[x][y]='.';
        }
    }
    else 
    {
        for(;y<=m&&y>0;y+=dy)
        {
            if(A[x][y]=='.')
            {
                return ; 
            }
            A[x][y]='.';
        }
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ; 
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin >> A[i][j] ;
        }
    }
    int cnt = 0 ;
    for(int i=2;i<=n&&cnt==0;i++)
    {
        for(int j=2;j<=m;j++)
        {
            if(A[i][j]=='*'&&A[i+1][j]=='*'&&A[i-1][j]=='*'&&A[i][j+1]=='*'&&A[i][j-1]=='*')
            {
                split(i,j,1,0);
                A[i][j]='*';
                split(i,j,-1,0);
                A[i][j]='*';
                split(i,j,0,-1);
                A[i][j]='*';
                split(i,j,0,1);
                A[i][j]='.';
                cnt++;
                break; 
            }
        }
    }
    if(cnt==1)
    {
        bool find = 0 ;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(A[i][j]=='*')
                {
                    find++;
                }
            }
        }
        if(find==0)
        {
            cout << "YES" << '\n' ;
            return 0 ;
        }
    }
    cout << "NO" << '\n' ;
    return 0 ;
}