#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii ;
#define mid (l+r>>1)
#define fi first
#define se second
const int N = 5009 ;
string s ;
int n,g,k,len,r ;
void solve1()
{
    int rmn = n , add = 0 ;
    /*
    if(len*2<n)
    {
        for(int i=0;i<len;i++)
        {
            if(s[i]=='x')cout << s[i+len];
            else cout << s[i] ;
        }
        for(int i=len;i<n-len;i++)cout << s[i];
        for(int i=n-len;i<n;i++)
        {
            if(s[i]=='x')cout << s[i+len];
            else cout << s[i] ;
        }
        cout << '\n' ;
        return ;
    }*/
    for(int i=0;rmn&&s[i]!='x';i++)
    {
        cout << s[i] ;
        rmn--;
        add++;
    }
    for(int i=n+add;rmn;i++)
    {
        cout << s[i] ;
        rmn--;
    }
    cout << '\n' ;
}
void add(int i,pii &bit)
{
    if(s[i]=='0')bit.fi++;
    else bit.se++;
}
void solve2()
{
    for(int i=0;i<n;i++)
    {
        pii bit = {0,0};
        add(i,bit);
        add(i+n,bit);
        add(i+2*n,bit);
        if(bit.fi>bit.se)cout << '0' ;
        else cout << '1';
    }
    cout << '\n' ;
}
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    cin >> n >> g >> k >> len >> r  ;
    if(g==1)
    {
        if(r==1)
        {
            while(k--)
            {
                cin >> s ;/*
                if(len*2<n)
                {
                    for(int i=0;i<len;i++)cout << s[i] ;
                    cout << s ;
                    for(int i=n-len;i<n;i++)cout << s[i];
                    cout << '\n' ;
                }*/
                cout << s << s << '\n' ;
            }
        }
        else
        {
            while(k--)
            {
                cin >> s;
                solve1();
            }
        }
    }
    else if(g==2)
    {
        if(r==1)
        {
            while(k--)
            {
                cin >> s ;
                cout << s << s << s << '\n' ;
            }
        }
        else
        {
            while(k--)
            {
                cin >> s ;
                solve2();
            }
        }
    }
    else
    {
        if(r==1)
        {
            while(k--)
            {
                cin >> s ;
                cout << s << s << s << '\n' ;
            }
        }
        else
        {
            while(k--)
            {
                cin >> s ;
                int typ = 2 ;
                for(int i=0;i<3*n;i++)
                {
                    if(s[i]=='x')typ=1;
                }
                if(typ==1)solve1();
                else solve2();
            }
        }
    }
    return 0 ;
}
