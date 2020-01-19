#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
typedef long long ll ;
#define fi first
#define se second 
const int N = 1509 ;
map<ll,vector<pii>> mp ;
int arr[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i] ;
    }
    for(int j=1;j<=n;j++)
    {
        ll sum = 0 ;
        for(int i=j;i>=1;i--)
        {
            sum+=arr[i];
            if(mp[sum].empty())mp[sum].push_back({0,0});
            if(i>mp[sum].back().se)mp[sum].push_back({i,j});
        }
    }
    pair<int,vector<pii>> mx = {0,{{0,0}}} ;
    for(auto it:mp)
    {
        mx=max(mx,{it.se.size(),it.se});
    }
    cout << mx.fi-1 << '\n' ;
    for(int i=1;i<mx.fi;i++)
    {
        cout << mx.se[i].fi << " " << mx.se[i].se << '\n' ;
    }
    return 0 ;
}