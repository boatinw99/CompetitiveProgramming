#include<bits/stdc++.h>
using namespace std ;
const int N = 30009;
vector<int> path[N];
int euler[N*4],depth[N*4],p=1;
int pos[N];
int st[N*8];
void dfs(int u,int v,int hi)
{
    vector<int>::iterator it ;
    pos[u]=p;
    depth[p]=hi;
    euler[p++]=u;
    for(it=path[u].begin();it!=path[u].end();it++)
    {
        if(*it!=v)
        {
            dfs(*it,u,hi+1);
            depth[p]=hi;
            euler[p++]=u;
        }
    }
}
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)
    {
        st[m]=depth[l];
        return ;
    }
    construct(l,mid,m*2);
    construct(mid+1,r,m*2+1);
    st[m]=min(st[m*2],st[m*2+1]);
    //printf("[%d %d] -> %d\n",l,r,st[m]);
}
int findmin(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    if(l>=x&&r<=y)
    {
        return st[m];
    }
    if(r<x||l>y)return INT_MAX;
    return min(findmin(l,mid,x,y,m*2),findmin(mid+1,r,x,y,m*2+1));
}
main()
{
    int n,i,j,m,y,x,u,v,h,par1,par2 ;
    scanf("%d",&n);
    for(i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        path[u].push_back(v);
        path[v].push_back(u);
    }
    dfs(1,1,1);
    x=1;
    scanf("%d",&m);
    int ans=0,temp1,temp2;
    construct(1,p-1,1);
    while(m--)
    {
        scanf("%d",&y);
        par1=pos[x]; par2=pos[y];
        if(par1>par2)swap(par1,par2);
        h=findmin(1,p-1,par1,par2,1);
        //printf("%d(%d) %d(%d) ->%d\n",x,par1,y,par2,h);
        ans+=(depth[par1]-h)+(depth[par2]-h);
        swap(x,y);
    }
    printf("%d",ans);
}
