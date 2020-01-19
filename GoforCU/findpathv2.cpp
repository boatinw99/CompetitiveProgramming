#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 500009;
ll a[N];
main()
{
    int n,i,j,l,r ;
    int pr=0;
    ll x;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%lld",&a[i]);
    sort(a+1,a+n+1);
    for(i=1;i<=n;i++)if(a[i]==a[i-1])pr--;
    l=1; r=n;
    bool b;
    while(a[n]>1)
    {
        r=n ;
        pr+=r-l+1;
        for(i=n;i>=l;i--)
        {
            b=0;
            x=a[i];
            while(r>i)
            {

            }
            if(b==0)
            {
                a[i]=x/2;
                l=i;
            }
        }

    }
}
