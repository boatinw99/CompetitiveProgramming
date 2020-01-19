#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 80009 ;
ll dijk[N][9];
bool potion[N];
int power[20];
priority_queue<pair<ll,pair<int,pair<int,int> > > >pq;
vector<pair<int,int> > path[N];
vector<pair<int,int> > ::iterator it ;
main()
{
    int n,m,l,q,i,j,u,v,wi,d,y,town;
    ll x;
    scanf("%d %d %d %d",&n,&m,&l,&q);
    while(m--)
    {
        scanf("%d %d %d",&u,&v,&wi);
        path[u].push_back({v,wi});
    }
    for(i=1;i<=l;i++)
    {
        scanf("%d",&y);
        potion[y]++;
    }
    power[0]=1;
    for(i=1;i<=10;i++)power[i]=power[i-1]*2;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<=q;j++)
        {
            dijk[i][j]=1e18;
        }
    }
    dijk[1][0]=0;
    pq.push({0,{1,{0,0}}});
    while(!pq.empty())
    {
        x=pq.top().first*-1;
        y=pq.top().second.first;
        d=pq.top().second.second.first;
        town=pq.top().second.second.second;
        pq.pop();
        if(y==n)
        {
            printf("%lld",x);
            return 0 ;
        }
        if(dijk[y][d]==x)
        {
            //printf("%lld %d %d -> %lld\n",x,y,d,dijk[y][d]);
            for(it=path[y].begin();it!=path[y].end();it++)
            {
                if(x+it->second/power[d]<dijk[it->first][d])
                {
                    dijk[it->first][d]=x+it->second/power[d];
                    pq.push({-x-it->second/power[d],
                            {it->first,{d,town}}});
                }
                if(potion[y]==1&&d<q&&town!=y)
                {
                    if(x+it->second/power[d+1]<dijk[it->first][d+1])
                    {
                        dijk[it->first][d+1]=x+it->second/power[d+1];
                        pq.push({-x-it->second/power[d+1],
                                {it->first,{d+1,y}}});
                    }
                }
            }
        }
    }
}
