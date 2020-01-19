#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+9;
int bi[N*2];
int n;
void update(int in,int co)
{
    for(;in<=n;in+=in&-in)bi[in]+=co;
}
int getval(int in)
{
    int x=0 ;
    for(;in>0;in-=in&-in)x+=bi[in];
    return x;
}
main()
{
    int Q,l,r,x,q,A,K ;
    scanf("%d %d",&n,&Q);
    update(1,10000);
    while(Q--)
    {
        scanf("%d %d %d %d",&A,&K,&x,&q);
        l=A-K;
        r=A+K;
        if(l<1)
        {
            l+=n;
            update(l,-x);
            update(1,-x);
            update(r+1,x);
        }
        else if(r>n)
        {
            r-=n;
            update(1,-x);
            update(r+1,x);
            update(l,-x);
        }
        else
        {
            update(l,-x);
            update(r+1,x);
        }
        while(q--)
        {
            scanf("%d",&A);
            x=getval(A);
            printf("%d ",x<0?0:x);
        }
        printf("\n");
    }
}
