#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ; 
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll INF = 1e18 ; 
const int N = 1e5+9 ; 
ll f[N];
vector<pii> V ; 
void update(int x,ll nw)
{
    for(;x;x-=x&-x)
    {
        f[x]=min(f[x],nw);
    }
}
ll getmin(int x)
{
    if(x==0)return 0 ;
    ll mn = INF ; 
    for(;x<N;x+=x&-x)
    {
        mn=min(mn,f[x]);
    }
    return mn ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    cin >> n >> m ;
    fill(f,f+N-1,INF);
    for(int i=1;i<=n;i++)
    {
        int x,s ; 
        cin >> x >> s ; 
        V.emplace_back(x,s);
    }
    sort(V.begin(),V.end(),[&](pii a,pii b){
        return a.fi-b.fi<=b.fi-b.fi;
    });
    for(auto it:V)
    {
        for(int i=0;i<=m;i++)
        {
            int l = max(1,it.fi-it.se-i);
            int r = min(m,it.fi+it.se+i);
            ll val = getmin(l-1)+i;
            update(r,val);
        }
    }
    cout << getmin(m) << '\n' ; 
    return 0 ;
}