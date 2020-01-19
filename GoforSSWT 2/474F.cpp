#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 ;
int a[N];
struct Tree
{
    int gcd,ans;
};
Tree st[N*4];
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)
    {
        st[m]={a[l],1};
        return ;
    }
    construct(l,mid,m*2); construct(mid+1,r,m*2+1);
    if(st[m*2].gcd<st[m*2+1].gcd)
    {
        if(__gcd(st[m*2].gcd,st[m*2+1].gcd)==st[m*2].gcd)
        {
            st[m]=st[m*2];
        }
        else
        {
            st[m]={__gcd(st[m*2].gcd,st[m*2+1].gcd),0};
        }
    }
    else if(st[m*2].gcd>st[m*2+1].gcd)
    {
        if(__gcd(st[m*2].gcd,st[m*2+1].gcd)==st[m*2+1].gcd)
        {
            st[m]=st[m*2+1];
        }
        else
        {
            st[m]={__gcd(st[m*2].gcd,st[m*2+1].gcd),0};
        }
    }
    else
    {
        st[m]={st[m*2].gcd,st[m*2].ans+st[m*2+1].ans};
    }
}
Tree findans(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    if(r<x||l>y)
    {
        return {0,0};
    }
    if(r<=y&&l>=x)
    {
        return st[m];
    }
    Tree st1=findans(l,mid,x,y,m*2),st2=findans(mid+1,r,x,y,m*2+1);
    if(st1.gcd==0)
    {
        return st2;
    }
    if(st2.gcd==0)
    {
        return st1;
    }
    if(st1.gcd<st2.gcd)
    {
        if(__gcd(st1.gcd,st2.gcd)==st1.gcd)
        {
            return st1;
        }
        else
        {
            return {__gcd(st1.gcd,st2.gcd),0};
        }
    }
    else if(st1.gcd>st2.gcd)
    {
        if(__gcd(st1.gcd,st2.gcd)==st2.gcd)
        {
            return st2;
        }
        else
        {
            return {__gcd(st1.gcd,st2.gcd),0};
        }
    }
    else
    {
        return {st1.gcd,st1.ans+st2.ans};
    }
}
main()
{
    int n,i,j,m,l,r ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    construct(1,n,1);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d",&l,&r);
        printf("%d\n",(r-l+1)-findans(1,n,l,r,1).ans);
    }
}
