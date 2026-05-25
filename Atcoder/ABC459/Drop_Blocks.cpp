#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define rall(c) c.rbegin(),c.rend()
#define vii vector<vector<int>>
#define pii pair<int, int>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define YES cout << "Yes" << endl
#define NO cout << "No" << endl
#define YESNO(x) cout << ((x) ? "YES" : "NO") << endl
#define debug(x) cerr << #x << " = " << (x) << endl;
#define debugArr(arr) for (auto v : arr) cerr << v << " "; cerr << endl;
#define readVec(v, n) for (int i = 0; i < n; ++i) cin >> v[i];
#define readMatrix(mat, n, m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mat[i][j];
#define printVec(v) for (auto x : v) cout << x << " "; cout << endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }
#define fp(i, a, b) for (int i = (a); i < (b); ++i)

/*
----
Problem:
We are give the task to perfore 2 operation under q queries in an array of size n
    * 1 a -> Insert +1 to the v[a] value
    * 2 b -> output the count of values in the array that have atleast b elements
Note S.O : if every cell has at least 1 block, remove 1 block from every cell.

My Intuition:
    I adapted the idea of a property in multiset, where in each insertion the array restructure the order in sorted manner
    We just came to my thought, for the S.O
    -> If we inital state the size and insert the values we can estimate of the array is filled or not by 
        just focusing the first index, because if the first index is filled after restructing in multiset that means
        the array is at momentf for S.O,
    Now for the decrementing the array,
    -> We don't need to decrement the entire array we know it is to output the final value of that particular index.
        So we can just count occurance when the array becomes filled and at the moment of we have to output just reduce the 
        that value with the count

        * if(*ms.begin() > dec) dec++; -> Count of Occurance
        *  if(v[i]>=dec+b) -> The original expression is "v[i]-dec = b", where 'b' is the target value to compare.


Approach 2:
    MultiSet Fill-check and Global offset 

Why Failed:
    Time Complexity of approach O(NQ); -> 

    Problem limits the process till 1e5

Approach 2:
    Segment Tree Approach


    

Why Failed:

Approach 2:
    Fenwick Tree Approach

Example Process:
    3 7 -> n,q, these are q queries below with operations
    1 1
    1 3
    1 3
    2 1
    2 2
    1 2
    2 1

the arr =   0    [_,_,_]
            1    [1,_,_]
            2    [1,_,1]
            3    [1,_,2]
            4    [1,_,2] -> 2, since there are both values greater than given b=1 at idx = 1,3
            5    [1,_,2] -> 1, since there is only one values greater than given b=2 at idx = 3
            6    [1,1,2] => {S.O activates} => [0,0,1]
            
            7    [0,0,1] -> 1, since there is only one values greater than given b=2 at idx = 3

Final Learning:

------
*/

void solve() {
    int n,q;cin>>n>>q;
    
    vi v(n,0);
    multiset<int> ms(all(v));
    int dec=0;
    while(q--)
    {
        
        int x;cin>>x;
        if(x==1){
            int a;cin>>a;a--;
            ms.erase(ms.find(v[a]));
            v[a]++;
            ms.insert(v[a]);
            if(*ms.begin() > dec) dec++;
        }
        else{
            int b;cin>>b;
            int cnt=0;
            for (int i = 0; i < n; i++)
            {
                if(v[i]>=dec+b){
                    cnt++;
                }
            }
            
            //
            cout<<cnt<<endl;
        }
    }
    
}
/*
Approach 2:
    Segment Tree Approach
*/

const int MAXV = 300005;

typedef struct node {

    int l, r;
    int val;

    struct node *left, *right;

} node;

node* build(int l, int r) {

    node* ne = (node*)malloc(sizeof(node));

    ne->l = l;
    ne->r = r;
    ne->val = 0;

    if(l == r) {
        ne->left = ne->right = NULL;
        return ne;
    }

    int mid = (l + r) / 2;

    ne->left = build(l, mid);
    ne->right = build(mid + 1, r);

    return ne;
}

void update(node* t, int idx, int val) {

    if(t->l == t->r) {
        t->val += val;
        return;
    }

    int mid = (t->l + t->r) / 2;

    if(idx <= mid)
        update(t->left, idx, val);
    else
        update(t->right, idx, val);

    t->val = t->left->val + t->right->val;
}

int query(node* t, int ql, int qr) {

    if(t->r < ql || qr < t->l)
        return 0;

    if(ql <= t->l && t->r <= qr)
        return t->val;

    return query(t->left, ql, qr)
         + query(t->right, ql, qr);
}

void solve1(){
    int n, q;
    cin >> n >> q;

    vector<int> v(n, 0);

    multiset<int> ms;

    for(int i = 0; i < n; i++)
        ms.insert(0);

    node* head = build(0, MAXV);

    update(head, 0, n);

    int dec = 0;

    while(q--) {

        int type;
        cin >> type;

        if(type == 1) {

            int x;
            cin >> x;
            x--;

            int oldv = v[x];

            update(head, oldv, -1);

            ms.erase(ms.find(oldv));

            v[x]++;

            int newv = v[x];

            update(head, newv, +1);

            ms.insert(newv);

            if(*ms.begin() > dec)
                dec++;
        }
        else {

            int y;
            cin >> y;

            int need = y + dec;

            cout << query(head, need, MAXV) << endl;
        }
    }
}


void test() {
    int t;
    cin >> t;
    while (t--) solve();
}

int32_t main() {
    fastio();
    // test();
    solve1();
    return 0;
}