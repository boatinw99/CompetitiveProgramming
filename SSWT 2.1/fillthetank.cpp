#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii;
#define fi first
#define se second
#define mp make_pair
const int N = 1e6+9,inf=2e9 ;
int bucket[50],lim=INT_MAX;
int minval[N];
priority_queue<pii,vector<pii>,greater<pii> > pq ;
void preprocess(int B)
{
    fill(minval+1,minval+N,inf);
    for(pq.push(mp(0,0));!pq.empty();pq.pop())
    {
        auto p=pq.top();
        if(p.fi!=minval[p.se])continue;
        for(int i=0;i<B;i++)
        {
            int pf = p.fi+bucket[i];
            if(pf<minval[pf%lim])
            {
                minval[pf%lim]=pf;
                pq.push({pf,pf%lim});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int B,Q,i,j,x  ;
    cin >> B >> Q ;
    for(i=0;i<B;i++)
    {
        cin >> bucket[i];
        lim=min(lim,bucket[i]);
    }
    preprocess(B);
    while(Q--)
    {
        cin >> x ;
        if(minval[x%lim]<=x)cout << "yes" ;
        else cout << "no";
        cout << '\n' ;
    }
}
