#include<bits/stdc++.h>
using namespace std ;
const int md = 786433,N=1<<18,r=10 ;
int a[N],b[N],c[N],R[N],W[N],res[N],ans[md] ;
void ntt(int *f)
{
    int n=N,i,j,len,w,wn ;
    for(i=0;i<N;i++)if(res[i]>i)swap(f[i],f[res[i]]);
    for(len=2;len<=N;len<<=1)
    {
        for(i=0,wn=W[n/len];i<n;i+=len)
        {
            for(j=0,w=1;j<len/2;j++,w=w*1ll*wn%md)
            {
                int u=f[i+j],v=f[i+j+len/2]*1ll*w %md ;
                f[i+j]=(u+v)%md , f[i+j+len/2]=(md+u-v)%md;
            }
        }
    }
}
main()
{
    int i,j,n,tmp,T ;
    W[0]=R[0]=1;
    for(i=1;i<N;i++)
    {
        R[i]=r*1ll*R[i-1] %md ;
        W[i]=W[i-1]*1000ll%md ;
    }
    for(int len=N>>1;len;len>>=1)
    {
        int i=N/len >> 1 ;
        for(j=0;j<i;j++)res[j+i]=res[j]+len ;
    }
    scanf("%d",&n);
    for(i=0;i<=n;i++)
    {
        scanf("%d",&a[i]);
        b[i]=1ll*a[i]*R[i]%md;
        c[i]=1ll*b[i]*R[i]%md;
    }
    ans[0]=a[0];
    ntt(a),ntt(b),ntt(c);
    for(i=0;i<N;i++)
    {
        tmp=W[i];
        ans[tmp]=a[i];
        tmp=1ll*tmp*r %md ;
        ans[tmp]=b[i];
        tmp=1ll*tmp*r %md;
        ans[tmp]=c[i];
    }
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&tmp);
        printf("%d\n",ans[tmp]);
    }
}
