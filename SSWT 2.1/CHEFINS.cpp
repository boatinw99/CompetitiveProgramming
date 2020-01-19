#include<bits/stdc++.h>
using namespace std ;
typedef complex<double> cpx ;
typedef vector<cpx> vc ;
typedef vector<int> vi ;
typedef vector<long long> vl ;
const int N =  2e5+9 ;
const double pi = acos(-1) ;
vl coef(1<<20);
vl res(1<<20);
vi bit(1<<20);
void fft(vc &a,int inv)
{
    int n=a.size();
    bit[0]=0;
    for(int len=n>>1;len;len>>=1)
    {
        int i=n/len >> 1 ;
        for(int j=0;j<i;j++)
        {
            bit[j+i]=bit[j]+len ;
            if(bit[j+i]>j+i)swap(a[j+i],a[bit[j+i]]);
        }
    }
    for(int len=2;len<=n;len<<=1)
    {
        double ang = 2*pi/len*inv ;
        cpx wn(cos(ang),sin(ang));
        for(int i=0;i<n;i+=len)
        {
            cpx w(1,0);
            for(int j=0;j<len/2;j++,w*=wn)
            {
                cpx u = a[i+j],v=a[i+j+len/2]*w ;
                a[i+j]=u+v;a[i+j+len/2]=u-v;
            }
        }
    }
    if(inv == -1)for(auto &it:a)it/=n;
}
void multi(int n)
{
    ///coef[0] -> coef[n-1];
    vc fa(coef.begin(),coef.begin()+n);
    n<<=2;
    fa.resize(n);
    fft(fa,1);
    for(int i=0;i<n;i++)fa[i]*=fa[i]*fa[i];
    fft(fa,-1);
    for(int i=0;i<n/2;i++)res[i]=round(fa[i].real());
    for(int i=0;i<n/2;i++)coef[i]=max(coef[i],min(res[i],1ll));
}
main()
{
    int n,K,q,i,j,tmp,fi ;
    scanf("%d %d %d",&n,&K,&q);
    coef[0]=1 ;
    for(i=0;i<K;i++)
    {
        scanf("%d",&tmp);
        coef[tmp]++ ;
    }
    for(i=1;i<N;i<<=1)multi(i);
    while(q--)
    {
        scanf("%d",&fi);
        printf("%s\n",(coef[fi]>0)?"Yes":"No");
    }
}
