#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
typedef long long ll ;
ll sll[N],slr[N];
int bil[N],bir[N],a[N];
vector<int> key ;
vector<int>::iterator it,it1 ;
void updatel(int in,int co)
{
    for(;in;in-=in&-in)
    {
        bil[in]+=co;
    }
}
int findmore(int in)
{
    int x= 0;
    for(;in<N;in+=in&-in)
    {
        x+=bil[in];
    }
    return  x;
}
void updater(int in,int co)
{
    for(;in<N;in+=in&-in)bir[in]+=co;
}
int findless(int in)
{
    int x=0;
    for(;in;in-=in&-in)
    {
        x+=bir[in];
    }
    return x;
}
main()
{
    int n,i,j,x,y,d;
    ll pr=0,k;
    scanf("%d %I64d",&n,&k);
    for(i=1;i<=n;i++)scanf("%d",&a[i]),key.push_back(a[i]);
    sort(key.begin(),key.end());
    for(i=1;i<=n;i++)
    {
        it=lower_bound(key.begin(),key.end(),a[i]);
        j=it-key.begin()+1;
        x=findmore(j+1);
        updatel(j,1);
        sll[i]=x+sll[i-1];
    }
    for(i=n;i>0;i--)
    {
        it=lower_bound(key.begin(),key.end(),a[i]);
        j=it-key.begin()+1;
        x=findless(j-1);
        updater(j,1);
        slr[i]=x+slr[i+1];
    }
    for(i=0;i<N;i++)bil[i]=0;
    ll ans=0;
    for(i=1,j=1;i<n;i++)
    {
        it=lower_bound(key.begin(),key.end(),a[i]);
        d=it-key.begin()+1;
        pr+=findless(d-1);
        updatel(d,1);
        while((sll[i]+slr[j]+pr>k||i==j)&&j<=n)
        {
            it=lower_bound(key.begin(),key.end(),a[j]);
            d=it-key.begin()+1;
            j++;
            pr-=findmore(d+1);
            updater(d,-1);
        }
        ans+=n-j+1;
    }
    printf("%I64d",ans);
}
