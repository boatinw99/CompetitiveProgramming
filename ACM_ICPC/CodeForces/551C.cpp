#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mid (l+r>>1)
const int N = 1e5+9 ; 
int n,m,arr[N],arr1[N];
bool comp(ll T)
{
    int r = n ; 
    for(int i=1;i<=n;i++)arr1[i]=arr[i];
    for(int i=1;i<=m&&r;i++)
    {
        ll times = T ; 
        while(arr1[r]==0&&r)r--;
        if(times<r)break ; 
        times-=r;
        while(r)
        {
            if(times>=arr1[r])times-=arr1[r],arr1[r]=0,r--;
            else 
            {
                arr1[r]-=times ; 
                break ; 
            }
        }
    }
    return r==0 ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ; 
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    ll l=0,r=1e16 ;
    while(l+1<r)
    {
        if(comp(mid))r=mid ;
        else l=mid;
    }
    cout << r << '\n' ;
    return 0 ;
}