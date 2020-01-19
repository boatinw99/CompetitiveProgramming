#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
typedef long long ll ;
typedef pair<ll,int> pli;
#define fi first
#define se second
const int N = 1e3+9,sz=59 ;
const ll inf = 1ll<<60;
int fav[N],k[sz];
ll mark[N];
ll minv[sz];
priority_queue<pli,vector<pli>,greater<pli> > pq;
vector<pii> v ;
void precompute(int B,int lim)
{
    fill(minv,minv+sz,inf);
    minv[0]=0;
    for(pq.push({0,0});!pq.empty();pq.pop())
    {
        pli p = pq.top();
        if(p.fi!=minv[p.se])continue ;
        for(int i=0;i<B;i++)
        {
            ll pf = p.fi + k[i] ;
            if(pf<minv[pf%lim])
            {
                minv[pf%lim]=pf ;
                pq.push({pf,pf%lim});
            }
        }
    }
}
main()
{
    int T,n,B,i,j ;
    cin >> T ;
    while(T--)
    {
        cin >> n ;
        for(i=1;i<=n;i++)cin >> fav[i],v.emplace_back(fav[i],i);
        cin >> B ;
        int lim=2e9;
        for(i=0;i<B;i++)
        {
            cin >> k[i];
            lim=min(lim,k[i]);
        }
        precompute(B,lim);
        sort(v.begin(),v.end());
        memset(mark,-1,sizeof mark);
        ll ans=0 ;
        for(auto it:v)
        {
            ll max1=-1 ;
            if(fav[it.se]>fav[it.se+1])max1=max(max1,mark[it.se+1]);
            if(fav[it.se]>fav[it.se-1])max1=max(max1,mark[it.se-1]);
            max1=max1*2+1;
            while(minv[max1%lim]>max1)max1++;
            mark[it.se]=max1;
            ans+=max1;
        }
        v.clear();
        double pr= 1.0*ans/n ;
        printf("%.6f\n",pr);
    }
}
