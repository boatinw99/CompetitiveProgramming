#include<bits/stdc++.h>
using namespace std ;
string s ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int T ;
    cin >> T ;
    while(T--)
    {
        int n ;
        cin >> n ;
        cin >> s ;
        bool ans = 0 ;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='8'&&n-i>=11)
            {
                ans++;
                break;
            }
        }
        cout << (ans==1?"YES":"NO") << '\n' ;
    }
    return 0 ;
}
