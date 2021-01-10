#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ;
pii A[N] ; 
vector<int> V[N]; 
priority_queue<int> pq ;
void init(int n)
{
    for(int i=0;i<=n;i++)A[i]={0,0};
    while(!pq.empty())pq.pop();
    for(int i=0;i<=n;i++)V[i].clear();
}
pii solve(int n)
{
    pii ans = {0,0};
    for(int i=n;i>=1;i--)
    {
        for(auto it:V[i])
        {
            pq.push(it);
        }
        if(!pq.empty())
        {
            ans.fi+=i;
            ans.se+=min(pq.top(),i);
            pq.pop();
        }
    }
    return ans ; 
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int q ; 
    cin >> q ;
    while(q--)
    {
        int n ;
        cin >> n ;
        init(n);
        for(int i=1,u,v ;i<=n;i++)
        {
            cin >> u >> v ;
            A[u].fi++;
            A[u].se+=v;
        }
        for(int i=1;i<=n;i++)
        {
            V[A[i].fi].push_back(A[i].se);
        }
        pii ans = solve(n) ;
        cout << ans.fi << " " << ans.se << '\n' ;
    }
    return 0 ;
}