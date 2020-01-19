#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ;
struct Point
{
    int pos,toungue,pr;
};
Point a[N];
pair<int,int> ans[N],query[N];
vector<int> key;
vector<int> ::iterator it;
int st[N*4],lazy[N*4];
bool sortpos(Point P1,Point P2)
{
    return P1.pos<P2.pos;
}
void update(int l,int r,int x,int y,int val,int m)
{
    int mid=l+r>>1;
    if(lazy[m]<INT_MAX)
    {
        st[m]=min(lazy[m],st[m]);
        if(l<r)
        {
            lazy[m*2]=min(lazy[m*2],lazy[m]);
            lazy[m*2]=min(lazy[m*2],lazy[m]);
        }
        lazy[m]=INT_MAX;
    }
    if(r<x||l>y)
    {
        return ;
    }
    if(l>=x&&r<=y)
    {
        st[m]=min(st[m],val);
        if(l<r)
        {
            lazy[m*2]=min(st[m],val);
            lazy[m*2+1]=min(st[m],val);
        }
        return ;
    }
    update(l,mid,x,y,val,m*2); update(mid+1,r,x,y,val,m*2+1);
    st[m]=min(st[m*2],st[m*2+1]);
}
int findmin(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    if(lazy[m]<INT_MAX)
    {
        st[m]=min(lazy[m],st[m]);
        if(l<r)
        {
            lazy[m*2]=min(lazy[m*2],lazy[m]);
            lazy[m*2]=min(lazy[m*2],lazy[m]);
        }
        lazy[m]=INT_MAX;
    }
    if(r<x||l>y)
    {
        return INT_MAX;
    }
    if(l>=x&&r<=y)return st[m];
    return min(findmin(l,mid,x,y,m*2),findmin(mid+1,r,x,y,m*2+1));
}
main()
{
    int n,m,i,j,x,y,k,min1 ;
    scanf("%d %d",&n,&m);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        a[i]={x,y,i};
    }
    sort(a+1,a+1+n,sortpos);
    cout <<'\n';
    for(i=1;i<=m;i++)
    {
        scanf("%d %d",&x,&y);
        query[i]={x,y};
        key.push_back(x);
    }
    for(i=0;i<=4*m;i++)st[i]=lazy[i]=INT_MAX;
    sort(key.begin(),key.end());
    for(i=n;i>0;i--)
    {
        x=a[i].pos; y=a[i].toungue;
        j=lower_bound(key.begin(),key.end(),x)-key.begin()+1;
        k=upper_bound(key.begin(),key.end(),x+y)-key.begin();
        if(j<=k)update(1,m,j,k,i,1);
    }
    ///query[i].pos,tounge,pr;
    for(i=1;i<=m;i++)
    {
        j=lower_bound(key.begin(),key.end(),query[i].first)
        -key.begin()+1;
        min1=findmin(1,m,j,j,1);
        if(min1<INT_MAX)
        {
            printf("%d -> %d\n",i,min1);
            ans[a[min1].pr].first++;
            a[min1].toungue+=query[i].second;
            x=a[min1].pos; y=a[min1].toungue;
            j=lower_bound(key.begin(),key.end(),x)-key.begin()+1;
            k=upper_bound(key.begin(),key.end(),x+y)-key.begin();
            if(j<=k)update(1,m,j,k,min1,1);
        }
    }
    for(i=1;i<=n;i++)
    {
        printf("%d %d\n",ans[i].first);
    }

}
