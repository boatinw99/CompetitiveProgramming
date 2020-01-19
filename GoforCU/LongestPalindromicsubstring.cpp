#include <stdio.h>
#include <string.h>
char text[100];
void findLongestPalindromicString()
{
    int N = strlen(text);
    N = 2*N + 1; //Position count
    int L[N]; //LPS Length Array
    L[0] = 0;
    L[1] = 1;
    int C = 1; //centerPosition 
    int R = 2; //centerRightPosition
    int i ; //currentRightPosition
    int iMirror; //currentLeftPosition
    int expand = -1;
    int diff = -1;
    int maxLPSLength = 0;
    int maxLPSCenterPosition = 0;
    int start = -1;
    int end = -1;
    for (i = 2; i < N; i++) 
    {
        expand = 0;
        diff = R - i;
        if(diff > 0) 
        { 
			iMirror  = 2*C-i;
            if(L[iMirror] < diff)L[i] = L[iMirror]; // Case 1
            else if(L[iMirror] == diff && i == N-1)L[i] = L[iMirror]; // Case 2
            else if(L[iMirror] == diff && i < N-1)  // Case 3
            {
                    L[i] = L[iMirror];
                    expand = 1;  // expansion required
            }
            else if(L[iMirror] > diff)  // Case 4
            {
                L[i] = diff;
                expand = 1;  // expansion required
            }
        }
        else L[i] = 0,expand = 1;
        
        if (expand == 1)
        {
            while (((i + L[i]) < N && (i - L[i]) > 0) && 
                ( ((i + L[i] + 1) % 2 == 0) || 
                (text[(i + L[i] + 1)/2] == text[(i-L[i]-1)/2] )))
        		L[i]++;
        }
        if(L[i] > maxLPSLength)maxLPSLength = L[i];
        if (i + L[i] > R) C = i , R = i + L[i];
    }
    printf("%d",maxLPSLength);
}
main()
{
    strcpy(text, "abbaa");
    findLongestPalindromicString();
}
