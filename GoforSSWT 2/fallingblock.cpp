#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+ 9 ;
int bi[N],biup[N],bidown[N];
void updatehi(int in,int co)
{
    for(;in<N;in+=in&-in)bi[in]+=co;
}
int findhi(int in)
{
    int x=0;
    for(;in;in-=in&-in)x+=bi[in];
    return x;
}
void updateup(int in,int co)
{
    for(;in<N;in+=in&-in)biup[in]+=co;
}
int findup(int in)
{
    int x=0;
    for(;in;in-=in&-in)x+=biup[in];
    return x;
}
void updatedown(int in,int co)
{
    for(;in<N;in+=in&-in)bidown[in]+=co;
}
int finddown(int in)
{
    int x=0;
    for(;in;in-=in&-in)x+=bidown[in];
    return x;
}
main()
{
    int n,Q,i,j,l,r,x,y,pre,post,T ;
    scanf("%d %d",&n,&Q);
    while(Q--)
    {
        scanf("%d %d %d",&T,&l,&r);
        if(T==1)
        {
            updatehi(l,1);
            updatehi(r+1,-1);
            x=findhi(l); pre=findhi(l-1);
            if(pre+1==x)updateup(l,1);
            else if(pre==x)updatedown(l-1,-1);
            x=findhi(r); post=findhi(r+1);
            if(post+1==x)updatedown(r,1);
            else if(post==x)updateup(r+1,-1);
        }
        else if(T==2)
        {
            printf("%d %d\n",findhi(l),findhi(r));
        }
        else
        {
            printf("%d %d ",findhi(l),findhi(r));
            printf("%d ",findup(r)-findup(l));
            printf("%d\n",finddown(r-1)-finddown(l-1));
        }
    }
}
