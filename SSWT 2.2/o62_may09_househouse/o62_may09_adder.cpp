#include<bits/stdc++.h>
using namespace std ;
const int M = 500009,inf=2e9;
int idx = 0 ;
vector<int> out ;
int op[M],L[M],R[M];
void add(int l,int r)
{
    L[idx]=l;
    R[idx]=r;
}
void sum(int l,int r)
{
    op[++idx]=1;///or
    add(l,r);
    op[++idx]=0;///and
    add(l,r);
    op[++idx]=2;
    add(idx-1,inf);
    op[++idx]=0;
    add(idx-1,idx-3);
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n,m ;
    cin >> n >> m ;
    int c = 0 ;
    for(int i=0;i<n;i++)
    {
        int a = -i-1 , b = -i-n-1;
        op[++idx]=0;
        add(a,b);
        op[++idx]=0;
        add(a,c);
        op[++idx]=0;
        add(c,b);
        op[++idx]=1;
        add(idx-3,idx-2);
        op[++idx]=1;
        add(idx-1,idx-2);
        int newc = idx ;
        ///findsum
        sum(a,b);
        sum(idx,c);
        out.push_back(idx);
        c=newc;
    }
    out.emplace_back(c);
    cout << idx << '\n' ;
    for(auto it:out)cout << it << " " ;
    cout << '\n' ;
    for(int i=1;i<=idx;i++)
    {
        if(op[i]==0)///and
        {
            cout << "AND " << L[i] << " " << R[i] ;
        }
        else if(op[i]==1)///or
        {
            cout << "OR " << L[i] << " " << R[i] ;
        }
        else
        {
            cout << "NOT " << L[i] ;
        }
        cout << '\n' ;
    }
    return 0 ;
}
