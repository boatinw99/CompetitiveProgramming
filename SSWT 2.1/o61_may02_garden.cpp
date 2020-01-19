#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1009 , K = 10 , md = 1e6+3 ;
vector<int> g[N];
queue<pii> q;
int comb[N][1<<K],a[N];
bool vst[N][1<<K];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m,c,i,j,u,v ;
    cin >> n >> m >> c ;
    for(i=0;i<n;i++)
    {
        cin >> a[i] ;
        comb[i][1<<a[i]]=1 ;
        q.push({1<<a[i],i});
    }
    int bits=(1<<c)-1 ;
    for(i=1;i<=m;i++)
    {
        cin >> u >> v ;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }
    while(!q.empty())
    {
        int mask = q.front().fi,town=q.front().se ;
        q.pop();
        for(auto it:g[town])
        {
            if((mask&(1<<a[it]))==0)
            {
                comb[it][mask|(1<<a[it])]+=comb[town][mask];
                comb[it][mask|(1<<a[it])]%=md ;
                if(vst[it][mask|(1<<a[it])]==0)
                {
                    vst[it][mask|(1<<a[it])]++;
                    q.push({mask|(1<<a[it]),it});
                }
            }
        }
    }
    int ans=0;
    for(i=0;i<n;i++)
    {
        ans+=comb[i][bits];
        ans%=md ;
    }
    cout << ans ;
}
