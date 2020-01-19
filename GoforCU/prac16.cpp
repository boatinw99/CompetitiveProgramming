#include<bits/stdc++.h>
using namespace std ;
int L[309];
int n;
string text;
int find()
{
    int N=2*n-1,C=1,R=2,diff,maxLPS=1,mir,i;
    bool expand;
    for(i=2;i<N;i++)
    {
        diff=R-i;
        expand=0;
        if(diff>0)
        {

        }
        else expand=1;
        if(expand)
        {

        }
        if(i+L[i]>R)R=i+L[i],C=i;
        maxLPS=max(maxLPS,L[i]);
    }
    return maxLPS;
}
main()
{
    find();
}
