#include<bits/stdc++.h>
using namespace std ;
typedef complex<double> cpx ;
typedef vector<cpx> vc ;
typedef vector<int> vi ;
typedef long long ll ;
const int N = 1e6+9 ;
const double pi =  3.14159265358979323;
int p[N];
ll f[N];
vi tmp(1<<21) ;
void findprime()
{
    p[0]=p[1]=1;
    for(int i=2;i<N;i++)if(!p[i])for(int j=2;j*i<N;j++)p[j*i]++;
}
void fft(vc &a,int inv)
{
    int n=a.size(),bit;
    tmp[0]=0;
    for(int len=n>>1;len;len>>=1)
    {
        int i=n/len >> 1;
        for(int j=0;j<i;j++)
        {
            tmp[j+i]=tmp[j]+len;
            if(tmp[j+i]>j+i)swap(a[j+i],a[tmp[j+i]]);
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
                cpx u=a[i+j],v=a[i+j+len/2]*w;
                a[i+j]=u+v; a[i+j+len/2]=u-v;
            }
        }
    }
    if(inv==-1)for(auto &it :a)it/=n;
}
vector<long long> multi(vi a)
{
    vc fa(a.begin(),a.end());
    int n=1;
    while(n<a.size()+a.size())n<<=1;
    fa.resize(n);
    fft(fa,1);
    for(int i=0;i<n;i++)fa[i]*=fa[i];
    fft(fa,-1);
    vector<ll> ans(n) ;
    for(int i=0;i<n;i++)ans[i]=round(fa[i].real());
    return ans ;
}
int main()
{
    vi coef1;
    int T,n,i,j ;
    scanf("%d",&T);
    findprime();
    for(i=0;i<N;i++)coef1.push_back((p[i]==0)?1:0);
    vector<ll> ans = multi(coef1);
    for(i=0;i<N;i++)
    {
        if(p[i/2]==0)ans[i]++;
        ans[i]/=2;
    }
    while(T--)
    {
        scanf("%d",&n);
        ll fn=ans[n];
        memset(f,0,sizeof f);
        for(i=0;i<n;i++)f[ans[i]]++;
        ll res = 0 ;
        for(i=0;i<n;i++)if(ans[i]<=fn)res+=f[fn-ans[i]];
        if(fn%2==0)res+=f[fn/2];
        printf("%lld\n",res/2);
    }
}
