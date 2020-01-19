#include<bits/stdc++.h>
using namespace std ;
const int N = 3e5+9 ; 
int main()
{
    ios::sync_with_stdio(false),cin.tie(0);
    int q ;
    cin >> q ;
    while(q--)
    {
        string s ;
        int a,b,x1=0,x2=0,x3=0,x4=0 ; 
        cin >> a >> b ;
        cin >> s ;
        int m = s.size();
        s=s+"X";
        int cnt = 0 ;
        int num4 = 0 ; ///do4 = 0 -> nox4 , do4 = 1 -> havex4 and print YES , do4 = 2 -> havex4 and print No  
        for(int i=0;i<=m;i++)
        {
            if(s[i]=='X')
            {
                if(cnt>0)
                {
                    if(cnt<b)x1++;
                    else if(b<=cnt&&cnt<a)x2++;
                    else if(a<=cnt&&cnt<2*b)x3++;
                    else 
                    {
                        x4++;
                        num4=cnt ; 
                    }
                }
                cnt=0 ;
            }
            else cnt++;
        }
        assert(s.size()==m+1&&s[m]=='X');
        if(x2||x4>1)
        {
            cout << "NO" << '\n' ;
            continue ; 
        }
        else if(num4)
        {
            bool cn = 0 ;
            assert(num4>=2*b);
            assert(x4==1);
            assert(a<=num4);
            for(int i=1;i<=num4-a+1;i++)              
            {
                int lx = i-1 ;
                int ly = num4-(i+a-1);
                if((lx<b||(a<=lx&&lx<2*b))&&(ly<b||(a<=ly&&ly<2*b)))
                {
                    int tmp = x3+(a<=lx&&lx<2*b)+(a<=ly&&ly<2*b);
                    if(tmp%2==0)
                    {
                        cn = 1 ;
                        break; 
                    }
                }
            }
            if(cn==1)cout << "YES" << '\n' ;
            else cout << "NO" << '\n' ;
            continue ;
        }
        else cout << ((x3&1)?"YES":"NO") << '\n' ;
    }
}