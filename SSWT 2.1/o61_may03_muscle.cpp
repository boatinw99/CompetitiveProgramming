#include<bits/stdc++.h>
using namespace std ;
const int N = 5e5+9 ;
int f[N],n,a[N],ans[N];
void update(int i,int cst)
{
    for(;i;i-=i&-i)f[i]+=cst;
}
int getsum(int i)
{
    int x=0 ;
    for(;i<=n;i+=i&-i)x+=f[i];
    return x ;
}
int find(int x)
{
    int l=1,r=n+1 ;
    while(l+1<r)
    {
        int mid=l+r>>1;
        //printf("aaa %d %d\n",mid,getsum(mid));
        if(getsum(mid)<=x)r=mid;
        else l=mid ;
    }
   // printf("aa %d %d\n",l,r);
    return l ;
}
main()
{
    int i,j ;
    cin >> n ;
    for(i=1;i<=n;i++)
    {
        cin >> a[i] ;
        update(i,1);
    }
    for(i=n;i>=1;i--)
    {
        int ret = find(a[i]);
        ans[i]=ret;
        //return 0 ;
        update(ret,-1);
    }
    for(i=1;i<=n;i++)
    {
        cout << ans[i] << " " ;
    }
}
