#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define fi first
#define se second
const int N = 2e5+9 ;
const ll pb = 98765431 ;
int pos[N];
int ssize[N];
vector<ll> hv[N] ; ///hash vector
vector<pair<string,int> > sst ; ///sorted string
vector<int> query;
int findlca(int u,int v)
{
    int l=0,r=min(ssize[u],ssize[v])+1 ;
    while(l+1<r)
    {
        int mid=l+r>>1;
        if(hv[u][mid]==hv[v][mid])l=mid;
        else r= mid ;
    }
    return l ;
}
ll sld(int len)
{
    ll ans=0 ;
    int size,l,i,j,x,y ;
    query.emplace_back(0);sort(query.begin(),query.end());
    query.emplace_back(0); size=query.size()-1 ;
    for(l=1;l+len-1<size;l++)
    {
        ///b search + lca
        x=findlca(sst[query[l]].se,sst[query[l+len-1]].se);
        y=findlca(sst[query[l]].se,sst[query[l-1]].se);
        y=max(y,findlca(sst[query[l]].se,sst[query[l+len]].se));
        ans+=max(0,x-y);
    }
    return ans ;
}
main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int i,j,k,n,m,T,len ;
    ll hash ;
    string s;
    cin >> n >> T ;
    for(i=1;i<=n;i++)
    {
        cin >> s;
        sst.emplace_back(s,i);
        hash=0 ; ssize[i]=len=s.size();
        hv[i].emplace_back(0);
        for(j=0;j<len;j++)
        {
            hash*=pb;
            hash+=s[j];
            hv[i].emplace_back(hash);
        }
    }
    sst.emplace_back("A",0);
    sort(sst.begin(),sst.end());i=0;
    for(auto it:sst)pos[it.se]=i++;
    while(T--)
    {
        cin >> k >> len ;
        query.clear();
        while(k--)cin >> i,query.emplace_back(pos[i]);
        cout << sld(len) << '\n' ;
    }
}
