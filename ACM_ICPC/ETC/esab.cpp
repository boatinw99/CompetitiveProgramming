#include<bits/stdc++.h>
using namespace std ;
int main() {
    int T,B ; 
    scanf("%d %d",&T,&B);
    for(int t=1;t<=T;t++) {
       string s = "" ;
        for(int i=1;i<=B;i++) {
            char c ;
            printf("%d\n",i);
            fflush(stdout);
            scanf(" %c",&c);
            s.push_back(c);
        }
        // for(int i=0;i<s.size();i++) {
        //     printf("%d",s[i]);
        // }
        printf("%s \n",s.c_str());
        fflush(stdout);
    }
    return 0 ; 
}