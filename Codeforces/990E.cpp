#include<bits/stdc++.h>
using namespace std ;
const int N =1e6+9;
typedef long long ll;
int a[N];
bool vis[N];
main()
{
    int n,m,k,i,j,max1=0 ;
    ll x;
    ll co,maxr=1e18;
    scanf("%d %d %d",&n,&m,&k);
    while(m--)
    {
        scanf("%I64d",&x);
        vis[x]++;
    }
    if(vis[0])
    {
        printf("-1");
        return 0;
    }
    for(i=0;i<n;i++)
    {
        if(vis[i])
        {
            a[i]=a[i-1];
        }
        else a[i]=i;
    }
    for(i=0;i<n;i++)max1=max(max1,i-a[i]);
    if(max1>=k)
    {
        printf("-1");
        return 0;
    }
    for(i=1;i<=k;i++)
    {
        scanf("%I64d",&x);
        if(i>max1)
        {
            co=0;
            for(j=0;j<n;j+=i)
            {
                if(vis[j])j=a[j];
                co+=x;
            }
            maxr=min(maxr,co);
        }
    }
    printf("%I64d",maxr);
}
