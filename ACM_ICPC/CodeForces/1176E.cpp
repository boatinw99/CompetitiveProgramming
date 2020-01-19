#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second 
const int N = 2e5+9 ; 
vector<int> G[N];
bool vst[N];
int marked[N];
queue<pii> Q ; 
void init(int n)
{
    for(int i=1;i<=n;i++)
    {
        marked[i]=0;
        vst[i]=0;
        G[i].clear();
    }
}
int comp()
{
    int cnt = 0 ;
    Q.push({1,1});
    vst[1]++;
    while(!Q.empty())
    {
        pii x = Q.front();
        Q.pop();
        if(x.se==1)marked[x.fi]=1,cnt++; 
        for(auto it:G[x.fi])
        {
            if(!vst[it]++)
            {
                Q.push({it,x.se^1});
            }
        }
    }
    return cnt ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int M ;
    cin >> M ;
    while(M--)
    {
        int n,m ;
        cin >> n >> m ; 
        init(n);
        for(int i=1,u,v ;i<=m;i++)
        {
            cin >> u >> v ;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }
        int cnt = comp();
        if(cnt<=n/2)cout << cnt << '\n' ;
        else cout << n-cnt << '\n' ;
        for(int i=1;i<=n;i++)
        {
            if(marked[i]&&cnt<=n/2)cout << i << " " ;
            else if(!marked[i]&&cnt>n/2)cout << i << " " ;
        }
        cout << '\n' ; 
    }
    return 0 ;
}