#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
typedef pair<ll,int> pli ;
typedef pair<int,ll> pil ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const ll INF = 1e18 ;
const int N = 1e5+9 , inf = 1e9 , mod = 1e9+7 ;
int lvl[N];
vector<int> s[4] ; /// in 2  
set<int> g[N] ; 
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,u,v  ; 
    cin >> n >> m ;
    for(int i=1;i<=m;i++)
    {
        cin >> u >> v ;
        g[u].insert(v);
        g[v].insert(u);
    }
    lvl[1]=1 ;
    s[1].emplace_back(1);
    for(int i=2;i<=n;i++)
    {
        auto it = g[1].lower_bound(i);
        if(it==g[1].end()||(*it!=i))
        {
            lvl[i]=1 ;
            s[1].emplace_back(i);
        }
    }
    int x = 0 ;
    for(int i=2;i<=n;i++)
    {
        if(lvl[i]==0)
        {
            x=i;
            break;
        }
    }
    /// x in lvl2
    if(x==0)
    {
        cout << "-1" << '\n' ;
        return 0 ;
    }
    lvl[x]=2 ;
    s[2].emplace_back(x);
    for(int i=2;i<=n;i++)
    {
        if(lvl[i]==0)
        {
            auto it = g[x].lower_bound(i);
            if(it==g[x].end()||(*it!=i))
            {
                lvl[i]=2 ;
                s[2].emplace_back(i);
            }
            else
            {
                lvl[i]=3;
                s[3].emplace_back(i);
            }
        }
    }
    int edge = 0 ;
    if(!s[1].empty()&&!s[2].empty()&&!s[3].empty()&&s[1].size()+s[2].size()+s[3].size()==n)
    {
        for(auto d1:s[1])
        {
            for(auto d2:s[2])
            {
                auto it = g[d1].lower_bound(d2);
                if(it==g[x].end()||(*it!=d2))
                {
                    cout << "-1" << '\n' ;
                    return 0 ;
                }
                edge++;
            }
            for(auto d2:s[3])
            {
                auto it = g[d1].lower_bound(d2);
                if(it==g[x].end()||(*it!=d2))
                {
                    cout << "-1" << '\n' ;
                    return 0 ;
                }
                edge++;
            }
        }
        for(auto d1:s[2])
        {
            for(auto d2:s[3])
            {
                auto it = g[d1].lower_bound(d2);
                if(it==g[x].end()||(*it!=d2))
                {
                    cout << "-1" << '\n' ;
                    return 0 ;
                }
                edge++;
            }
        }
        if(edge!=m)
        {
            cout << "-1" << '\n';
            return 0 ;
        }
        for(int i=1;i<=n;i++)
        {
            cout << lvl[i] << " " ;
        }
        cout << '\n' ;
        return 0 ;
    }
    cout << "-1" << '\n' ;
    return 0 ; 
}