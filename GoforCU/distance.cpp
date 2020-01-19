#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
typedef long long ll ;
pair<int,int> a[N];
int bi[N*5];
void update(int in,int co)
{
    for(;in<=4*N;in+=in&-in)bi[in]+=co;
}
int getsum(int in)
{
    int x = 0;
    for(;in>0;in-=in&-in)x+=bi[in];
    return x;
}
main()
{
    int n,i,j,x,y ;
    ll K ;
    scanf("%d %lld",&n,&K);
    for(i=1;i<=n;i++)
    {
        scanf("%d %d",&x,&y);
        a[i]={x,y};
    }
    sort(a+1,a+1+n);
    int l=-1,r=N;
    int pr=0 ;
    while(l+1<r)
    {
        int mid=(l+r)/2 ;
        ll check = 0;
        for(i=1;i<=n;i++)update(a[i].second,1);
        for(i=1,j=1;i<=n;i++)
        {
            while(a[j].first-a[i].first<=mid&&j<=n)
            {
                update(a[j].second,-1);
                j++;
            }
            check += (j-i-1) ;
            x=getsum(a[i].second+mid);
            y=getsum(a[i].second-mid-1);
            check+=x-y;
        }
        if(check>=K)
        {
            pr=mid ;
            r=mid;
        }
        else l=mid ;
    }
    printf("%d",pr);
}
