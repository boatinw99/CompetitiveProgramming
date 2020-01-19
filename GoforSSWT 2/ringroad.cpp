#include<bits/stdc++.h>
using namespace std;
const int N = 2e5+9;
int par[N],val[N],pathcycle[N];
int bi[N];
vector<pair<int,int> >path[N];
void dfs(int u,int parent,int ti)
{
    vector<pair<int,int> >::iterator it ;
    par[u]=parent; val[u]=ti;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(par[it->first]!=parent)
        dfs(it->first,parent,ti+it->second);
    }
}
void update(int i,int co)
{
    for(;i<N;i+=i&-i)bi[i]+=co;
}
int sum(int i)
{
    int sum=0;
    for(;i;i-=i&-i)sum+=bi[i];
    return sum ;
}
main()
{
    int n,k,Q,i,j,x,y,u,v,wi,l,r,T,all=0;
    scanf("%d %d %d",&n,&k,&Q);
    for(i=1;i<=k;i++)
    {
        scanf("%d",&wi);
        all+=wi;
        pathcycle[i]=wi;
        update(i+1,wi);
    }
    for(i=k+1;i<=n;i++)
    {
        scanf("%d %d",&v,&wi);
        path[i].push_back({v,wi});
        path[v].push_back({i,wi});
    }
    for(i=1;i<=k;i++)
    {
        dfs(i,i,0);
    }
    int ans,dif;
    while(Q--)
    {
        scanf("%d %d %d",&T,&l,&r);
        if(T==0)
        {
            dif=r-pathcycle[l];
            pathcycle[l]=r;
            all+=dif;
            update(l+1,dif);
        }
        else
        {
            if(par[l]==par[r])
            {
                printf("%d\n",abs(val[l]-val[r]));
            }
            else
            {
                ans=val[l]+val[r];
                l=par[l]; r=par[r];
                if(l>r)swap(l,r);
                x=sum(r)-sum(l);
                ans+=min(x,all-x);
                printf("%d\n",ans);
            }
        }
    }
}
