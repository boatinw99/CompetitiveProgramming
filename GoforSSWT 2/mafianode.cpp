#include<bits/stdc++.h>
using namespace std;
const int N = 1e6+9 ;
bool b[N];
pair<int,int> st[N*4]; //MAX,index
void update(int l,int r,int x,int y,int m)
{
    int mid=l+r >> 1;
    if(l>x||r<x)
    {
        return ;
    }
    if(l==r)
    {
        st[m].first += y;
        st[m].second = l ;
        return ;
    }
    update(l,mid,x,y,m*2); update(mid+1,r,x,y,m*2+1);
    if(st[m*2].first>st[m*2+1].first)
    {
        st[m]=st[m*2];
    }
    else if(st[m*2].first<st[m*2+1].first)
    {
        st[m]=st[m*2+1];
    }
    else
    {
        st[m].first=st[m*2].first;
        st[m].second = max(st[m*2].second,st[m*2+1].second);
    }
}
void construct(int l,int r,int m)
{
    int mid= l+r>>1;
    if(l==r)
    {
        st[m].first = 0;
        st[m].second = l;
        return ;
    }
    construct(l,mid,m*2); construct(mid+1,r,m*2+1);
    st[m].first = 0 ; st[m].second=st[m*2+1].second;
}
main()
{
    int n,m,k,i,j,x,y,l,r,val ;
    scanf("%d %d %d",&n,&m,&k);
    int IN=m+k;
    char c ;
    construct(1,n,1);
    while(IN--)
    {
        scanf(" %c",&c);
        if(c=='L'||c=='C')
        {
            val=(c=='L')?1:3;
            scanf("%d %d",&l,&r);
            if(b[l]==1||b[r]==1)continue;
            update(1,n,r,val,1);
        }
        else if(c=='R')
        {
            printf("%d\n",st[1].second);
        }
        else
        {
            b[st[1].second]++;
            update(1,n,st[1].second,INT_MIN,1);
        }

    }
}
