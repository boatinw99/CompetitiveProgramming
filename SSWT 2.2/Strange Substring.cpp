#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define mid (l+r>>1)
const int N = 2e5+9 ,inf = 1e9+7 ;
int st[N<<2],n,m,l,sa[N],pos[N],lcp[N],tmp[N],gap,R[N];
string a,b,s="" ;
void construct(int l,int r,int m)
{
    if(l==r)
    {
        st[m]=lcp[l];
        return ;
    }
    construct(l,mid,m<<1);
    construct(mid+1,r,m<<1|1);
    st[m]=min(st[m<<1],st[m<<1|1]);
}
int getmin(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return inf ;
    if(l>=x&&r<=y)return st[m];
    return min(getmin(l,mid,x,y,m<<1),getmin(mid+1,r,x,y,m<<1|1));
}
bool cmp(int i,int j)
{
    if(pos[i]!=pos[j])return pos[i]<pos[j];
    i+=gap,j+=gap;
    return (i<=l&&j<=l?pos[i]<pos[j]:i>j);
}
void constructsa()
{
    for(int i=1;i<=l;i++)sa[i]=i,pos[i]=s[i-1];
    for(gap=1;gap<=l;gap<<=1)
    {
        sort(sa+1,sa+1+l,cmp);
        for(int i=1;i<=l;i++)tmp[i]=tmp[i-1]+cmp(sa[i-1],sa[i]);
        for(int i=1;i<=l;i++)pos[sa[i]]=tmp[i];
    }
}
void constructlcp()
{
    for(int i=1,k=0;i<=l;i++)if(pos[i]!=l)
    {
        int j = sa[pos[i]+1];
        while(s[i+k-1]==s[j+k-1])k++;
        lcp[pos[i]]=k;
        if(k)k--;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> a >> b ;
    n=a.size();
    m=b.size();
    char c = 'z'+1;
    s=a+c+b;
    l=s.size();
    s+="#";
    constructsa();
    constructlcp();
    construct(1,l,1);
    for(int i=l,r=l+1;i>=1;i--)
    {
        if(sa[i]>n+1)r=i ;
        R[i]=r;
    }
    ll ans = 0 ;
    for(int i=1;i<=l;i++)
    {
        if(sa[i]<=n)
        {
            int mx = max(lcp[i-1],getmin(1,l,i,R[i]-1,1));
            ans+=n-sa[i]-mx+1;
            //printf("aa %d | %d %d\n",i,mx,ans);
        }
    }
    cout << ans ;
    return 0 ;
}
