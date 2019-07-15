#include<bits/stdc++.h>
using namespace std;
vector<int> arr, segTree;
void build(int root, int l, int r)
{
    if(l == r)
    {
        segTree[root] = arr[l];
    }
    else
    {
        int m = (l + r) / 2;
        build(root*2, l, m);
        build(root*2+1, m+1, r);
        segTree[root] = min(segTree[root*2], segTree[root*2+1]);
    }
}
void update(int root, int l, int r, int i, int val)
{
    if(l == r)
    {
        segTree[root] = val;
    }
    else
    {
        int m = (l + r) / 2;
        if(i <= m)
        {
            update(root*2, l, m, i, val);
        }
        else
        {
            update(root*2+1, m+1, r, i, val);
        }
        segTree[root] = min(segTree[root*2], segTree[root*2+1]);
    }
}
int query(int root, int l, int r, int l1, int r1)
{
    if(l1 > r1)
    {
        return INT_MAX;
    }
    if(l == l1 && r == r1)
    {
        return segTree[root];
    }
    int m = (l+r)/2;
    int x = query(root*2, l, m, l1, min(r1, m));
    int y = query(root*2+1, m+1, r, max(m+1, l1), r1);
    return min(x, y);
}
int main()
{
    int n, q;
    cin >> n >> q;
    arr.resize(n);
    segTree.resize(4*n);
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    build(1, 0, n-1);
    while(q--)
    {
        char c; int ql, qr;
        cin >> c >> ql >> qr;
        if(c == 'q')
        {
            cout << query(1, 0, n-1, ql-1, qr-1) << endl;
        }
        else
        {
            update(1, 0, n-1, ql-1, qr);
        }
        
    }
}
