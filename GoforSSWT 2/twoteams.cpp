#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
int color[N];
vector<pair<int,int> >path[N];
bool dfs(int in,int mid,int col)
{
    vector<pair<int,int> >::iterator it;
    color[in]=col;
    bool q;
    for(it=path[in].begin();it!=path[in].end();it++)
    {
        if(it->second>mid);
        else if(color[it->first]==0)
        {
            if(col==1)q=dfs(it->first,mid,2);
            else q=dfs(it->first,mid,1);
        }
        else if(color[it->first]==col)
        {
            return 1;
        }
        if(q==1)return q;
    }
    return 0 ;
}
main()
{
    int n,m,i,j,u,v,l,r ;
    bool q;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back({v,i});
        path[v].push_back({u,i});
    }
    l=1; r=m+1;
    while(l+1<r)
    {
        int mid=l+r>>1;
        q=0;
        for(i=1;i<=n;i++)
        {
            if(color[i]==0)
            {
                q=dfs(i,mid,1); ///1 = first;
            }
            if(q==1)break;
        }
        if(q==0)l=mid;
        else r=mid;
        for(i=1;i<=n;i++)color[i]=0;
    }
    printf("%d",l);
}
