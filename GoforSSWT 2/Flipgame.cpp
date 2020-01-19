#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 59 ;
ll a[N];
main()
{
    int n,m,x,i,j ;
    ll mask,bits,temp1,temp2;
    scanf("%d %d",&n,&m);
    mask=1ll*1<<(m-1);
    for(i=1;i<=n;i++)
    {
        for(j=1,bits=mask;j<=m;j++,bits/=2)
        {
            scanf("%d",&x);
            a[i]+=bits*x;
        }
        a[i]=max(a[i],mask*2-1^a[i]);
    }
    ll ans=0;
    for(;mask;mask>>=1)
    {
        temp1=0; temp2=0;
        for(i=1;i<=n;i++)
        {
            temp1+=((a[i]&mask)>0);
            temp2+=((a[i]&mask)==0);
        }
        ans+=1ll*max(temp1,temp2)*mask;
    }
    printf("%lld",ans);
}
