#include<bits/stdc++.h>
using namespace std ;
const int N = 4e6+9 ;
const int H = 1e6+9;
struct Color
{
    bool b;
    int hi,val ;
};
int bi[H],T,size ;
vector<struct Color> v[N];
vector<struct Color>::iterator it;
void update(int r,int val)
{
    int i ;
    for(i=1;i<H;i+=i&-i)
    {
        bi[i]+=val;
    }
    for(i=r+1;i<H;i+=i&-i)
    {
        bi[i]-=val ;
    }
}
int sum(int r)
{
    int x=0,i ;
    for(i=r;i>0;i-=i&-i)
    {
        x+=bi[i];
    }
    return x;
}
main()
{
    int n,i,j,l,r,h,va,wi,x,l1,r1,d1,d2 ;
    long long pr= 0;
    struct Color C;
    scanf("%d %d",&n,&T);
    while(n--)
    {
        scanf("%d %d %d %d",&l,&h,&wi,&va);
        C.hi=h; C.val = va ; C.b=0;
        v[l].push_back(C) ;
        C.b=1;
        v[l+wi].push_back(C) ;
    }
    bool q =0 ;
    int plus =0;
    for(i=1;i<N;i++)
    {
        q=0;
        for(it=v[i].begin();it!=v[i].end();it++)
        {
            q++;
            x=it->val ;
            if(it->b==1)
            x*=-1 ;
            r = it->hi ;
            update(r,x);
        }
        if(q==0)
        {
            pr+=plus;
            continue ;
        }
        l1=0,r1=H-1;
        while(l1+1<r1)
        {
            int mid=(l1+r1)>>1;
            if(sum(mid)<T)
            {
                r1=mid;
            }
            else l1=mid;
        }
        d1=r1;
        l1=0,r1=H-1;
        while(l1+1<r1)
        {
            int mid=l1+r1 >> 1;
            if(sum(mid)<T+1)
            {
                r1=mid ;
            }
            else l1=mid;
        }
        plus=d1-r1;
        pr+=plus;
    }
    printf("%lld",pr);
}
