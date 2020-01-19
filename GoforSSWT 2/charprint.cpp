#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 3e5+9;
ll bi[N];
char a[N],b[N];
queue<int> pos[256];
void update(int i,int co)
{
    for(;i<N;i+=i&-i)bi[i]+=co;
}
ll getsum(int i)
{
    ll sum=0;
    for(;i;i-=i&-i)sum+=bi[i];
    return sum;
}
main()
{
    int T,i,j,n,m,x ;
    ll ans=0;
    scanf("%d",&T);
    scanf("%s %s",&a,&b);
    n=strlen(a);
    m=strlen(b);
    for(i=0;i<n;i++)
    {
        pos[a[i]].push(i+1);
        update(i+1,1);
    }
    for(i=0;i<m;i++)
    {
        if(pos[b[i]].empty())
        {
            printf("-1");
            return 0;
        }
        else
        {
            x=pos[b[i]].front();
            ans+=getsum(x);
            if(T==1)
            {
                update(x,-1);
            }
            pos[b[i]].pop();
        }
    }
    printf("%lld",ans);


}
