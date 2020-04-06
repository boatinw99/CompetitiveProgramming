#include<bits/stdc++.h>
using namespace std ;
int query(int x) {
    cout << x << endl ; 
    cin >> x ; 
    return x ; 
}
int main() {
    int T,B ; 
    cin >> T >> B;
    for(int t=1;t<=T;t++) {
        vector<int> arr(B+1);
        int l = 1 , r = B , num = 1 ; 
        while(l<=r) {
            int same = -1 ;
            int dif = -1 ;
            if((num%10==1)&&num!=1) {
                int tmp = 0 ; 
                for(int i=1;i<l;i++) {
                    if(arr[i]==arr[B-i+1]) {
                        same = i ;
                    }
                    else {
                        dif = i ;
                    } 
                }
                if(same!=-1) {
                    int res = query(same); 
                    tmp++ ;
                    if(res!=arr[same]) {
                        for(int i=1;i<=B;i++) {
                            arr[i]^=1;
                        }
                    }
                }
                if(dif!=-1) {
                    int res = query(dif);
                    tmp++;
                    if(res!=arr[dif]) {
                        reverse(arr.begin()+1,arr.end());
                    }
                }
                while(tmp<2) {
                    query(1);
                    tmp++;
                }
                num+=2;
            }
            arr[l] = query(l);
            arr[r] = query(r);
            l++;
            r--;
            num+=2;
        }
        for(int i=1;i<=B;i++) {
            cout << arr[i] ;
        } 
        cout << endl ;
        char c ;  
        cin >> c ;
        assert(c=='Y');
    }
    return 0 ; 
}