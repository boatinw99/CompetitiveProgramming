#include<bits/stdc++.h>
using namespace std ;
const int n = (1<<19)-1 ,LOG=log2(n)+1;
int st[n*LOG+n*4],L[n*LOG+n*4],R[n*LOG+n*4],root[n];
int id=1;
void construct(int l,int r,int m)
{
    if(l==r)return ;
    L[m]=++id,R[m]=++id;
    int mid=l+r>>1;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int m)
{
    int tmp=++id,mid=l+r>>1;
    if(l==r)
    {
        st[tmp]=st[m]+1;
        return tmp ;
    }
    L[tmp]=L[m],R[tmp]=R[m];
    if(x<=mid)L[tmp]=update(l,mid,x,L[m]);
    else R[tmp]=update(mid+1,r,x,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]];
    return tmp;
}
int query1(int l,int r,int m1,int m2,int x,int bit)
{
    int tmp=st[L[m2]]-st[L[m1]],mid=l+r>>1;
    if(l==r)return l ;
    if(tmp==0)return query1(mid+1,r,R[m1],R[m2],x,bit>>1);
    else if((x&bit)==0&&tmp!=st[m2]-st[m1])
        return query1(mid+1,r,R[m1],R[m2],x,bit>>1);
    else return query1(l,mid,L[m1],L[m2],x,bit>>1);
}
int query3(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0;
    if(l>=x&&r<=y)return st[m];
    int mid=l+r>>1;
    return query3(l,mid,x,y,L[m])+query3(mid+1,r,x,y,R[m]);
}
int query4(int l,int r,int m1,int m2,int k)
{
    if(l==r)return l ;
    int tmp=st[L[m2]]-st[L[m1]],mid=l+r>>1;
    if(tmp>=k)return query4(l,mid,L[m1],L[m2],k);
    else return query4(mid+1,r,R[m1],R[m2],k-tmp);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,i=1,j,x,l,r,t,k ;
    root[0]=1;
    construct(0,n,1);
    cin >> m ;
    while(m--)
    {
        cin >> t ;
        if(t==0)
        {
            cin >> x ;
            root[i]=update(0,n,x,root[i-1]);
            i++;
        }
        else if(t==1)
        {
            cin >> l >> r >> x ;
            cout << query1(0,n,root[l-1],root[r],x,1<<18) << '\n' ;
        }
        else if(t==2)
        {
            cin >> k ;
            i-=k;
        }
        else if(t==3)
        {
            cin >> l >> r >> x ;
            cout << query3(0,n,0,x,root[r])
            -query3(0,n,0,x,root[l-1]) << '\n';
        }
        else
        {
            cin >> l >> r >> x ;
            cout << query4(0,n,root[l-1],root[r],x) << '\n';
        }
    }
}
