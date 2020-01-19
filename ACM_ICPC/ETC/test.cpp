#include<bits/stdc++.h>
using namespace std ;
int main()
{
    ifstream inFile ; 
    //inFile.open("C:\\Users\\BOAT\\OneDrive\\เดสก์ท็อป\\Vocabulary");
    string x ; 
    inFile.open("test.txt");
    while(inFile >> x )
    {
        cout << x << '\n' ;
        printf("what ? ");
    }
    inFile.close();
    return 0 ;
}