#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1009;
ll a[N];
main()
{
    ll n,i,j,l=-1,r=2e9+7 ;
    ll k,temp,dis,d ;
    scanf("%lld %lld",&n,&k);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    while(l+1<r)
    {
        ll mid=l+r>>1;
        ll amount = 0;
        temp = mid ;
        mid++ ;
        amount=(mid*(mid+1))/2+(mid*(mid-1))/2;
        if(amount>=k)r=temp;
        for(i=2;i<=n;i++)
        {
            dis=a[i]-a[i-1];
            amount+=(mid*(mid+1))/2+(mid*(mid-1))/2;
            if(dis%2==0)
            {
                d=dis/2+1;
                d=mid-d+1;
                if(d>0)
                amount-=(d*(d+1))/2+(d*(d-1))/2;
            }
            else
            {
                d=dis/2;
                d=mid-d-1;
                if(d>0)
                amount-=d*(d+1);
            }
            if(amount>=k)r=temp;
        }
        mid=temp;
        if(amount>=k)
        {
            r=mid;
        }
        else l=mid ;
    }
    printf("%lld",r);
}
