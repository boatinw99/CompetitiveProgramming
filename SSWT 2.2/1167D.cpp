#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9 ;
stack<int> st ;
int depth[N];
char s[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,cur=0 ;
    cin >> n ;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i] ;
        if(s[i]==')')
        {
            depth[st.top()]=cur;
            depth[i]=cur;
            cur--;
            st.pop();
        }
        else
        {
            cur++;
            st.push(i);
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(depth[i]&1)cout << "0" ;
        else cout << "1";
    }
    return 0 ;
}
