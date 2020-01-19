#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
#define fi first
#define se second
const ll pb = 98765431 ;
const int N = 1009 ;
map<ll,set<int> > mp ;
vector<string> s ;
vector<ll> hashh[N] ;
ll p[N];
int sz[N];
bool use[N];
void compute(int x)
{
    int n = s[x].size();
    ///hash backward
    hashh[x].clear();
    ll hash = 0 ;
    for(int i=n-1;i>=0;i--)
    {
        hash += s[x][i]*p[n-i];
        hashh[x].push_back(hash);
    }
    reverse(hashh[x].begin(),hashh[x].end());
    for(auto it:hashh[x])mp[it].insert(x);
}
main()
{
    int n,m,T,i,j ;
    cin >> T ;
    p[0]=1;
    for(i=1;i<N;i++)p[i]=p[i-1]*pb;
    for(int t=1;t<=T;t++)
    {
        int ans = 0 ;
        s.clear();
        mp.clear();
        string in ;
        cin >> n ;
        for(i=1;i<=n;i++)
        {
            cin >> in ;
            s.push_back(in);
            compute(i-1);
            sz[i-1]=in.size();
        }
        memset(use,0,sizeof use);
        for(int len=50;len>=1;len--)
        {
            for(i=0;i<n;i++)
            {
                if(sz[i]>=len&&!use[i])
                {
                    ll tmp = hashh[i][sz[i]-len];
                    if(mp[tmp].size()>=2)
                    {
                        int l = i , r = *mp[tmp].rbegin();
                        use[l]++;
                        use[r]++;
                        ans+=2;
                        for(auto it:hashh[l])mp[it].erase(l);
                        for(auto it:hashh[r])mp[it].erase(r);
                        mp[tmp].clear();
                    }
                }
            }
        }
        cout << "Case #" << t << ": "<<  ans << '\n';
    }
}
