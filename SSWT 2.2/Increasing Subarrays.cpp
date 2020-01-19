#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int N = 1e6+9 ,inf = 1e9+7 ;
deque<int> dq ;
stack<int> st ;
int a[N],nxt[N],sz[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    ll M ;
    cin >> n >> M ;
    for(int i=1;i<=n;i++)cin >> a[i];
    a[n+1]=inf ;
    st.push(n+1);
    for(int i=n;i>=1;i--)
    {
        while(!st.empty()&&a[st.top()]<=a[i])st.pop();
        nxt[i]=st.top();
        st.push(i);
    }
    ll ans = 0 ,sum = 0 ;
    for(int i=n,r=n;i>=1;i--)
    {
        sz[i]=1;
        while(!dq.empty()&&dq.front()!=nxt[i])
        {
            sum+=sz[dq.front()]*(a[i]-a[dq.front()]);
            sz[i]+=sz[dq.front()];
            dq.pop_front();
        }
        dq.push_front(i);
        while(sum>M)
        {
            //printf("a %d \n",i);
            sz[dq.back()]--;
            sum-=a[dq.back()]-a[r];
            if(r==dq.back())dq.pop_back();
            r--;
        }
        ans+=r-i+1;
    }
    cout << ans ;
    return 0 ;
}
