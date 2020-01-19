#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
long long  a[N],b[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    cin >> n >> m ;
    for(int i=1;i<=n;i++)cin >> a[i];
    for(int j=1;j<=m;j++)cin >> b[j];
    long long ans = 0 ;
    sort(a+1,a+1+n);
    sort(b+1,b+1+m);
    if(a[n]>b[1])
    {
        cout << "-1" ;
        return 0;
    }
    else if(a[n]==b[1])
    {
        for(int j=1;j<=m;j++)ans+=b[j];
        for(int i=1;i<=n-1;i++)ans+=a[i]*(m);
        cout << ans ;
        return 0 ;
    }
    for(int j=1;j<=m-1;j++)ans+=b[j];
    ans+=a[n];
    ans+=a[n-1]*(m-1)+b[m];
    for(int i=1;i<=n-2;i++)ans+=a[i]*m;
    cout << ans ;
}
