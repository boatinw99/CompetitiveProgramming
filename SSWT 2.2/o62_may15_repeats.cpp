#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const ll pb = 98765431 ;
const int N = 1009 ;
string s ;
int n,k;
ll hashl[N],pows[N];
ll gethash(int i,int j)
{
    int len = j-i+1;
    return hashl[j]-hashl[i-1]*pows[len];
}
int nextpos(int i,int j,int x,int y)
{
    int l = i,r=j+1;
    if(s[l]!=s[x])return i+1;
    while(l+1<r)
    {
        int mid = l+r>>1 ;
        int len = mid-i+1;
        if(gethash(i,i+len-1)==gethash(x,x+len-1))l=mid;
        else r=mid ;
    }
    return l+2;
}
int query(int l,int r,int x,int y)
{
    if(y>n)return 0 ;
    int cnt = 0 ,len = r-l+1 ;
    if(n<=200)
    {
        for(int i=0;i<len;i++)
        {
            if(s[i+l]!=s[x+i])cnt++;
        }
    }
    else
    {
        if(k==0)return gethash(l,r)==gethash(x,y);
        int idx = l,idx1=x;
        while(idx<=r)
        {
            int len1 = idx ;
            idx=nextpos(idx,r,idx1,y);
            len1=idx-len1;
            idx1+=len1 ;
            cnt++;
            if(idx==r+2)cnt--;
            if(cnt>k)return 0 ;
        }
    }
    return cnt<=k ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    ll ans=0 ;
    cin >> k ;
    cin >> s ;
    n=s.size();
    s="0"+s;
    pows[0]=1;
    for(int i=1;i<N;i++)pows[i]=pows[i-1]*pb;
    for(int i=1;i<=n;i++)hashl[i]=hashl[i-1]*pb+s[i];
    for(int i=1;i<=n;i++)
    {
        for(int j=i;j<=n;j++)
        {
            int len=j-i+1;
            ans+=query(i,j,j+1,j+len);
        }
    }
    cout << ans ;
    return 0 ;
}
