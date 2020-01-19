#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 1e5+9 ;
stack<int> st ;
vector<pair<int,pii> > v ;
int par[N],out[N],L[N],a[N];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T,n,m,i,j,x ;
    cin >> T ;
    for(int t=1;t<=T;t++)
    {
        cin >> n ;
        v.clear();
        memset(a,0,sizeof a);
        memset(par,0,sizeof par);
        memset(out,0,sizeof out);
        memset(L,0,sizeof L);
        while(!st.empty())st.pop();
        st.push(0);
        for(i=1;i<=n;i++)
        {
            cin >> a[i] ;
            if(a[i]<0)
            {
                par[i]=st.top();
                v.push_back({a[i],{par[i],i}});
                st.push(i);
            }
            else
            {
                L[i]=st.top();
                out[st.top()]=i;
                st.pop();
            }
        }
        st.pop();
        sort(v.begin(),v.end());
        cin >> m ;
        cout << "Case " << t << ":" << '\n' ;
        while(m--)
        {
            cin >> x ;
            int tmp = -a[x],y=par[L[x]];
            auto it = lower_bound(v.begin(),v.end()
                        ,make_pair(tmp,make_pair(y,x)));
            if(it!=v.end()&&it->fi==tmp&&it->se.fi==y)
                cout << "yes" << '\n';
            else cout << "no" << '\n';
        }
    }
}
