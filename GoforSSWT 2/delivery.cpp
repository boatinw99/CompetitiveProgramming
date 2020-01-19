#include<bits/stdc++.h>
using namespace std ;
int bits;
const int N = 100009;
int dijk[N*2];
pair<int,int> edge[9];
priority_queue<pair<int,int> > pq ;
void re()
{
    int i ;
    for(i=1;i<7;i++)
    {
        dijk[edge[i].first]=INT_MAX;
        dijk[edge[i].second]=INT_MAX;
    }
}
int finddist(int x,int y)
{
    int sum=0;
    if(x>bits)x-=bits,y-=bits;
    while(x!=y)
    {
        if(x>y)x/=2;
        else y/=2;
        sum++;
    }
    return sum;
}
main()
{
    int k,l,Q,u,v,ans,i,j,x,y,g ;
    scanf("%d %d %d",&k,&l,&Q);
    bits=1<<k;
    for(i=1;i<=l;i++)
    {
        scanf("%d %d",&u,&v);
        edge[i]={u,v};
    }
    while(Q--)
    {
        re();
        scanf("%d %d",&u,&v);
        if(u>v)swap(u,v);
        ans=INT_MAX;
        //if(u<bits&&v<bits)ans=finddist(u,v);
        //else if(u>bits&&v>bits)ans=finddist(u,v);
        pq.push({0,u});
        dijk[u]=0;
        while(!pq.empty())
        {
            x=pq.top().first*-1;
            y=pq.top().second ;
            pq.pop();
            if(dijk[y]==x)
            {
                if(y<bits&&v<bits)
                {
                    ans=min(ans,finddist(y,v)+x);
                }
                else if(y>bits&&v>bits)
                {
                    ans=min(ans,finddist(y,v)+x);
                }
                if(y<bits)
                {
                    for(i=1;i<=l;i++)
                    {
                        g=finddist(y,edge[i].first);
                        if(g+x<dijk[edge[i].second])
                        {
                            dijk[edge[i].second]=g+x+1;
                            pq.push({-g-x-1,edge[i].second});
                        }
                    }
                }
                else
                {
                    for(i=1;i<=l;i++)
                    {
                        g=finddist(y,edge[i].second);
                        if(g+x<dijk[edge[i].first])
                        {
                            dijk[edge[i].first]=g+x+1;
                            pq.push({-g-x-1,edge[i].first});
                        }
                    }
                }

            }
        }
        dijk[u]=INT_MAX;
        dijk[v]=INT_MAX;
        printf("%d\n",ans);
    }

}
