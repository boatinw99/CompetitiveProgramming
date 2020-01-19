#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e6+9 ; 
ll ans[N];
struct pot
{
    int val ;
    int idx ; 
    bool typ ; 
};
vector<pot> mt[N];
multiset<ll> nw[N]; 
void E(multiset<ll> &m,ll dell)
{
    auto it = m.find(dell);
    m.erase(it);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,w ;
    cin >> n >> w ;
    for(int i=1,l ;i<=n;i++)
    {
        cin >> l ;
        for(int j=1;j<=l;j++)
        {
            int val ; 
            cin >> val ;     
            mt[j].push_back({val,i,0});
            mt[j+(w-l)+1].push_back({val,i,1});
        }
        mt[1].push_back({0,i,0});
        mt[w-l+1].push_back({0,i,1});
        mt[l+1].push_back({0,i,0});
    }
    ll ans = 0 ;
    for(int i=1;i<=w;i++)
    {
        for(auto it:mt[i])
        {
            if(it.typ==0)///add 
            {
                if(!nw[it.idx].empty())ans-=*nw[it.idx].rbegin(); 
                nw[it.idx].insert(it.val);  
                ans+=*nw[it.idx].rbegin();
            }
            else 
            {
                ans-=*nw[it.idx].rbegin();
                E(nw[it.idx],it.val);
                if(!nw[it.idx].empty())ans+=*nw[it.idx].rbegin();
            }
        }
        cout << ans << " " ;
    }
    return 0 ;
}