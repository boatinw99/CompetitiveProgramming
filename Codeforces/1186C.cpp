#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<int,int> pii ;
#define fi first 
#define se second 
const ll INF = 1e18 ; 
const int N = 1e6+9 , inf = 1e9 , mod = 1e9+7 ;
int n,m ;
string s,t ;
vector<int> V ; 
int pref[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> s >> t ;
    n = s.size();
    m = t.size();
    int cnt = 0 , ans = 0 ;
    for(int i=0;i<m;i++)cnt+=t[i]=='1';
    for(int i=1;i<=n;i++)pref[i]+=pref[i-1]+(s[i-1]=='1');
    for(int i=m;i<=n;i++)
    {
        ans+=((pref[i]-pref[i-m])%2)==(cnt%2);
    }
    cout << ans << '\n' ; 
    return 0 ;
}