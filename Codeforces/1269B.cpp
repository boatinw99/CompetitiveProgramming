#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second 
const int N = 2e3+9 , mod = 1e9+7 ; 
int n,m ;
int a[N],b[N];
int match(int add)
{
    vector<int> A,B ;
    for(int i=1;i<=n;i++)A.push_back((a[i]+add)%m),B.push_back(b[i]);
    sort(A.begin(),A.end());
    sort(B.begin(),B.end());
    for(int i=0;i<n;i++)
    {
        if(A[i]!=B[i])return m ;
    }
    return add;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] ;
    }
    for(int i=1;i<=n;i++)cin >> b[i];
    int ans = m ; 
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    for(int j=1;j<=n;j++)
    {
        ans=min(ans,match((-a[1]+b[j]+m)%m));
    }
    cout << ans << '\n' ;
    return 0 ;
}