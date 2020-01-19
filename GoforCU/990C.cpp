#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
ll a[600009];
string s;
stack<char> st;
const int N=300001;
int query(string s)
{
    int i,x=0 ;
    for(i=0;i<s.size();i++)
    {
        if(st.empty())st.push(s[i]);
        else if(s[i]==')'&&st.top()=='(')
        {
            st.pop();
        }
        else st.push(s[i]);
    }
    if(st.empty())return 0;
    while(!st.empty())
    {
        if(st.top()=='(')
        {
            x++;
        }
        else if(st.top()==')'&&x>0)return 1e9;
        else x--;
        st.pop();
    }
    return x;
}
main()
{
    int n,i,j,x ;
    scanf("%d ",&n);
    while(n--)
    {
        cin >> s;
        while(!st.empty())st.pop();
        x=query(s);
        if(x>1e6);
        else a[x+N]++;
    }
    ll pr=a[N]*a[N];
    for(i=N+1;i<=600000;i++)
    {
        pr+=a[i]*a[N-(i-N)];
    }
    printf("%I64d",pr);
}
