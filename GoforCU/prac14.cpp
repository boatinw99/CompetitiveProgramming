///dsu
#include<bits/stdc++.h>
using namespace std ;
const int N = 59;
int parent[N],rankr[N];
int find(int i)
{
    int x;
    if(parent[i]!=parent[parent[i]])
    {
        parent[i]=find(parent[i]);
    }
    return parent[i];
}
void unionset(int x,int y)
{
    int x1=find(x),y1=find(y);
    if(x1!=y1)
    {
        if(rankr[x]>=rankr[y])
        {
            rankr[x]+=rankr[y];
            parent[y]=parent[x];
        }
        else
        {
            rankr[y]+=rankr[x];
            parent[x]=parent[y];
        }
    }
}
main()
{

}
