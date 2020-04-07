/*
    waste ten minutes, mislead! 
    8 Case analysis : 1 hour 40 minutes
*/
#include<bits/stdc++.h>
using namespace std ;
void pr(char c) {
    if(c=='s') {
        cout << "Stannis" << '\n';
    }
    else cout << "Daenerys" << '\n' ;
}
int main() {
    int n,k,x=0,y=0 ; 
    cin >> n >> k ; 
    for(int i=1,d ;i<=n;i++) {
        cin >> d ;
        if(d%2) {
            x++;
        }
        else y++;
    }
    n-=k; 
    int turny = n/2 ; 
    int turnx = n-turny ; 
    ///case analysis
    if(turnx+turny==x+y) {
        pr('d');
        return 0 ;
    }
    if(n==0) {
        if(x%2) {
            pr('s');
        }
        else pr('d');
        return 0 ;
    }
    if(turny>=x) {
        pr('d');
        return 0 ; 
    }
    if(turnx>turny) {
        while(turny>0) {
            if(x>2) {
                x--;
            }
            else y--;
            if(y>0) {
                y--;
            }
            else x--;
            turnx--;
            turny--;
        }
        if(y>0) {
            pr('s');
            return 0 ;
        }
        if(x%2==0) {
            pr('s');
        }
        else pr('d');
    }
    else if(turnx==turny) {
        while(turny>1) {
            x--;
            if(y>0) {
                y--;
            }
            else x--;
            turnx--;
            turny--;
        }
        if(y>0)y--;
        else x--;
        if(y>0)pr('d');
        else if(x%2) {
            pr('d');
        }
        else pr('s');

    }
    return 0; 
}