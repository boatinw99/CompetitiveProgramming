#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9 , inf = 2e9 ;
int n ;
ll a[N],b[N];
int water[N];
ll total(ll add)
{
    ll ret = 0 ;
    for(int i=1;i<=n;i++)
    {
        int cur ;
        if(b[i]<add)cur=b[i];
        else cur=max(a[i],add);
        water[i]=cur;
        ret+=cur;
    }
    return ret ;
}
int main()
{
    ll X,add=0;
    cin >> n >> X ;
    for(int i=1;i<=n;i++)cin >> a[i] >> b[i] ;
    for(int i=29;i>=0;i--)if(total(add+(1<<i))<=X)add+=(1<<i);
    X-=total(add);
    for(int i=1;i<=n;i++)
    {
        if(water[i]<b[i]&&X)
        {
            X--;
            water[i]++;
        }
    }
    int mn = inf , mx = 0 ;
    for(int i=1;i<=n;i++)
    {
        mn=min(mn,water[i]);
        mx=max(mx,water[i]);
    }
    cout << mx-mn ;
    return 0 ;
}
