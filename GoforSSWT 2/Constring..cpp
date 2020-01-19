#include<bits/stdc++.h>
using namespace std ;
const int N = 1e5+9;
char A[N],B[N];
vector<int> v[256];
vector<int>::iterator it ;
main()
{
    int i,j,n,m,ans=1,k ;
    scanf("%s %s",&A,&B);
    n=strlen(A); m=strlen(B);
    for(i=0;i<n;i++)
    {
        v[A[i]].push_back(i+1);
    }
    for(i=0,j=1;i<m;)
    {
        k=B[i];
        it=lower_bound(v[k].begin(),v[k].end(),j);
        if(it==v[k].end()&&j==1)
        {
            printf("-1");
            return 0 ;
        }
        else if(it==v[k].end())
        {
            j=1;
            ans++;
        }
        else
        {
            j=(*it)+1;
            i++;
        }
    }
    printf("%d",ans);

}
