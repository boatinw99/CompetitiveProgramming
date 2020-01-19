#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e6+9 ;
int hd[N],cntdown=0,cntup=0;
ll f1[N],f2[N],ans1=0,ans2=0; /// f1-> down , f2-> up
int L,n ;
int drc[N]; ///direction down=0,up=1
void update(ll *f,int i,int cst)
{
    for(;i<N;i+=i&-i)f[i]+=cst;
}
ll getsum(ll *f,int i)
{
    ll x=0;
    for(;i;i-=i&-i)x+=f[i];
    return x ;
}
void changehd(int x,int cst)
{
    if(drc[x]==0)
    {
        if(hd[x]>1)ans1-=L-hd[x]+1;
        ans2-=L-hd[x]+1;
        update(f1,1,-L+hd[x]-1);
        update(f1,hd[x],L);
        hd[x]=(hd[x]+cst)%L;
        if(hd[x]==0)hd[x]=L;
        if(hd[x]>1)ans1+=L-hd[x]+1;
        ans2+=L-hd[x]+1;
        update(f1,1,L-hd[x]+1);
        update(f1,hd[x],-L);
    }
    else
    {
        if(hd[x]!=L)ans1-=hd[x]+1;
        else ans1--;
        ans2-=(hd[x]+1)%L;
        update(f2,1,L-hd[x]);
        update(f2,hd[x]+1,-L);
        hd[x]=(hd[x]+cst)%L;
        if(hd[x]==0)hd[x]=L;
        if(hd[x]!=L)ans1+=hd[x]+1;
        else ans1++;
        ans2+=(hd[x]+1)%L;
        update(f2,1,-L+hd[x]);
        update(f2,hd[x]+1,L);
    }
    while(hd[x]<0);
}
void flip(int x)
{
    if(drc[x]==0)
    {
        cntdown--;
        cntup++;
        if(hd[x]>1)ans1-=L-hd[x]+1;
        ans2-=L-hd[x]+1;
        update(f1,1,-L+hd[x]-1);
        update(f1,hd[x],L);
        hd[x]=(hd[x]-2+L)%L;
        if(hd[x]==0)hd[x]=L;
        if(hd[x]!=L)ans1+=hd[x]+1;
        else ans1++;
        ans2+=(hd[x]+1)%L;
        update(f2,1,-L+hd[x]);
        update(f2,hd[x]+1,L);
    }
    else
    {
        cntup--;
        cntdown++;
        if(hd[x]!=L)ans1-=hd[x]+1;
        else ans1--;
        ans2-=(hd[x]+1)%L;
        update(f2,1,L-hd[x]);
        update(f2,hd[x]+1,-L);
        hd[x]=(hd[x]+2)%L;
        if(hd[x]==0)hd[x]=L;
        if(hd[x]>1)ans1+=L-hd[x]+1;
        ans2+=L-hd[x]+1;
        update(f1,1,L-hd[x]+1);
        update(f1,hd[x],-L);
    }
    drc[x]^=1;
}
ll qans(int x)
{
    ll p=getsum(f1,x)+getsum(f2,x) ;
    return p+1ll*cntdown*x+1ll*cntup*(L-x+1);
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int Q,i,j,x,y ;
    char c;
    cin >> n >> L >> Q ;
    ans2=1ll*n*L;
    for(i=0;i<n;i++)hd[i]=1;
    cntdown=n;
    while(Q--)
    {
        cin >> c ;
        if(c=='s')
        {
            cin >> x >> y ;
            changehd(x,y);
        }
        else if(c=='q')
        {
            cin >> x ;
            if(x==0)cout << ans1 << '\n' ;
            else if(x==L)cout << ans2 << '\n' ;
            else cout << qans(x) << '\n' ;
        }
        else
        {
            cin >> x ;
            flip(x);
        }
    }
}
