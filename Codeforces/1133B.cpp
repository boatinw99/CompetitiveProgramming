#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
#define fi first
#define se second
#define mid (l+r>>1)
const int N = 2e5+9 ;
const double pi = 3.14159265358979;
vector<int> a(N),b(N);
map<pair<int,int>,int> m;
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0);
    int n,i,j ;
    cin >> n;
    for(i = 0;i<n;i++) cin >> a[i];
    for(i = 0;i<n;i++) cin >> b[i];
    int ba = 0;
    for(i = 0;i < n;i++)
    {
        if(a[i]==0 and b[i]==0)
        {
            ba++;
            continue;
        }
        else if(a[i]==0 and b[i]!=0)continue;
        if(b[i]==0)
        {
            a[i] = -1;
            m[{-1,0}]++;
            continue;
        }
        int g = __gcd(a[i],b[i]);
        a[i]/=g;
        b[i]/=g;
        m[{a[i],b[i]}]++;
    }
    int mx = 0;
    for(i = 0;i < n;i++)
    {
        if(a[i]==0) continue;
        mx = max(mx,m[{a[i],b[i]}]);
    }
    cout << mx+ba ;
}
