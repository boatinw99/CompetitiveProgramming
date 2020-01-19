#include<bits/stdc++.h>
using namespace std ;
#define fi first
#define se second
typedef long long ll ;
const ll MAX = 1e18+2 ;
const int N = 109 ;
ll f[N];
int p;
stack<int> st;
ll dp1[N],dp2[N];
main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int i,j,T ;
    ll n ;
    cin >> T ;
    f[0]=0,f[1]=1;
    for(p=2;f[p-1]<MAX;p++)
    {
        f[p]=f[p-1]+f[p-2];
    }
    p--;
    f[1]=0;
    while(T--)
    {
        cin >> n ;
        for(j=p-1;j>=2&&f[j]>n;j--);
        for(j;j>=1;j--)
        {
            if(f[j]<=n)
            {
                st.push(j);
                n-=f[j];
            }
        }
        dp1[st.top()]=1,dp2[st.top()]=0;
        while(st.size()>1)
        {
            int l=st.top();
            st.pop();
            j=st.top();
            int len=j-l;
            dp1[j]=dp1[l]+dp2[l];
            dp2[j]=dp1[l]*(len-1>>1)+dp2[l]*(len>>1);
            //printf("aaa %d %d | %lld %lld\n",l,j,dp1[l],dp2[l]);
        }
       // printf("aa %lld %lld\n",dp1[8],dp2[8]);
        cout << dp1[st.top()]+dp2[st.top()] << '\n' ;
        st.pop();
        memset(dp1,0,sizeof dp1);
        memset(dp2,0,sizeof dp2);
    }
}
