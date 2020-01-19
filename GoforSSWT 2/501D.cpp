#include<bits/stdc++.h>
using namespace std ;
const int N = 4e5+9 ;
int a[N];
int bi[N];
int ans[N],size;
void update(int in,int co)
{
    for(;in<=size;in+=in&-in)bi[in]+=co;
}
int sum(int in)
{
    int x=0;
    for(;in;in-=in&-in)x+=bi[in];
    return x;
}
int findpos(int in)
{
    int w=0,j=size/2;
    for(;j;j>>=1)
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
    int i,j,n,x ;
    scanf("%d",&n);
    for(size=1;size<n;size*=2);
    for(i=1;i<=n;i++)update(i,1);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        a[i]++;
        j=n-i;
        ans[j]+=sum(a[i])-1;
        update(a[i],-1);
    }
    for(i=1;i<=n;i++)update(i,1);
    for(i=1;i<=n;i++)
    {
        j=n-i;
        scanf("%d",&a[i]);
        a[i]++;
        ans[j]+=sum(a[i])-1;
        update(a[i],-1);
    }
    for(i=1;i<n;i++)
    {
        if(ans[i]>i)
        {
            ans[i+1]++;
            ans[i]-=(i+1);
        }

    }
    for(i=1;i<=n;i++)update(i,1);
    for(i=n-1;i>=0;i--)
    {
        j=ans[i];
        x=findpos(j+1);
        printf("%d ",x-1);
        update(x,-1);
    }
}
