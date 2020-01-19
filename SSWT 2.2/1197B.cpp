#include <bits/stdc++.h>
using namespace std ;
typedef long long ll ;
typedef pair<int,int> pii;
#define fi first
#define se second
int ask(int a, int b, int ret = 0)
{
    printf("? %d %d\n",a,b);
    fflush(stdout);
    scanf("%d", &ret);
    return ret;
}
vector<int> ans,base ={4,8,15,16,23,42};
int main()
{
    int a, b, c, d;
    a=ask(1,2),b=ask(1,3),c=ask(1,4),d=ask(1,5);
    int gc = __gcd(a, __gcd(b, __gcd(c, d)));
    ans.push_back(gc);
    ans.push_back(a/gc);
    ans.push_back(b/gc);
    ans.push_back(c/gc);
    ans.push_back(d/gc);
    for(int i=0;i<base.size();i++)
    {
        bool fnd=0;
        for(int j=0;j<ans.size();j++)
        {
            fnd|=(base[i]==ans[j]);
        }
        if(!fnd)
        {
            ans.push_back(base[i]);
            break;
        }
    }
    printf("! ");
    for(int i : ans) printf("%d ", i);
    printf("\n");
    fflush(stdout);
    return 0;
}
