#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
priority_queue<pii> pq ;
vector<pair<pii,int> > v ;
ll W ;
bool cmp(pair<pii,int> a,pair<pii,int> b)
{
    return 1ll*a.fi.fi*b.fi.se<1ll*b.fi.fi*a.fi.se ;
}
bool cst(ll q,int sk,int qk)
{
    return 1.0*sk/qk*q<=1.0*W;
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll Q=0 ;
    int n,i,j,x,y;
    pair<int,pair<long double,int> > f ={0,{0,0}};
    cin >> n >> W ;
    for(i=1;i<=n;i++)
    {
        cin >> x >> y ;
        v.push_back({{x,y},i});
    }
    sort(v.begin(),v.end(),cmp);
    for(auto it:v)
    {
        Q+=it.fi.se ;
        pq.push({it.fi.se,it.se});
        while(!pq.empty()&&!cst(Q,it.fi.fi,it.fi.se))
        {
            Q-=pq.top().fi ;
            pq.pop();
        }
        if(pq.size()>f.fi||(pq.size()==f.fi&&
            1.0*it.fi.fi/it.fi.se*Q<f.se.fi))
        {
            f={pq.size(),{1.0*it.fi.fi/it.fi.se*Q,it.se}};
        }
    }
    while(!pq.empty())pq.pop();
    Q=0 ;
    for(auto it:v)
    {
        Q+=it.fi.se ;
        pq.push({it.fi.se,it.se});
        while(!pq.empty()&&!cst(Q,it.fi.fi,it.fi.se))
        {
            Q-=pq.top().fi ;
            pq.pop();
        }
        if(it.se==f.se.se)
        {
            cout << f.fi << '\n' ;
            while(!pq.empty())
            {
                cout << pq.top().second << '\n' ;
                pq.pop();
            }
            cout << it.se ;
            return 0 ;
        }

    }
}
