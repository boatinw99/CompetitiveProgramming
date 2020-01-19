#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+9;
int a[N];
bool b[N];
pair<int,int> st[N*4];
set<int> s;
set<int>::iterator its;
vector<pair<int,int> > v;
vector<pair<int,int> > ::iterator it;
void construct(int l,int r,int m)
{
    int mid=l+r>>1 ;
    if(l==r)
    {
        st[m]={a[l],l};
        return ;
    }
    construct(l,mid,m*2); construct(mid+1,r,m*2+1);
    if(st[m*2].first<=st[m*2+1].first)
    {
        st[m]=st[m*2+1];
    }
    else
    {
        st[m]=st[m*2];
    }
}
pair<int,int> findmax(int l,int r,int x,int y,int m)
{
    int mid=l+r>>1;
    if(r<x||l>y)return {-1,1};
    if(l>=x&&r<=y)
    {
        return st[m];
    }
    pair<int,int> q1,q2;
    q1=findmax(l,mid,x,y,m*2); q2=findmax(mid+1,r,x,y,m*2+1);
    if(q1.first<=q2.first)
    {
        return q2;
    }
    else
    {
        return q1;
    }
}
main()
{
    int n,i,j,x,y,k,max1=1,l,r ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]),v.push_back({a[i],i});
    construct(1,n,1);
    sort(v.begin(),v.end());
    for(it=v.begin();it!=v.end();it++)
    {
        x=it->first; y=it->second ;
        if(b[y]==1)continue ;
        if(b[y+1]==1||y==n);
        else if(b[y+2]==1)
        {
            max1=max(max1,2);
            b[y+1]++;
        }
        else if(b[y]==0)
        {
           its=s.lower_bound(y);
           if(its==s.end())
           {
               r=n;
           }
           else r=*its-1;
           if(r-y+1<=max1)
           {
               for(k=y+1;k<=r;k++)b[k]++;
           }
           else
           {
                j=findmax(1,n,y,r,1).second;
                max1=max(max1,j-y+1);
                for(k=y+1;k<=j;k++)b[k]++;
           }
        }
        b[y]++;
        s.insert(y);
    }
    printf("%d",(max1==1)?-1:max1);
}
