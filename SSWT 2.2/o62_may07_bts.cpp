#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 3009 ;
//vector<pii> rang;
priority_queue<pair<int,pii> > pq1,pq2;
int dist[N];
int main()
{
    int n,m,a,b,cnt=0,cst,ans=0 ;
    bool ed = 0 ;
    cin >> n >> m >> a >> b ;
    if(a>b)swap(a,b);
    for(int i=1;i<n;i++)dist[i]=1;
    for(int i=1,u,v,x ;i<=m;i++)
    {
        cin >> u >> v >> x ;
        cst=x;
        if(u>v)swap(u,v);
        v--;
        if(x<=a)ed++;
        else if(x<=b)
        {
            pq1.push({v-u+1,{u,v}});
            for(int j=u;j<=v;j++)dist[j]=0;
        }
        else
        {
            pq2.push({v-u+1,{u,v}});

        }
    }
    if(ed)
    {
        cout << "-1" ;
        return 0 ;
    }
    /** start **/
    while(!pq2.empty()&&!pq1.empty())
    {
        if(pq2.top().fi<=pq1.top().fi)break;
        pair<int,pii> tmp1 = pq1.top(),tmp2=pq2.top();
        pq1.pop();
        pq2.pop();
        pq2.push(tmp2);
        pq1.push(tmp1);
    }
    while(!pq1.empty())
    {
        int x = pq1.top().se.fi , y= pq1.top().se.se;
        for(int i=x;i<=y;i++)dist[i]=0;
        pq1.pop();
    }
    for(int i=1;i<n;i++)
    {
        if(dist[i]==1)ans+=b;
        else ans+=a;
    }
    cout << ans ;
    return 0 ;
}
