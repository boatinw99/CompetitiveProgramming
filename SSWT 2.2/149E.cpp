#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9 , M = 1009 ;
int pat[M],pre[N],suf[N];
int n,m ;
string s,t,q ;
void preprocess()
{
    for(int i=1,j=0;i<m;)
    {
        if(q[i]==q[j])
        {
            pat[i++]=j+1;
            j++;
        }
        else if(j==0)pat[i++]=0;
        else j=pat[j-1];
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> s ;
    t=s;
    reverse(t.begin(),t.end());
    n=t.size();
    int T,ans=0 ;
    cin >> T ;
    while(T--)
    {
        cin >> q ;
        m=q.size();
        if(m==1)continue ;
        preprocess();
        memset(pre,-1,sizeof pre);
        memset(suf,-1,sizeof suf);
        for(int i=0,j=0;i<n;)
        {
            if(s[i]==q[j])
            {
                if(pre[j]==-1)pre[j]=i;
                i++;
                j++;
            }
            else if(j==0)i++;
            else j=pat[j-1];
        }
        reverse(q.begin(),q.end());
        preprocess();
        for(int i=0,j=0;i<n;)
        {
            if(t[i]==q[j])
            {
                if(suf[j]==-1)suf[j]=i;
                i++;
                j++;
            }
            else if(j==0)i++;
            else j=pat[j-1];
        }
        bool got = 0 ;
        for(int i=0;i<m;i++)
        {
            if(pre[i]<n-suf[m-i-2]-1&&pre[i]>=0&&suf[m-i-2]>=0)
            {
                got++;
                break;
            }
        }
        ans+=got;
    }
    cout << ans ;
}
