#include "househouse.h"
#include<bits/stdc++.h>
using namespace std ;
int main()
{
    int C,M ;
    househouse_init(C,M);
    if(M<=C)while(1)househouse_pay(1);
    int div = M/C;
    if(C*2<=M)for(int i=1;i<=C;i++)househouse_pay(1);///2C
    else
    {
        while(1)househouse_pay(1);
    }
    househouse_pay(C);
}
