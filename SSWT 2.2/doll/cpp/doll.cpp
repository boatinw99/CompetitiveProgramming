#include "doll.h"
#include<bits/stdc++.h>
using namespace std ;
typedef pair<int,int> pii ;
#define fi first
#define se second
const int N = 2e5+9 ;
#define mid (l+r>>1)
vector<pii> pos ;
int n,L[N<<4],R[N<<4],id=1,a[N<<1],f[N<<1];
int construct(int l,int r,int x,int m)
{
    if(r<x)
    {
        id--;
        return -1 ;
    }
    if(l==r)
    {
        id--;
        return a[l];
    }
    L[m]=construct(l,mid,x,++id);
    R[m]=construct(mid+1,r,x,++id);
    return -m ;
}
void create_circuit(int M, vector<int> A)
{
    n=A.size()+1;
    A.push_back(0);
    int sz ;
    for(sz=1;sz<n;sz<<=1);
    f[1]=1;
    for(int len=sz/2,idx=1;len;len/=2,idx*=2)
    {
        for(int j=1;j<=idx;j++)f[j+idx]=f[j]+len ;
    }
    for(int i=sz-n+1;i<=sz;i++)pos.push_back({f[i],i});
    sort(pos.begin(),pos.end());
    int ptr = 0 ;
    for(auto it:pos)a[it.se]=A[ptr++];
    construct(1,sz,sz-n+1,1);
    vector<int> X(id),Y(id),C(M+1);
    for(int i=0;i<=M;i++)C[i]=-1;
    for(int i=1;i<=id;i++)
    {
        X[i-1]=L[i];
        Y[i-1]=R[i];
    }
    answer(C,X,Y);
}
