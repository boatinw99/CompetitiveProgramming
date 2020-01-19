#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
const int N = 1e5+9 ;
ll a[N],sum[N] ;
ll getamount(int n)
{
    if(n&1){
        return 1ll*n*(n-1)/2+1;
    }
    else return 1ll*n*(n-1)/2+(n-2)/2+1;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    cin >> n >> m ;
    for(int i=1;i<=m;i++){
        int q ; 
        cin >> q >> a[i] ;
    }
    sort(a+1,a+1+m,greater<ll>());
    for(int i=1;i<=m;i++){
        sum[i]=a[i]+sum[i-1];
    }
    for(int i=m;i>=1;i--){
        if(getamount(i)<=n){
            cout << sum[i] << '\n' ;
            return 0 ;
        }
    }
    cout << "0" << '\n' ;
    return 0 ;
}