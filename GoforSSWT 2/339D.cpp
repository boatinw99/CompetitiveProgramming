#include<bits/stdc++.h>
using namespace std ;
const int N = (1<<17)+9 ;
int a[N],st[N*4];
void construct(int l,int r,int m,int XorOr)///Or-> 1 , XOR -> 0
{
    int mid=l+r>>1;
    if(l==r)
    {
        st[m]=a[l];
        return ;
    }
    construct(l,mid,m*2,XorOr^1); construct(mid+1,r,m*2+1,XorOr^1);
    if(XorOr==1)
    {
        st[m]=st[m*2]|st[m*2+1];
    }
    else
    {
        st[m]=st[m*2]^st[m*2+1];
    }
}
void update(int l,int r,int x,int y,int m,int XorOr)
{
    int mid=l+r>>1;
    if(r<x||l>x)
    {
        return ;
    }
    if(l==r)
    {
        st[m]=y;
        return ;
    }
    update(l,mid,x,y,m*2,XorOr^1); update(mid+1,r,x,y,m*2+1,XorOr^1);
    if(XorOr==1)
    {
        st[m]=st[m*2]|st[m*2+1];
    }
    else
    {
        st[m]=st[m*2]^st[m*2+1];
    }
}
main()
{
    int i,j,n,q,m,x,y ;
    scanf("%d %d",&q,&m);
    n=1<<q;
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    construct(1,n,1,q%2);
    while(m--)
    {
        scanf("%d %d",&x,&y);
        update(1,n,x,y,1,q%2);
        printf("%d\n",st[1]);
    }

}
