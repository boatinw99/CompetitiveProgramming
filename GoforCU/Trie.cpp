#include<bits/stdc++.h>
using namespace std ;
string s;
struct TrieNode 
{
	struct TrieNode *child[26];
	bool end;
};
struct TrieNode *getnode()
{
	struct TrieNode *p = new TrieNode ;
	p->end = 0;
	for(int i=0;i<26;i++)
	{
		p->child[i]=NULL ;
	}
	return p;
}
void insert(struct TrieNode *root,string key)
{
	struct TrieNode *p = root;
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!p->child[index])p->child[index]=getnode();
		p=p->child[index];
	}
	p->end=1;
}
bool search(struct TrieNode *root,string key)
{
	struct TrieNode *p =root;
	for(int i=0;i<key.length();i++)
	{
		int index=key[i]-'a';
		if(!p->child[index])return 0;
		p=p->child[index];
	}
	return p!=NULL&&p->end;
}
main()
{
	int m,i,j ;
	scanf("%d",&m);
	struct TrieNode *root = getnode();
	while(m--)
	{
		cin >> s;
		insert(root,s);
	}
	printf("%d\n",search(root,"qpt"));
	printf("%d\n",search(root,"them"));
	printf("%d\n",search(root,"thq"));
	printf("%d\n",search(root,"t"));
	
}
