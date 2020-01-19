#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
int a[N],sub[N];
vector<int> g[N];
void dfs0(int u)
{
    sub[u]=1;
    for(auto it:g[u])
    {
        dfs0(it);
        sub[u]+=sub[it];
    }
}
void dfs1(int u,multiset<int> &s)
{
    int mx=0,tmp=0;
    //printf("a %d\n",u);
    for(auto it:g[u])if(sub[it]>mx)mx=sub[it],tmp=it;
    if(tmp)dfs1(tmp,s);
    for(auto it:g[u])
    {
        if(it!=tmp)
        {
            multiset<int> t ;
            dfs1(it,t);
            for(auto it1:t)s.insert(it1);
        }
    }
    auto it=s.upper_bound(a[u]);
    //printf("aaa %d %d %d\n",u,s.size(),*it);
    if(it==s.end())
    {
        s.insert(a[u]);
    }
    else
    {
        s.erase(it);
        s.insert(a[u]);
    }
}
main()
{
    multiset<int> ans ;
    int n,i,j,u,v ;
    cin >> n ;
    for(i=0;i<n;i++)cin >> a[i];
    for(i=1;i<n;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
    }
    dfs1(0,ans);
    cout << n-ans.size();
}
