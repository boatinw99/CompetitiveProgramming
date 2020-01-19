#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 3e5+9,inf = 1e9+7 ;
int a[N],pos[N];
int mx[N],mn[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    iota(pos,pos+N,0);
    int n , ans = inf;
    cin >> n ;
    for(int i=1;i<=n;i++)cin >> a[i];
    sort(pos+1,pos+n+1,[&](const int l, const int r){return a[l]<a[r];});
    mn[n+1]=inf ;
    for(int i=n;i>=1;i--)
    {
        mx[i]=max(pos[i],mx[i+1]);
        mn[i]=min(pos[i],mn[i+1]);
    }
    for(int i = 1; i < n; i++)
    {
        ans=min(ans,a[pos[i]]/abs(pos[i]-mx[i+1]));
        ans=min(ans,a[pos[i]]/abs(pos[i]-mn[i+1]));
    }
    cout << ans ;
    return 0;
}
