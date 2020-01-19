#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9;
char s[N];
int a[N];
struct T
{
    int l,r,val ;
};
T st[N*4];//l r ans
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)
    {
        if(a[l]==1)
        {
            st[m]={1,0,0};
        }
        else st[m]={0,1,0};
        return ;
    }
    construct(l,mid,m*2); construct(mid+1,r,m*2+1);
    if(st[m*2].l>=st[m*2+1].r)
    {
        st[m]={st[m*2].l-st[m*2+1].r+st[m*2+1].l,
            st[m*2].r,
        st[m*2+1].r+st[m*2].val+st[m*2+1].val};
    }
    else
    {
        st[m]={st[m*2+1].l,st[m*2].r+st[m*2+1].r-st[m*2].l,
        st[m*2].l+st[m*2].val+st[m*2+1].val};
    }
}
T findans(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    if(r<x||l>y)
    {
        return {0,0,0};
    }
    if(l>=x&&r<=y)
    {
        return st[m];
    }
    T st1=findans(l,mid,x,y,m*2),st2=findans(mid+1,r,x,y,m*2+1);
    if(st1.l>=st2.r)
    {
        return {st1.l-st2.r+st2.l,
            st1.r,
        st2.r+st1.val+st2.val};
    }
    else
    {
        return {st2.l,st1.r+st2.r-st1.l,
        st1.l+st1.val+st2.val};
    }
}
main()
{
    int n,i,j,l,r,m ;
    scanf("%s",&s);
    n=strlen(s);
    for(i=1;i<=n;i++)
    {
        a[i]=(s[i-1]=='(')?1:-1;
    }
    scanf("%d",&m);
    construct(1,n,1);
    while(m--)
    {
        scanf("%d %d",&l,&r);
        printf("%d\n",findans(1,n,l,r,1).val*2);
    }
}
