#include<bits/stdc++.h>
using namespace std ;
const int N = 200009;
typedef long long ll ;
struct Tree
{
    int MAX,range ;
    int bl,br ;
};
Tree st[N*6];
int lazy[N*6];
void update(int l,int r,int x,int y,int add,int m)
{
    int mid=l+r >> 1;
    if(lazy[m]!=0)
    {
        st[m].MAX+=lazy[m];
        if(l!=r)
        {
            lazy[m*2]+=lazy[m];
            lazy[m*2+1]+=lazy[m];
        }
        lazy[m]=0;
    }
    if(r<x||l>y)
    {
        return ;
    }
    if(r<=y&&l>=x)
    {
        st[m].MAX+=add;
        if(l!=r)
        {
            lazy[m*2]+=add;
            lazy[m*2+1]+=add;
        }
        return ;
    }
    update(l,mid,x,y,add,m*2);
    update(mid+1,r,x,y,add,m*2+1);
    if(st[m*2].MAX<st[m*2+1].MAX)
    {
        st[m].MAX=st[m*2+1].MAX;
        st[m].range=st[m*2+1].range;
        st[m].bl=st[m*2+1].bl ;
        st[m].br=st[m*2+1].br ;
    }
    else if(st[m*2].MAX>st[m*2+1].MAX)
    {
        st[m].MAX=st[m*2].MAX;
        st[m].range=st[m*2].range ;
        st[m].bl=st[m*2].bl;
        st[m].br=st[m*2].br ;
    }
    else if(st[m*2].MAX==st[m*2+1].MAX)
    {
        st[m].MAX=st[m*2].MAX;
        st[m].range=st[m*2].range+st[m*2+1].range ;
        st[m].bl=st[m*2].bl;
        st[m].br=st[m*2+1].br;
        if(st[m*2].br==st[m*2+1].bl-1)
        {
            st[m].range--;
        }
    }
}
void construct(int l,int r,int m)
{
    int mid=(l+r) >> 1;
    if(l==r)
    {
        st[m].MAX = 0;
        st[m].bl=st[m].br=l;
        st[m].range=1;
        return ;
    }
    construct(l,mid,m*2);
    construct(mid+1,r,m*2+1);
    st[m].MAX=0;
    st[m].bl=l;
    st[m].br=r;
    st[m].range=1;
}
main()
{
    int n,m,i,j,l,r ;
    scanf("%d %d",&n,&m);
    int x,y,X ;
    construct(1,n,1);
    while(m--)
    {
        scanf("%d %d %d",&l,&r,&X);
        update(1,n,l,r,X,1);
        x=st[1].MAX ; y=st[1].range ;
        printf("%d %d\n",x,y);
    }
}
