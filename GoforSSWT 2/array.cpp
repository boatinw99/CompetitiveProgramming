#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
struct Q
{
    int type,l,r ;
    ll wi ;
};
vector<ll>key,key1;
vector<ll>::iterator it;
const int N = 2e5+9;
const ll MIN = -2000000000000;
Q query[N];
ll st[4*N],lazy[4*N];
ll findsum(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    if(lazy[m]>MIN)
    {
        st[m]=lazy[m]*(key[r+1]-key[l]);
        if(l!=r)
        {
            lazy[m*2]=lazy[m];
            lazy[m*2+1]=lazy[m];
        }
        lazy[m]=MIN;
    }
    if(l>=x&&r<=y)
    {
        return st[m];
    }
    if(r<x||l>y)
    {
        return 0;
    }
    return findsum(l,mid,x,y,m*2)+findsum(mid+1,r,x,y,m*2+1);
}
void update(int l,int r,int x,int y,ll co,int m)
{
    int mid=l+r>>1;
    if(lazy[m]>MIN)
    {
        st[m]=lazy[m]*(key[r+1]-key[l]);
        if(l!=r)
        {
            lazy[m*2]=lazy[m];
            lazy[m*2+1]=lazy[m];
        }
        lazy[m]=MIN;
    }
    if(l>=x&&r<=y)
    {
        st[m]=co*(key[r+1]-key[l]);
        if(l!=r)
        {
            lazy[m*2]=co;
            lazy[m*2+1]=co;
        }
        return ;
    }
    if(r<x||l>y)return ;
    update(l,mid,x,y,co,m*2);
    update(mid+1,r,x,y,co,m*2+1);
    st[m]=st[m*2]+st[m*2+1];
}
main()
{
    int n,m,i,j,T ;
    ll d,x,y;
    scanf("%d %d",&n,&m);
    for(i=1;i<=m;i++)
    {
        scanf("%d",&T);
        scanf("%lld %lld",&x,&y);
        //y--;
        if(T==0)
        {
            scanf("%lld",&d);
            query[i]={T,x,y,d};
        }
        else
        {
            query[i]={T,x,y,0};
        }
        key.push_back(x);
        key.push_back(y);
    }
    for(i=0;i<4*N;i++)
    {
        lazy[i]=MIN;
        st[i]=0;
    }
    sort(key.begin(),key.end());
    key1.push_back(-1);
    key1.push_back(*key.begin());
    for(it=key.begin()+1;it!=key.end();it++)
    {
        if(*it!=*(it-1))key1.push_back(*it);
    }
    key=key1;
    int size=key.size();
    for(i=1;i<=m;i++)
    {
        it=lower_bound(key.begin(),key.end(),query[i].l);
        x=it-key.begin();
        it=lower_bound(key.begin(),key.end(),query[i].r);
        y=it-key.begin()-1;
        if(query[i].type==1)
        {
            printf("%lld\n",findsum(1,size,x,y,1));
        }
        else
        {
            update(1,size,x,y,query[i].wi,1);
        }
    }
}
