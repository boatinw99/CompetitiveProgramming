#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 2e4+9 ;
const ll pb = 98765431 ;
ll pi[N];
int a[N],n;
map<ll,int> mp;
bool hashing(int len)
{
    int i ;
    ll hash=0;
    for(i=1;i<len;i++)hash=hash*pb+a[i];
    for(i;i<n+len;i++)
    {
        hash=hash-pi[len-1]*a[i-len];
        hash=hash*pb+a[i];
        mp[hash]++;
    }
    for(auto it:mp)
    {
        if(it.se>1)return 0;
    }
    return 1;
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int i,j ;
    cin >> n ;
    int l=0,r=n+1;
    pi[0]=1;
    for(i=1;i<=n;i++)
    {
        cin >> a[i];
        a[i+n]=a[i];
        pi[i]=pi[i-1]*pb;
    }
    while(l+1<r)
    {
        if(hashing(mid))r=mid; ///not circular
        else l=mid;
        mp.clear();
    }
    cout << ((l==n)?-1:l) ;
}
