#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
#define mid (l+r>>1)
const int N = 1e6+9 ;
int st[N*4];
void update(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return ;
    if(l==r)
    {
        st[m]=cst;
        return ;
    }
    update(l,mid,x,cst,m<<1);
    update(mid+1,r,x,cst,m<<1|1);
    st[m]=max(st[m<<1],st[m<<1|1]);
}
int getmax(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0 ;
    if(l>=x&&r<=y)return st[m];
    return max(getmax(l,mid,x,y,m<<1),getmax(mid+1,r,x,y,m<<1|1));
}
main()
{
    ios::sync_with_stdio(0),cin.tie(0);
    int n,k,x,h,i,j ;
    cin >> n >> k ;
    while(k--)
    {
        cin >> x >> h ;
        x++;
        update(1,n,x,h,1);
        int l=0,r=n+1;
        while(l+1<r)
        {
            if(getmax(1,n,max(x-mid,1),min(x+mid,n),1)<=h)l=mid;
            else r=mid;
        }
        cout << l << '\n' ;
    }
}
