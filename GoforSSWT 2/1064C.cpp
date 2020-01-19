#include<bits/stdc++.h>
using namespace std ;
const int N = 2e5+9;
char s[N];
main()
{
    int n,i;
    scanf("%d",&n);
    scanf("%s",&s);
    sort(s,s+n);
    for(i=0;i<n;i++)printf("%c",s[i]);
}
