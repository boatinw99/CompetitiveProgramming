#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 3e6+9 ;
const ll Pb = 9876431 ;
ll Prime[256];
char a[N],b[N];
main()
{
    int n,m,i,j ;
    ll hashr=0,hash=0;
    scanf("%d %d",&n,&m);
    scanf("%s %s",&a,&b);
    Prime[0]=1;
    for(i=1;i<=250;i++)
    {
        Prime[i]=Prime[i-1]*Pb;
    }
    for(i=0;i<n;i++)
    {
        hashr+=Prime[a[i]];
        hash+=Prime[b[i]];
    }
    int ans=0;
    if(hash==hashr)ans++;
    for(i=n;i<m;i++)
    {
        hash-=Prime[b[i-n]];
        hash+=Prime[b[i]];
        if(hash==hashr)ans++;
    }
    printf("%d",ans);
}
