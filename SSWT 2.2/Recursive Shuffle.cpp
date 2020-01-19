#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
int n,m,pos[N] ;
int recur(int sz,int x)
{
    if(sz==1)return 1 ;
    if(x&1)return recur((sz+1)/2,x/2+1)+sz/2;
    else return recur(sz>>1,x>>1);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    int x ;
    for(int i=1;i<=m;i++)
    {
        cin >> x ;
        pos[i]=recur(n,x);
    }
    for(int i=2;i<=m;i++)
    {
        if(pos[i]!=pos[i-1]+1)
        {
            cout << "0" ;
            return 0 ;
        }
    }
    cout << "1" ;
    return 0 ;
}
