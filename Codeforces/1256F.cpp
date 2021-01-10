#include<bits/stdc++.h>
using namespace std ;
const int M = 256 , N = 2e5+9 ; 
vector<char> u,v ; 
int A[M],B[M];
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ; 
    cin >> T ; 
    while(T--)
    {
        memset(A,0,sizeof A);
        memset(B,0,sizeof B);
        u.clear();
        v.clear();
        int n ; 
        cin >> n ; 
        string s,t ; 
        cin >> s >> t ;
        for(int i=0;i<s.size();i++)
        {
            A[s[i]]++;
            u.emplace_back(s[i]);
        }
        for(int i=0;i<t.size();i++)
        {
            B[t[i]]++;
            v.emplace_back(t[i]);
        }
        bool ed = 0 , dup = 0 ; 
        for(int i='a';i<='z';i++)
        {
            if(A[i]!=B[i])
            {
                ed++;
            }
            if(A[i]>1)dup++;
        }
        if(ed==1)
        {
            cout << "NO" << '\n' ;
            continue ;
        }
        if(dup==1)
        {
            cout << "YES" << '\n' ;
            continue ; 
        }
        int swap = 0 ;
        for(int i=0;i<n;i++)
        {
            //printf("pls");
            char it = u[i] ;
            int ptr = 0 ;
            for(ptr=0;ptr<v.size();ptr++)if(v[ptr]==it)break ;
            swap+=ptr;
            v.erase(v.begin()+ptr);
        }
        cout << (swap&1?"NO":"YES") << '\n' ;
    }
}