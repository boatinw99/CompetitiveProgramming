#include<bits/stdc++.h>
using namespace std ;
vector<string> V ;
const int N = 1e6+9 ;
void print(int x)
{
    string s = V[x];
    int m = s.size();
    for(int i=0;i<m;i++)
    {
        if(s[i]=='_')cout << " " ;
        else cout << s[i] ;
    }
}
int main()
{
    srand(time(0));
    string s;
    while(1)
    {
        cin >> s ;
        if(s[0]=='0')break;
        V.emplace_back(s);
    }
    int n = V.size();
    cout << "ALL WORD = " << n << '\n' ;
    random_shuffle(V.begin(),V.end());
    int ptr = 0 ;
    while(n--)
    {
        int x ;
        cin >> s ;
        cout <<  "Vocabulary remainders = " << n << " ----> " ; 
        cout << "What does / " ;
        print(ptr);
        ptr++;
        cout << " \\ mean ? " << '\n' ;
    }
    return 0 ;
}
