#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<ll,ll> pll ;
#define mid (l+r>>1)
#define fi first
#define se second
const ll pb = 98765431 ;
const int N = 2e5+9 ;
string s ;
int n ;
ll hashr[N],p[N];
ll gethash(int i,int j)
{
    int len = j-i+1;
    if(i==0)return hashr[j];
    return hashr[j]-hashr[i-1]*p[len] ;
}
int getmin(int i,int j,int k)
{
    int len=j-i ;
    int l = max(i-len+1,0)-1,r=i+1;
    while(l+1<r)
    {
        if(gethash(mid,i)==gethash(mid+len,j)
           &&gethash(mid,i)==gethash(mid+2*len,k))r=mid;
        else l=mid;
    }
    return r;
}
int getmax(int i,int j,int k)
{
    int len = j-i;
    int l = i , r = min(i+len-1,n-1)+1 ;
    while(l+1<r)
    {
        //printf("bsearch %d %d %d \n",l,mid,r);
        if(mid+2*len>=n)r=mid;
        else if(gethash(i,mid)==gethash(j,mid+len)
           &&gethash(i,mid)==gethash(k,mid+2*len))l=mid;
        else r=mid;
    }
    return l ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> s ;
    n=s.size();
    s+="#";
    p[0]=1;
    for(int i=1;i<N;i++)p[i]=p[i-1]*pb ;
    hashr[0]=s[0]; ///p^0
    for(int i=1;i<n;i++)hashr[i]=hashr[i-1]*pb+s[i];
    pll ans = {0,0} ;
    for(int len=1;len<=n/3;len++)
    {
        for(int i=0;;i+=len)
        {
            int j = i+len,k=i+2*len;
            if(k>=n)break;
            int pre = getmin(i,j,k);
            int post = getmax(i,j,k)-len+1;
            if(pre<=post)
            {
                ans.se+=post-pre;
                if(post+3*len==n)
                {
                    ans.fi++;
                }
                else if(post+3*len>n)while(1);
                else
                {
                    if(s[post]!=s[post+3*len])ans.fi++;
                    else ans.se++;
                }
            }
        }
    }
    cout << ans.fi << " " << ans.se ; ///interesting (distinct), boring
    return 0 ;
}
