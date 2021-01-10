#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 1e6+9 , inf = 1e9+7 ; 
int arr[N],cnt[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    cin >> n >> m ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i] ;
        if(arr[i]<=m)
        {
            cnt[arr[i]]++;
        } 
    }
    for(int i=m;i>=1;i--)
    {
        for(int j=i+i;j<=m;j+=i)
        {
            cnt[j]+=cnt[i];
        }
    }
    pii mx = {0,1};
    for(int i=1;i<=m;i++)
    {
        if(cnt[i]>mx.fi)
        {
            mx = {cnt[i],i};
        }
    }
    cout << mx.se << " " << mx.fi << '\n' ;
    for(int i=1;i<=n;i++)
    {
        if(mx.se%arr[i]==0)cout << i << " " ;
    }
    return 0 ;
}