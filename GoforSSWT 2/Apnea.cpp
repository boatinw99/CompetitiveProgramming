#include<bits/stdc++.h>
using namespace std ;
const int N = 3e5+9 ;
long long a[N];
vector<int> v;
vector<int>::iterator it ;
main()
{
    int i,j,n,x ;
    long long pr=0 ;
    long long max1=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
        pr+=a[i];
        max1=max(max1,a[i]);
    }
    long long d=2*max1-pr;
    if(d<0)d=0;
    printf("%lld",pr+d);
}
