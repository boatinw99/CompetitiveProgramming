#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
int a[N],pos[N],n ;
bool ps[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n ;
    for(int i=1;i<=n;i++)cin >> a[i] , pos[a[i]]=i ;
    int ans = 0 , l = 1 , r = n , cnt = 0 ;
    for(int i=1;i<=n;i++)
    {
        int x = pos[i];
        ps[x]++;
        while(a[l]<=i&&l<=n)
        {
            if(ps[l])cnt++;
            l++;
        }
        while(a[r]<=i&&r>=1)
        {
            if(ps[r])cnt++;
            r--;
        }
        ans=max(ans,i-cnt+2);
    }
    cout << ans ;
}
