#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 100010
#define P pair<int,int>
int mod;
int A,B;
ll n,m;
struct mat
{
    ll a[2][2];
};
P has[N];
int head[N],tot,nex[N],stp[N];
void add(P x,int i)
{
    int h=x.first%N;
    has[tot]=x; stp[tot]=i;
    nex[tot]=head[h];
    head[h]=tot++;
}
int find(P x)
{
    int h=x.first%N;
    for(int i=head[h];~i;i=nex[i])
        if(has[i]==x) return stp[i];
    return -1;
}
mat mul(mat x,mat y)
{
    mat res;
    memset(res.a,0,sizeof(res.a));
    for(int i=0;i<2;++i)
        for(int k=0;k<2;++k)
            for(int j=0;j<2;++j)
                res.a[i][j]=(res.a[i][j]+x.a[i][k]*y.a[k][j])%mod;
    return res;
}
mat pow(mat x,ll n)
{
    mat res;
    memset(res.a,0,sizeof(res.a));
    for(int i=0;i<2;++i) res.a[i][i]=1;
    while(n>0)
    {
        if(n&1) res=mul(res,x);
        x=mul(x,x);
        n>>=1;
    }
    return res;
}
P sta[N];
ll solve()
{
    sta[0]=P(B,A);
    for(int i=1;i<m;++i)
    {
        int BB=A,AA=(B-A+mod)%mod;
        A=AA; B=BB;
        //printf("A=%d,B=%d\n",A,B);
        //add(P(B,A),i);
        sta[i]=P(B,A);
    }
    for(int i=m-1;i>=0;--i) add(sta[i],i);
    mat res;
    res.a[0][0]=1; res.a[0][1]=1;
    res.a[1][0]=1; res.a[1][1]=0;
    res=pow(res,m);

    int fn=1,fn1=0;
    for(ll i=0;i<=n;i+=m)
    {
        //printf("fn=%d,fn1=%d\n",fn,fn1);
        int j=find(P(fn,fn1));
        if(j>=0) return i+j;
        int fx=(1LL*res.a[0][0]*fn+1LL*res.a[0][1]*fn1)%mod;
        int fy=(1LL*res.a[1][0]*fn+1LL*res.a[1][1]*fn1)%mod;
        fn=fx; fn1=fy;
    }
    return -1;
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        memset(head,-1,sizeof(head)); tot=0;
        scanf("%d%d%d",&mod,&A,&B);
        n=6LL*mod; m=(ll)ceil(sqrt(n));
        printf("%lld\n",solve());
    }
    return 0;
}
