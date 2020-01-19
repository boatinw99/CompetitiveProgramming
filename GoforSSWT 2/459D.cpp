#include<bits/stdc++.h>
using namespace std ;
const int N = 1e6+9;
int sll[N],slr[N],a[N],bi[N];
vector<int> v;
vector<int>::iterator it ;
map<int,int> key ;
void update(int in,int co)
{
    for(;in<N;in+=in&-in)bi[in]+=co;
}
int sum(int in)
{
    int x=0;
    for(;in;in-=in&-in)x+=bi[in];
    return x;
}
main()
{
    int n,i,j ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)scanf("%d",&a[i]);
    ///Slideleft
    for(i=1;i<=n;i++)
    {
        v.push_back(a[i]);
        key[a[i]]++;
        sll[i]=key[a[i]];
    }
    key.clear();
    for(i=n;i>0;i--)
    {
        key[a[i]]++;
        slr[i]=key[a[i]];
        update(slr[i],1);
    }
    long long ans=0;
    for(i=1;i<=n;i++)
    {
        update(slr[i],-1);
        ans+=sum(sll[i]-1);
    }
    printf("%I64d",ans);

}

