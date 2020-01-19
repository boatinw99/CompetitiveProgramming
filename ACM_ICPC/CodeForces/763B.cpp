#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int n ;
    cin >> n ;
    cout << "YES" << '\n' ;
    for(int i=1;i<=n;i++)
    {
        int x1,y1,x2,y2 ; 
        cin >> x1 >> y1 >> x2 >> y2 ; 
        if(x1&1&&y1&1)cout << "1" << '\n' ;
        else if((x1&1)==0&&y1&1)cout << "2" << '\n' ;
        else if(x1&1&&(y1&1)==0)cout << "3" << '\n' ;
        else cout << "4" << '\n' ;
    }
    return 0 ; 
}