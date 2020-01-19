#include<bits/stdc++.h>
using namespace std ;
const int N = 1009;
int pre[N],post[N],n;
map<int,int>pospre,pospost;
void solve(int l1,int r1,int l2,int r2)
{
    int l,r,x,y,q ;
    q=pospost[pre[l1]];
    x=pospost[pre[l1+1]];
    y=pospre[post[q-1]];
    if(l1>r1)return ;
    if(l1==r1)
    {
        printf("%d\n",pre[l1]);
        return ;
    }
    solve(l1+1,y-1,l2,x);
    printf("%d\n",pre[l1]);
    solve(y,r1,x+1,r2-1);
}
main()
{
    int i,j;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%d",&pre[i]);
        pospre[pre[i]]=i;
    }
    for(i=1;i<=n;i++)
    {
        scanf("%d",&post[i]);
        pospost[post[i]]=i;
    }
    solve(1,n,1,n);
}
