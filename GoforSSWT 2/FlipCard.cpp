#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ;
map<int,int> key ;
map<int,int>::iterator it;
int a[N][2];
int query[N];
int ans[N];
int MAX[N];
int st[N*4];
int bi[N*4];
int keysize;
vector<pair<int,int> > v;
vector<pair<int,int> > ::iterator itv;
void construct(int l,int r,int m)
{
    int mid=l+r >> 1;
    if(l==r)
    {
        st[m]=MAX[l];
        return ;
    }
    construct(l,mid,m*2);
    construct(mid+1,r,m*2+1);
    st[m]=max(st[m*2],st[m*2+1]);
}
int findmax(int l,int r,int x,int y,int m)
{
    int mid=l+r >> 1 ;
    if(r<x||l>y)
    {
        return 0 ;
    }
    if(r<=y&&l>=x)return st[m];
    return max(findmax(l,mid,x,y,m*2),findmax(mid+1,r,x,y,m*2+1));
}
void update(int in,int co)
{
    for(;in>0;in-=in&-in)bi[in]+=co;
}
int findsum(int in)
{
    int x=0;
    for(;in<=keysize;in+=in&-in)x+=bi[in];
    return x;
}
main()
{
    int n,m,i,j,l,r,x,y ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&l,&r);
        a[i][0]=l ;
        a[i][1]=r;
        key[l]++;
        key[r]++;
    }
    for(i=1;i<=m;i++)
    {
        scanf("%d",&x);
        key[x]++;
        query[i]=x;
    }
    keysize=key.size();
    i=1;
    for(it=key.begin();it!=key.end();it++)
    {
       it->second=i++;
    }
    for(i=1;i<=m;i++)
    {
        y=query[i];
        MAX[key[y]]=i;
    }
    construct(1,keysize,1);
    int max1 ;
    for(i=1;i<=n;i++)
    {
        if(a[i][0]==a[i][1])ans[i]=a[i][0];
        else
        {
            x=key[a[i][0]];
            y=key[a[i][1]];
            if(x>y)swap(x,y);
            max1=findmax(1,keysize,x,y-1,1);
            v.push_back({max1,i});
        }
    }
    sort(v.begin(),v.end(),greater<pair<int,int> >());
    itv=v.begin();
    int g ;
    for(i=m;i>=0;i--)
    {
        while(itv->first==i&&itv!=v.end())
        {
            x=a[itv->second][0];
            y=a[itv->second][1];
            if(x>y)swap(x,y);
            g=findsum(key[y]);
            if(i==0)
            {
                ans[itv->second]=a[itv->second][1^(g%2==0)];
            }
            else if(g%2==0)ans[itv->second]=y;
            else ans[itv->second]=x;
            itv++;
        }
        if(i==0)break;
        update(key[query[i]],1);
    }
    for(i=1;i<=n;i++)
    {
        printf("%d\n",ans[i]);
    }
}
