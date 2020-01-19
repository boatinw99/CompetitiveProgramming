#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9,inf=1e8;
map<int,set<int>> mp ;
map<int,multiset<int>> dist ;
int a[N];
void E(multiset<int> &s,int val)
{
    auto it = s.lower_bound(val);
    s.erase(it);
}
void del(int x)
{
    auto it = mp[a[x]].lower_bound(x);
    int dl = *next(it)-*it , dr = *it-*prev(it) , d = *next(it)-*prev(it);
    E(dist[a[x]],dl);
    E(dist[a[x]],dr);
    dist[a[x]].insert(d);
    mp[a[x]].erase(x);
}
void add(int x)
{
    mp[a[x]].insert(x);
    auto it = mp[a[x]].lower_bound(x);
    int d = *next(it)-*prev(it),dl=*it-*prev(it),dr=*next(it)-*it;
    E(dist[a[x]],d);
    dist[a[x]].insert(dl);
    dist[a[x]].insert(dr);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    cin >> n >> m ;
    long long ans = 0 ;
    mp[0].insert(-inf);
    mp[0].insert(inf);
    dist[0].insert(inf+inf);
    for(int i=0;i<=n-1;i++)add(i);
    for(int i=1,x,y ;i<=m;i++)
    {
        cin >> x >> y ;
        if(mp[y].empty())
        {
            mp[y].insert(-inf);
            mp[y].insert(inf);
            dist[y].insert(inf+inf);
        }
        del(x);
        a[x]=y;
        add(x);
        ans+=(*dist[y].begin()<=n?*dist[y].begin():0);
    }
    cout << ans ;
    return 0 ;
}
