#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9;
typedef long long ll ;
vector<ll> key,qkey;
vector<ll> ::iterator it ;
pair<ll,ll> Q[N];
pair<ll,ll> a[N];
ll bi[N];
void update(int in)
{
    for(;in;in-=in&-in)bi[in]++;
}
ll findmore(int in)
{
    ll x =0 ;
    for(;in<N;in+=in&-in)x+=bi[in];
    return x ;
}
main()
{
    int n,i,j,l,r,k ;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        scanf("%I64d %I64d",&Q[i].first,&Q[i].second);
        key.push_back(Q[i].first);
        key.push_back(Q[i].second);
    }
    int size ;
    sort(key.begin(),key.end());
    qkey.push_back(key[0]);
    for(it=key.begin()+1;it!=key.end();it++)
        if(*it!=*(it-1))qkey.push_back(*it);
    key=qkey;
    size=key.size();
    for(i=0;i<size;i++)a[i+1]={key[i],key[i]};
    for(i=1;i<=n;i++)
    {
        j=lower_bound(key.begin(),key.end(),Q[i].first)-key.begin()+1;
        k=lower_bound(key.begin(),key.end(),Q[i].second)-key.begin()+1;
        swap(a[j].first,a[k].first);
    }
    ll ans=0;
    for(i=1;i<=size;i++)
    {
        j=lower_bound(key.begin(),key.end(),a[i].first)-key.begin()+1;
        k=lower_bound(key.begin(),key.end(),a[i].second)-key.begin()+1;
        l=j; r=k;
        if(l>r)swap(l,r);
        ans+=abs(a[i].first-a[i].second)-(r-l);
        //printf(" %d\n",a[i].first-a[i].second);
        ans+=findmore(j+1);
        update(j);
    }
    printf("%I64d",ans);
}
