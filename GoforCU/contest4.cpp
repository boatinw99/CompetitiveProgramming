#include<bits/stdc++.h>
using namespace std ;
string A,B;
const int N = 2009;
int n,m;
int l=0,r;
int dpa[N][26];
int dpb[N][26];
main()
{
    int i,j,k;
    cin >> A ;
    cin >> B;
    n=A.length();
    m=B.length();
    for(i=1;i<=n;i++)
        for(k=0;k<26;k++)
            dpa[i][k]=dpa[i-1][k]+(A[i-1]=='A'+k);
    for(i=1;i<=m;i++)
        for(k=0;k<26;k++)
            dpb[i][k]=dpb[i-1][k]+(B[i-1]=='A'+k);
    r=min(n,m)+1;
    while(l+1<r)
    {
        int mid=(l+r)/2;
        bool b=1 ;
        for(i=mid;i<=n;i++)
        {
            b=1;
            for(j=mid;j<=m;j++)
            {
                b=0;
                for(k=0;k<26;k++)
                {
                    if((dpa[i][k]-dpa[i-mid][k])!=(dpb[j][k]-dpb[j-mid][k]))
                    {
                        b=1;
                        break;
                    }
                }
                if(b==0)break;
            }
            if(b==0)break;
        }
        if(b==0)
        {
            l=mid;
        }
        else
        {
            r=mid;
        }
    }
    printf("%d",l);
}
