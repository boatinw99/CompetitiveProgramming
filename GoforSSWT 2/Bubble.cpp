#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
int pos[N];
int ans[N];
int bi[N*2];
vector<pair<int,int> > v[N] ;
vector<pair<int,int> > ::iterator it ;
int size ;
void update(int in)
{
    for(;in<=size;in+=in&-in)bi[in]++;
}
int getsum(int in)
{
    int x = 0;
    for(in;in>0;in-=in&-in)x+=bi[in] ;
    return x;
}
int findx(int in)
{
    int w=0,j=size/2;
    for(;j;j/=2)
    {
        if(bi[w+j]<in)
        {
            in-=bi[w+j];
            w+=j;
        }
    }
    return w+1;
}
main()
{
    int n,q,i,j,x,y,k,d ;
    scanf("%d %d",&n,&q);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&x);
        pos[x]=i;
    }
    for(size=1;size<=n;size<<=1);
    for(i=1;i<=q;i++)
    {
        scanf("%d %d",&k,&x);
        v[x].push_back({k,i});
    }
    for(i=n;i>0;i--)
    {
        d=getsum(pos[i]);
        for(it=v[i].begin();it!=v[i].end();it++)
        {
            if(it->first<=d)
            {
                ans[it->second]=pos[i]-it->first;
            }
            else if((n-i+1)<=it->first)
            {
                ans[it->second]=i;
            }
            else
            {
                x=findx(it->first);
                ans[it->second]=x-it->first;
            }
        }
        update(pos[i]);
    }
    for(i=1;i<=q;i++)
    {
        printf("%d\n",ans[i]);
    }
}
