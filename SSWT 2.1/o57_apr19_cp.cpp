#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 1e5+9 ,mx =1e9 ;
set<int> chk ;
int st[N*4],sa[N],pos[N],tmp[N],gap,n,lcp[N];
char s[N];
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
int findmin(int l,int r,int x,int y,int m)
{
    if(r<x||l>y)return mx ;
    if(l>=x&&r<=y)return st[m];
    return min(findmin(l,mid,x,y,m<<1),findmin(mid+1,r,x,y,m<<1|1));
}
bool cmp(int i,int j)
{
    if(pos[i]!=pos[j])return pos[i]<pos[j];
    i+=gap;
    j+=gap;
    return (i<=n&&j<=n?pos[i]<pos[j]:j>i);
}
void buildSA()
{
    for(gap=1;;gap<<=1)
    {
        sort(sa+1,sa+1+n,cmp);
        tmp[1]=1;
        for(int i=1;i<=n;i++)tmp[i+1]=tmp[i]+cmp(sa[i],sa[i+1]);
        for(int i=1;i<=n;i++)pos[sa[i]]=tmp[i];
        if(tmp[n]==n)return ;
    }
}
void buildLCP()
{
    for(int i=1,k=0;i<=n;i++)if(pos[i]!=n)
    {
        for(int j=sa[pos[i]+1];s[i+k]==s[j+k];k++);
        lcp[pos[i]]=k ;
        if(k)k--;
    }
}
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int m,i,j,type,x ;
    cin >> n >> m ;
    for(i=1;i<=n;i++)cin >> s[i];
    buildSA();
    buildLCP();
    construct(1,n,1);
    chk.insert(pos[1]);
    while(m--)
    {
        cin >> type >> x ;
        if(type==1)
        {
            chk.insert(pos[x]);
        }
        else
        {
            auto it=chk.lower_bound(pos[x]);
            if(*it==pos[x])
            {
                cout << n-x+1 << '\n' ;
                continue ;
            }
            else
            {
                if(it==chk.begin())cout << findmin(1,n,pos[x],*it-1,1) << '\n' ;
                else if(it==chk.end())
                {
                    it--;
                    cout << findmin(1,n,*it,pos[x]-1,1) <<'\n';
                }
                else
                {
                    auto it1=it;
                    it1--;
                    cout << max(findmin(1,n,*it1,pos[x]-1,1),
                                findmin(1,n,pos[x],*it-1,1)) << '\n' ;
                }
            }
        }
    }
}
