#include <bits/stdc++.h>
using namespace std;
 
#define N 100005
 
// predefines the tree with nodes
// storing gcd, min and count
struct node 
{
    int gcd;
    int min;
    int cnt;
} tree[5 * N];
 
// function to construct the tree
void buildtree(int low, int high, 
               int pos, int a[])
{
    // base condition
    if (low == high) 
    {
        // initially always gcd and min
        // are same at leaf node
        tree[pos].min =  tree[pos].gcd = a[low];
        tree[pos].cnt = 1;
         
        return;
    }
 
    int mid = (low + high) >> 1;
     
    // left-subtree
    buildtree(low, mid, 2 * pos + 1, a);
 
    // right-subtree
    buildtree(mid + 1, high, 2 * pos + 2, a);
 
    // finds gcd of left and rigth subtree
    tree[pos].gcd = __gcd(tree[2 * pos + 1].gcd, 
                      tree[2 * pos + 2].gcd);
 
    // left subtree has the minimum element
    if (tree[2 * pos + 1].min < tree[2 * pos + 2].min) 
    {
        tree[pos].min = tree[2 * pos + 1].min;
        tree[pos].cnt = tree[2 * pos + 1].cnt;
    }
     
    // right subtree has the minimum element
    else
    if (tree[2 * pos + 1].min > tree[2 * pos + 2].min) 
    {
        tree[pos].min = tree[2 * pos + 2].min;
        tree[pos].cnt = tree[2 * pos + 2].cnt;
    }
     
    // both subtree has the same minimum element
    else
    {
        tree[pos].min = tree[2 * pos + 1].min;
        tree[pos].cnt = tree[2 * pos + 1].cnt + 
                        tree[2 * pos + 2].cnt;
    }
}
 
// function that answers every query
node query(int s, int e, int low, int high, int pos)
{
    node dummy;
     
    // out of range
    if (e < low or s > high) 
    {
        dummy.gcd = dummy.min = dummy.cnt = 0;
        return dummy;
    }
     
    // in range
    if (s >= low and e <= high) 
    {
        node dummy;
        dummy.gcd = tree[pos].gcd;
        dummy.min = tree[pos].min;
        if (dummy.gcd != dummy.min)
            dummy.cnt = 0;
        else
            dummy.cnt = tree[pos].cnt;
         
        return dummy;
    }
 
    int mid = (s + e) >> 1;
     
    // left-subtree
    node ans1 = query(s, mid, low, 
                high, 2 * pos + 1);
     
    // right-subtree
    node ans2 = query(mid + 1, e, low, 
                   high, 2 * pos + 2);
 
    node ans;
     
    // when both left subtree and
    // right subtree is in range
    if (ans1.gcd and ans2.gcd) 
    {
        // merge two trees
        ans.gcd = __gcd(ans1.gcd, ans2.gcd);
        ans.min = min(ans1.min, ans2.min);
 
        // when gcd is not equal to min
        if (ans.gcd != ans.min)         
            ans.cnt = 0;        
        else
        {
            // add count when min is
            // same of both subtree
            if (ans1.min == ans2.min)             
                ans.cnt = ans2.cnt + ans1.cnt;            
             
            // store the minimal's count
            else
            if (ans1.min < ans2.min)             
                ans.cnt = ans1.cnt;            
            else            
                ans.cnt = ans2.cnt;            
        }
         
        return ans;
    }
     
    // only left subtree is in range
    else if (ans1.gcd)
        return ans1;
     
    // only right subtree is in range
    else if (ans2.gcd)
        return ans2;
}
 
// function to answer query in range l-r
int answerQuery(int a[], int n, int l, int r)
{
    // calls the function which returns
    // a node this function returns the
    // count which will be the answer
    return query(0, n - 1, l - 1, r - 1, 0).cnt;
}
 
// Driver Code
int main()
{
    int a[] = { 3, 4, 2, 2, 4, 6 };
 
    int n = sizeof(a) / sizeof(a[0]);
    buildtree(0, n - 1, 0, a);
    int l = 1, r = 4;
 	for(int i=0;i<16;i++)printf("%d %d %d\n",tree[i].gcd,tree[i].min,tree[i].cnt);
    // answers 1-st query
    cout << answerQuery(a, n, l, r) << endl;
 
    l = 1, r = 6;
    // answers 2nd query
    cout << answerQuery(a, n, l, r) << endl;
    return 0;
}

