#include "recoverlib.h"
#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 3009 ,LOG=log2(N)+1;
int prime[N] ;
int dp[N][N],n;
int ans[N],L[N*LOG*10],R[N*LOG*10],st[N*LOG*10],root[N],pos[N],id=1,mem;
///Persistent segment tree sum -> find distinct number
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=0 ;
        return ;
    }
    L[m]=++id,R[m]=++id ;
    construct(l,mid,L[m]),construct(mid+1,r,R[m]);
}
int update(int l,int r,int x,int cst,int m)
{
    if(r<x||l>x)return m ;
    int tmp = ++id ;
    if(l==r)
    {
        st[tmp]=st[m]+cst ;
        return tmp ;
    }
    L[tmp]=update(l,mid,x,cst,L[m]);
    R[tmp]=update(mid+1,r,x,cst,R[m]);
    st[tmp]=st[L[tmp]]+st[R[tmp]] ;
    return tmp ;
}
int getsum(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return 0;
    if(l>=x&&r<=y)return st[m];
    return getsum(l,mid,x,y,L[m])+getsum(mid+1,r,x,y,R[m]);
}
void precom(int x)
{
    memset(pos,0,sizeof pos);
    memset(st,0,sizeof st);
    id=mem;
    for(int i=1;i<=n;i++)
    {
        root[i]=root[i-1];
        if(dp[x][i]&&pos[dp[x][i]])
        {
           // printf("del %d %d %d\n",x,i,pos[dp[x][i]]);
            root[i]=update(1,n,pos[dp[x][i]],-1,root[i]);
        }
        if(dp[x][i])
        {
            root[i]=update(1,n,i,1,root[i]);
        }
        pos[dp[x][i]]=i;
    }
}
int query(int x,int y,int num)
{
    return recover_query(x,y,num)-getsum(1,n,x,y,root[y]);
}
int findans(int x,int num)
{
    for(int i=2;i<55;i++)
    {
        if(prime[i]==i)
        {
            if(query(x,x,i))return i ;
            if(num%i==0)return i ;
        }
    }
}
void changeval(int x,int val)
{
    for(int j=val;j>1;j--)
    {
        if(val%j==0)
        {
            dp[j][x]=val;
        }
    }
}
void walk(int l,int r,int num)
{
    if(l==r)
    {
        int ret = findans(l,num);
        ans[l]=ret*num ;
        changeval(l,ans[l]);
        return ;
    }
    int pl = query(l,mid,num);
    int pr = query(mid+1,r,num);
    if(pl)walk(l,mid,num);
    if(pr)walk(mid+1,r,num);
}
void seive()
{
    for(int i=2;i<N;i++)
    {
        if(prime[i]==0)
        {
            for(int j=i;j<N;j+=i)if(prime[j]==0)prime[j]=i ;
        }
    }
}
main()
{
    int i,j ;
    n = recover_init();
    seive();
    root[0]=1;
    construct(1,n,1);
    mem=id ;
    for(i=1;i<=n;i++)ans[i]=1;
    for(i=1500;i>1;i--)
    {
        precom(i);
        if(query(1,n,i))walk(1,n,i);
    }
    recover_answer(ans);
    //for(i=1;i<=n;i++)cout << ans[i] << " " ;
}
