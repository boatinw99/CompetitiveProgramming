#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
string pat = "codecube";
char s[N];
main()
{
    int i,j,pr=0,m=8,n ;
    scanf("%s",&s);
    n=strlen(s);
    for(i=0,j=0;i<n;)
    {
        while(s[i]!=pat[j]&&j<m&&i<n)
        {
            j++;
            pr++;
        }
        if(j==m)j=0 ;
        else i++,j++;
    }
    pr+=m-j;
    printf("%d",pr);
}
