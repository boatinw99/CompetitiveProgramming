#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef complex<double> cpx ;
typedef vector<cpx> vc ;
typedef vector<int> vi ;
#define pi 3.14159265356
const int N = 1e5 ;
vc ans(N) ;
vc FFT(vi a,int n)
{
    if(n==1)
    {
        vc tmp ;
        tmp.emplace_back(cpx(1.0*a[0],0.0));
        return tmp ;
    }
    vi v0,v1 ;
    int hf=n/2 ;
    for(int i=0;i<n;i+=2)v0.emplace_back(a[i]),v1.emplace_back(a[i+1]);
    vc y0=FFT(v0,hf),y1=FFT(v1,hf),tmp(n);
    cpx w(1,0),wn(cos(2*pi/n),sin(2*pi/n));
    for(int i=0;i<hf;i++)
    {
        tmp[i]=y0[i]+w*y1[i];
        tmp[i+hf]=y0[i]-w*y1[i];
        w*=wn ;
    }
    return tmp ;
}
vc IFFT(vc a,int n)
{
    if(n==1)return a ;
    vc v0,v1 ;
    int hf=n/2 ;
    for(int i=0;i<n;i+=2)v0.emplace_back(a[i]),v1.emplace_back(a[i+1]);
    vc y0=IFFT(v0,n/2),y1=IFFT(v1,n/2);
    cpx w(1,0),wn(cos(-2*pi/n),sin(-2*pi/n));
    for(int i=0;i<hf;i++)
    {
        a[i]=y0[i]+w*y1[i];
        a[i+hf]=y0[i]-w*y1[i];
        w*=wn ;
    }
    return a ;
}
vc multi(vc a,vc b,int n)
{
    for(int i=0;i<n;i++)ans[i]=a[i]*b[i];
    return ans ;
}
main()
{
    ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    vector<int> A,B ;
    int T,n,i,j,k,tmp,sz  ;
    cin >> T ;
    while(T--)
    {
        cin >> n ; n++ ; k=n*2-1;
        for(i=0;i<n;i++)
        {
            cin >> tmp ;
            A.emplace_back(tmp);
        }
        for(i=0;i<n;i++)
        {
            cin >> tmp ;
            B.emplace_back(tmp) ;
        }
        reverse(A.begin(),A.end()); reverse(B.begin(),B.end());
        for(sz=1;sz<k;sz*=2);
        for(i=n;i<sz;i++)A.emplace_back(0),B.emplace_back(0);
        vc test = FFT(B,sz);
        ans=IFFT(multi(FFT(A,sz),FFT(B,sz),sz),sz);
        for(i=k-1;i>=0;i--)
        {
            cout << (long long) (ans[i].real()/sz+0.5) << " " ;
        }
        cout << '\n' ;
        A.clear();
        B.clear();
    }
}
