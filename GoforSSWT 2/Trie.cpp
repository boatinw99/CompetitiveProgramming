#include<bits/stdc++.h>
using namespace std ;
struct TrieNode
{
    bool End;
    struct TrieNode *child[26];
};
struct TrieNode *getnode()
{
    struct TrieNode *p=new TrieNode;
    p->End = 0 ;
    for(int i=0;i<26;i++)
    {
        p->child[i]=0;
    }
    return p;
}
void construct(struct TrieNode *p,string s)
{
    int in ;
    for(int i=0;i<s.length();i++)
    {
        in = s[i]-'a' ;
        if(p->child[in]!=0)
        {
            p->child[in]=getnode();
        }
        p=p->child[in];
    }
}
bool search(struct TrieNode *p,string s)
{
    int in;
    for(int i=0;i<s.length();i++)
    {
        in=s[i]-'a';
        if(p->child[in]==0)return 0;
        p=p->child[in];
    }
    return p->End&&p!=NULL ;
}
main()
{

}
