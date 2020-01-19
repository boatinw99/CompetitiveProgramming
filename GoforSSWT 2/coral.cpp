#include<bits/stdc++.h>
using namespace std ;
const int N = (1<<20)+9;
struct Tree
{
    int all,x;
};
Tree st[N*4];
void update(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1 ;
    if(l==x&&r==y)
    {
        if(l==r)
        {
            st[m].x=st[m].all=1;
            return ;
        }
        st[m].x=1;
        if(st[m*2+1].all+st[m*2+2].all>=(r-l))
        {
            st[m].all=r-l+1;
        }
        else
        {
            st[m].all=st[m*2+1].all+st[m*2+2].all;
        }
        return ;
    }
    if(r<x||l>y)return ;
    update(l,mid,x,y,m*2+1);
    update(mid+1,r,x,y,m*2+2);
    if(st[m*2+1].all+st[m*2+2].all+st[m].x==(r-l+1))
    {
        st[m].all=(r-l+1);
    }
    else
    {
        st[m].all=st[m*2+1].all+st[m*2+2].all;
    }
    //printf("%d %d -> all=%d all.l=%d all.r=%d\n",
         // l,r,st[m].all,st[m*2+1].all,st[m*2+2].all);
}
main()
{
    int n,m,a,b,i,j,bits;
    scanf("%d %d",&n,&m);
    bits=1<<n;
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&a,&b);
        update(0,bits-1,b,b+(1<<a)-1,0);
        if(st[0].all==bits)
        {
            printf("%d",i);
            return 0;
        }
    }
}
