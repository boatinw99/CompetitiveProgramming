#include<bits/stdc++.h>
using namespace std ;
const int N = 509 ;
vector<pair<int,pair<int,int> > > q ;
vector<pair<int,pair<int,int> > > :: iterator itq;
vector<pair<int,int> > v[N];
vector<pair<int,int> > ::iterator it ;
priority_queue<pair<int,int> > pq;
int town[N];
main()
{
    int n,m,x,y,l,r,val,i,j ;
    scanf("%d %d",&n,&m);
    while(m--)
    {
        scanf("%d %d %d",&l,&r,&val);
        v[l].push_back({r,val});
        v[r].push_back({l,val});
        q.push_back({l,{r,val}});
    }
    int min1=INT_MAX ;
    for(itq=q.begin();itq!=q.end();itq++)
    {
        l=itq->first ; r=itq->second.first;
        pq.push({0,l});
        for(i=0;i<n;i++)town[i]=1e9 ;
        town[l]=0;
        while(!pq.empty())
        {
            x=pq.top().first*-1;
            y=pq.top().second ;
            pq.pop();
            if(town[y]==x)
            {
                for(it=v[y].begin();it!=v[y].end();it++)
                {
                    if((y==l&&it->first==r)||(y==it->first&&it->first==l))continue;
                    if(it->second+x<town[it->first])
                    {
                        town[it->first]=it->second+x;
                        pq.push({-x-it->second,it->first});
                    }
                }
            }
        }
        min1=min(min1,town[r]+itq->second.second);
    }
    printf("%d",min1);
}


