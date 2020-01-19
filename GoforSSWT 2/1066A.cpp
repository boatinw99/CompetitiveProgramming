#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t,a,v,l,r;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d %d %d %d",&a,&v,&l,&r);
        int tmp = (a/v);
        l--;
        tmp-=(r/v-l/v);
        cout << tmp << endl;
    }
}
