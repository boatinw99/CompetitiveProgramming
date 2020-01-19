#include<bits/stdc++.h>
using namespace std ;
const int N = 400009;
char s[N];
int qs[N];
int st[N*5];
void construct(int l,int r,int m)
{
    int mid=(l+r)/2;
    if(l==r)
    {
        st[m]=qs[l];
        return ;
    }
    construct(l,mid,m*2);
    construct(mid+1,r,m*2+1);
    st[m]=min(st[m*2],st[m*2+1]);
}
int findmin(int l,int r,int x,int y,int m)
{
    int mid=(l+r)/2;
    if(l>=x&&r<=y)
    {
        return st[m];
    }
    if(r<x||l>y)return 1e6 ;
    return min(findmin(l,mid,x,y,m*2),findmin(mid+1,r,x,y,m*2+1));
}
main()
{
    scanf("%s",s);
    int n=strlen(s);
    int i,j,l,r,m,x,y,z ;
    for(i=0;i<n;i++)s[i+n]=s[i];
    for(i=0;i<n*2;i++)
    {
        qs[i+1]=qs[i]+(s[i]=='('?1:-1);
    }
    construct(1,2*n,1);
    scanf("%d",&m);
    while(m--)
    {
        scanf("%d %d",&l,&r);
        if(l>=r)r+=n;
        x=findmin(1,2*n,l,r,1);
        if(x-qs[l-1]>=0&&qs[r]-qs[l-1]==0)
        {
            printf("yes");
        }
        else printf("no");
        printf("\n");
    }
}
