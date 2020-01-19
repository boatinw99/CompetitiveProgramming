#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const ll inf = 1e18 ;
const int N = 1e6+9 , M = 10000009 ;
vector<pii> divs;
int sieve[M],a[N],n ;
pii mn[M];
void preprocess()
{
    sieve[1]=2;
    for(int i=2;i<M;i++)
        if(!sieve[i])for(int j=i;j<M;j+=i)if(!sieve[j])sieve[j]=i ;
}
void update(int x,int idx)
{
    if(mn[x].fi==-1)mn[x].fi=idx ;
    else if(mn[x].se==-1)mn[x].se=idx ;
}
void rec(int pos,int cnt,int idx)
{
    if(pos==divs.size())
    {
        update(cnt,idx);
        return ;
    }
    for(int i=0;i<=divs[pos].se;i++)
    {
        rec(pos+1,cnt,idx);
        cnt*=divs[pos].fi ;
    }
}
void add(int pos)
{
    int x = a[pos] ;
    while(x>1)
    {
        if(!divs.empty()&&sieve[x]==divs.back().fi)divs.back().se++;
        else divs.push_back({sieve[x],1});
        x/=sieve[x];
    }
    rec(0,1,pos);
    divs.clear();
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    vector<int> V ;
    cin >> n ;
    preprocess();
    a[0]=INT_MAX ;
    pair<ll,pii> ans={inf,{0,0}} ;
    for(int i=0;i<M;i++)mn[i]={-1,-1};
    for(int i=1;i<=n;i++)
    {
        cin >> a[i] ;
        V.emplace_back(i);
    }
    sort(V.begin(),V.end(),[&](const int x,int y){
         return a[x]<a[y];
         });
    for(auto it:V)add(it);
    for(int i=1;i<M;i++)
    {
        int x = mn[i].fi,y=mn[i].se ;
        if(x>0&&y>0)
        {
            if(1ll*a[x]*a[y]/i<ans.fi)
            {
                ans={1ll*a[x]*a[y]/i,{x,y}};
            }
        }
    }
    cout << min(ans.se.fi,ans.se.se) << " " << max(ans.se.se,ans.se.fi) ;
    return 0 ;
}
