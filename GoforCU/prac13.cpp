#include<bits/stdc++.h>
using namespace std ;
struct TrieNode
{
    bool END ;
    struct TrieNode *child[26];
};
struct TrieNode * getnode()
{
    struct TrieNode *p=new TrieNode;
    p->END=0;
    for(int i=0;i<26;i++)p->child[i]=0;
    return p;
}
main()
{

}
