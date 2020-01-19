/**
 *      Author : boatinw99
 *      Date : 3.5.2019 21:41
 */
#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ;
stack<int> st ;
int a[N],L[N],R[N],pos[N],ans=0;
void query(int l,int r,int x,int y,int val)
{
    for(int i=l;i<=r;i++)
    {
        if(a[i]<val&&x<=pos[val-a[i]]&&pos[val-a[i]]<=y)ans++;
    }
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        pos[a[i]]=i ;
    }
    ///compute L
    a[0]=n+1;
    a[n+1]=n+1;
    st.push(0);
    for(int i=1;i<=n;i++)
    {
        while(a[st.top()]<a[i])st.pop();
        L[i]=st.top();
        st.push(i);
    }
    while(!st.empty())st.pop();
    st.push(n+1);
    for(int i=n;i>=1;i--)
    {
        while(a[st.top()]<a[i])st.pop();
        R[i]=st.top();
        st.push(i);
    }
    for(int i=1;i<=n;i++)
    {
        int lenL = i-L[i];
        int lenR = R[i]-i;
        if(lenL<=lenR)query(L[i]+1,i-1,i+1,R[i]-1,a[i]);
        else query(i+1,R[i]-1,L[i]+1,i-1,a[i]);
    }
    cout << ans ;
    return 0 ;
}
