#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ;
int a[N],qs[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1,x;i<=n;i++)
    {
        cin >> x ;
        a[x]++;
    }
    for(int i=1;i<N;i++)qs[i]+=qs[i-1]+a[i];
    pair<int,pii> mx={0,{0,0}} ;
    for(int l=1;l<N;)
    {
        int r = l+1 ;
        if(a[l]==0)
        {
            l++;
            continue;
        }
        while(a[r]>=2)r++;
        int L,R ;
        if(a[r]==1)L=l,R=r;
        else L=l,R=r-1;
        mx=max(mx,{qs[R]-qs[L-1],{L,R}});
        l=r;
    }
    cout << mx.fi << '\n' ;
    for(int i=mx.se.fi;i<=mx.se.se;i++)
    {
        cout << i << " " ;
        a[i]--;
    }
    for(int i=mx.se.se;i>=mx.se.fi;i--)
    {
        while(a[i])
        {
            cout << i << " " ;
            a[i]--;
        }
    }
    return 0 ;
}
