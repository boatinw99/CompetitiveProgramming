/**
 *    Author : boatinw99
 *    Date : 1.5.2019 14.16
 **/
#include "cave.h"
#include<bits/stdc++.h>
using namespace std ;
#define mid (l+r>>1)
const int N = 5009 ;
void mem(int l,int r,int val,int *S,int *D)
{
    for(int i=l;i<=r;i++)
    {
        if(D[i]==-1)S[i]=val;
    }
}
void solve(int l,int r,int state,int x,int *S,int *D)
{
    if(l==r)
    {
        //printf("chk l=%d state=%d x=%d\n",l,state,x);
        D[l]=x;
        S[l]=state;
        return ;
    }
    mem(l,mid,state^1,S,D);
    int ret = tryCombination(S);
    ///printf("chk (%d %d) %d \n",l,r,ret);
    if(ret==x)
    {
        mem(l,mid,state,S,D);
        solve(l,mid,state,x,S,D);
    }
    else solve(mid+1,r,state,x,S,D);
}
void exploreCave(int n)
{
    int S[n],D[n];
    memset(D,-1,sizeof D);
    memset(S,0,sizeof S);
    for(int i=0;i<n;i++)
    {
        mem(0,n-1,0,S,D);
        int ret = tryCombination(S);
        if(ret>i||ret==-1)solve(0,n-1,0,i,S,D);
        else
        {
            mem(0,n-1,1,S,D);
            solve(0,n-1,1,i,S,D);
        }
        //break;
    }
    answer(S,D);
}
