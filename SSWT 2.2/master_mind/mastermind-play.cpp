#include "mastermind-lib.h"
#include<bits/stdc++.h>
using namespace std ;
void find_answer(int N, int K, int U)
{
    int num_matched,num_misplaced;
    string s ;
    if(N==1)
    {
        for(int i=1;i<=K;i++)
        {
            s=i+'0';
            guess(s,num_matched,num_misplaced);
            if(num_matched==1)return ;
        }
    }
    else if(N==2)
    {
        for(int i=1;i<=K;i++)
        {
            for(int j=i+1;j<=K;j++)
            {
                s=i+'0';
                s+=j+'0';
                guess(s,num_matched,num_misplaced);
                if(num_misplaced==2)
                {
                    reverse(s.begin(),s.end());
                    guess(s,num_matched,num_misplaced);
                }
                if(num_matched==N)return ;
            }
        }
    }

}
