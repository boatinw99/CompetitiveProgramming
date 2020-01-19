#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e5+9;
ll PBF = 98765431 ;///prime base
ll qs[N];
ll a[N];
ll bi[N];
int dvd[N];
void update(int i,ll co)
{
    for(;i<N;i+=i&-i)bi[i]+=co;
}
ll findsum(int i)
{
    ll sum=0;
    for(;i;i-=i&-i)sum+=bi[i];
    return sum;
}
main()
{
    int n,m,i,T,j,l,r,p1,p2 ;
    ll x;
    scanf("%d %d",&n,&m);
    ///pre process
    a[0]=1;
    for(i=1;i<=n;i++)
    {
        a[i]=a[i-1]*PBF;
        dvd[i]=i;
        update(i,a[i]);
    }
    qs[1]=a[1];
    for(i=2;i<=n;i++)
    {
        qs[i]=qs[i-1]+a[i];
    }
    while(m--)
    {
        scanf("%d %d %d",&T,&l,&r);
        l++; r++;
        p1=dvd[l]; p2=dvd[r];
        if(T==0)
        {
            update(l,-a[p1]);
            update(r,a[p1]);
            update(r,-a[p2]);
            update(l,a[p2]);
            swap(dvd[l],dvd[r]);
        }
        else
        {
            x=findsum(r)-findsum(l-1);
            //printf("aa %lld-> %lld\n",qs[r]-qs[l-1],x);
            if(x==qs[r]-qs[l-1])
            {
                printf("YES\n");
            }
            else printf("NO\n");
        }
    }
}
