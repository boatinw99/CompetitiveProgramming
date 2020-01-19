#include<bits/stdc++.h>
using namespace std ;
const int N = 109;
vector<pair<int,int> > node;
int dijk[N*2];
priority_queue<pair<int,int> > pq ;
int finddis(int x1,int y1,int x2,int y2)
{
    int disx,disy,disz;
    disx=abs(x2-x1);
    disy=abs(y2-y1);
    disz=abs(disx-disy);
    if(disx>=disy)
    {
        return disx;
    }
    else
    {
        if(disz%2==1)return disy+1;
        else return disy;
    }
}
main()
{
    int n,m,q,i,j,x,y,x1,y1,x2,y2,z ;
    scanf("%d %d",&m,&q);
    node.push_back({-1,-1});
    for(i=1;i<=m;i++)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        node.push_back({x1,y1});
        node.push_back({x2,y2});
    }
    int ans=0;
    while(q--)
    {
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        ans=finddis(x1,y1,x2,y2);
        for(i=1;i<=2*m;i++)
        {
            dijk[i]=finddis(x1,y1,node[i].first,node[i].second);
            pq.push({-dijk[i],i});
        }
        while(!pq.empty())
        {
            x=pq.top().first*-1;
            y=pq.top().second;
            pq.pop();
            //printf("%d %d\n",x,y);
            if(dijk[y]==x)
            {
                ans=min(ans,x+finddis(node[y].first,node[y].second,
                                      x2,y2));
                for(i=1;i<=2*m;i++)
                {
                    j=finddis(node[y].first,node[y].second,
                              node[i].first,node[i].second);
                    if(x+j<dijk[i])
                    {
                        dijk[i]=x+j;
                        pq.push({-dijk[i],i});
                    }
                }
                if(y%2==1)z=y+1;
                else z=y-1;
                if(x+1<dijk[z])
                {
                    dijk[z]=x+1;
                    pq.push({-x-1,z});
                }
            }
            //return 0;
        }
        printf("%d\n",ans);
    }
}
