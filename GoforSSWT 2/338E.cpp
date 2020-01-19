#include<bits/stdc++.h>
using namespace std ;
const int N =2e5+9 ;
vector<int> key;
vector<int> ::iterator it ;
int a[N],st[N*4],lazy[N*4],len;
void update(int l,int r,int x,int val,int m)
{
    int mid=l+r>>1;
    if(lazy[m])
    {
        st[m]+=lazy[m];
        if(l<r)
        {
            lazy[m*2]+=lazy[m];
            lazy[m*2+1]+=lazy[m];
        }
        lazy[m]=0;
    }
    if(l>x)return ;
    if(r<=x)
    {
        st[m]+=val;
        if(l<r)
        {
            lazy[m*2]+=val;
            lazy[m*2+1]+=val;
        }
        return ;
    }
    update(l,mid,x,val,m*2); update(mid+1,r,x,val,m*2+1);
    st[m]=max(st[m*2],st[m*2+1]);
}
void construct(int l,int r,int m)
{
    int mid=l+r>>1;
    if(l==r)
    {
        st[m]=len-l+1;
        return ;
    }
    construct(l,mid,m*2); construct(mid+1,r,m*2+1);
    st[m]=max(st[m*2],st[m*2+1]);
}
main()
{
    int n,h,x,ans=0,i,j ;
    scanf("%d %d %d",&n,&len,&h);
    for(i=1;i<=len;i++)
    {
        scanf("%d",&x);
        key.push_back(h-x);
    }
    construct(1,len,1);
    sort(key.begin(),key.end());
    for(i=1;i<=len;i++)
    {
        scanf("%d",&a[i]);
        it=upper_bound(key.begin(),key.end(),a[i]);
        it--; j=it-key.begin()+1;
        update(1,len,j,-1,1);
    }
    if(st[1]<=0)ans++;
    for(i=len+1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        it=upper_bound(key.begin(),key.end(),a[i]);
        it--; j=it-key.begin()+1;
        update(1,len,j,-1,1);
        it=upper_bound(key.begin(),key.end(),a[i-len]);
        it--; j=it-key.begin()+1;
        update(1,len,j,1,1);
        if(st[1]<=0)
        {
            ans++;
        }
    }
    printf("%d",ans);
}
