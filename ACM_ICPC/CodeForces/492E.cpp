#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 1e6+9 ;
int ax[N],ans[N];
///ax[i] -> store the number of move need to make to come to axis i  
// ans[i] -> store the number of apple trees can achive by this row 
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,dx,dy ;
    cin >> n >> m >> dx >> dy ; 
    for(int i=0,x=0;i<n;i++)
    {
        ax[x]=i;
        x=(x+dx)%n;
    }
    for(int i=1,x,y ;i<=m;i++)
    {
        cin >> x >> y ;
        int move = ax[x];
        ans[(y-1ll*move*dy+1ll*n*n)%n]++;
    }
    pii mx = {0,0} ;
    for(int i=0;i<n;i++)
    {
        mx = max(mx,{ans[i],i});
    }
    cout << "0 " << mx.se << '\n' ;
    return 0 ;
}