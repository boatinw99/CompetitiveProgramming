#include <iostream>
#include <vector>
#include "sockslib.h"

using namespace std;
const int N = 2e6+9 ;
bool vst[N];
vector<int> v ;
int main() {

    int n = num()*2,i,j;
    v.push_back(n);
    for(j=n-1;j>=1;j--)
    {
        v.push_back(j);
        if(ask(v)!=v.size())
        {
            int l=-1,r=v.size();
            while(l+1<r)
            {
                int mid=l+r>>1 ;
                vector<int> u(v.begin()+mid,v.end());
                if(ask(u)!=u.size())l=mid ;
                else r=mid ;
            }
            match(v[l],v.back());
            v.pop_back();
            vector<int> tmp ;
            for(auto it:v)
            {
                if(it!=v[l])tmp.emplace_back(it);
            }
            v=tmp ;
        }
    }
}

