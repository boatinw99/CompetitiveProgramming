#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<ll,int> pli ;
typedef pair<int,ll> pil ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll INF = 1e18 ;
const int N = 1e5+9 , inf = 1e9 , mod = 1e9+7 ;
bool b[10];
bool check(int i)
{
    memset(b,0,sizeof b);
    while(i>0)
    {
        int x = i%10;
        if(b[x])
        {
            return 0 ;
        }
        b[x]++;
        i/=10 ;
    }
    return 1 ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int l,r ;
    cin >> l >> r ;
    for(int i=l;i<=r;i++)
    {
        if(check(i))
        {
            cout << i << '\n' ;
            return 0 ;
        }
    }
    cout << "-1" << '\n' ;
    return 0 ; 
}