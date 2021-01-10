#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 2e5+9 , LOG = log2(N)+1 ; 
int up[N][LOG],arr[N],par[N];
vector<pair<pii,int>> V ; 
pii range[N],query[N];
set<pii> S ; 
int n,m ;
int getans(int y,int u)
{
    if(u==0)return -1 ;
    if(range[u].se>=y)return 1 ;
    int ans = 1 ;
    for(int i=LOG-1;i>=0;i--)
    {
        if(range[up[u][i]].se<y)
        {
            ans+=1<<i ;
            u=up[u][i];
        }
    }
    //while(range[u].se&&u!=up[u][0])u=up[u][0];
    u=up[u][0];
    if(range[u].se<y)return -1 ; 
    return ans+1 ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> m ; 
    for(int i=1;i<=n;i++)
    {
        cin >> range[i].fi >> range[i].se ;
        arr[i]=i;
        V.push_back({{range[i].fi,0},i});//(,0) is + , (,1) is - 
        V.push_back({{range[i].se,1},i});
    }
    for(int i=1;i<=m;i++)
    {
        cin >> query[i].fi >> query[i].se ;
        V.push_back({{query[i].fi,2},i});
    }
    sort(V.begin(),V.end());
    for(auto it:V)
    {
        if(it.fi.se==1)
        {
            int mxR = S.rbegin()->se ;
            up[it.se][0] = mxR ; 
            S.erase({it.fi.fi,it.se});
        }
        else if(it.fi.se==0)
        {
            S.insert({range[it.se].se,it.se});
        }
        else 
        {
            int mxR = 0 ; 
            if(!S.empty())mxR = S.rbegin()->se ;
            par[it.se] = mxR ; 
        }
    }
    for(int j=1;j<LOG;j++)
    {
        for(int i=1;i<=n;i++)
        {
            up[i][j]=up[up[i][j-1]][j-1];
        }
    }
    for(int i=1;i<=m;i++)
    {
        cout << getans(query[i].se,par[i]) << '\n' ;
    }
    return 0 ;
}