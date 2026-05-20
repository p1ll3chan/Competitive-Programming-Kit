#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define ll long long
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
We will input an initail value to the array. In q queries we are adding 2 values and each time we need to output the medium on each update.


My Intuition:
    Use the nth_element() and sort the middle index to the end values and output the new medium value.

Approach 1:
    Two Heap Method 

    Max Heap + Min Heap


Why Failed:
    The contraint aimed to achive under 2x1e5 which starts for an operation not more than O(N log N) here.

Approach 2:

Example Process:

Final Learning:
Two Heap Method {Max Heap + Min Heap size mantained segment trick}


------
*/

void solve1() {
    ll n;
    cin >> n;
    ll q;cin>>q;
    vector<ll> v;
    v.pb(n);
    for (ll i = 0; i < q; i++)
    {
        ll a,b;cin>>a>>b;
        v.pb(a);
        v.pb(b);
        //sort(all(v));
        
        nth_element(v.begin(),v.begin() + v.size()/2,v.end());
        cout<<v[v.size()/2]<<endl;
    } 
}


void solve() {
    ll n;
    cin >> n;
    ll q;cin>>q;
    priority_queue<int> L; //Max heap
    priority_queue<int,vi,greater<int>> R; //Min heap
    L.push(n);
    auto add=[&](int x){
        if(x<=L.top()){
            L.push(x);
        }else{
            R.push(x);
        }
        if(L.size() < R.size()+1){
            L.push(R.top());
            R.pop();
        }
        if(L.size() > R.size()+1){
            R.push(L.top());
            L.pop();
        }
    };

    for (int i = 0; i < q; i++)
    {
        int a,b;cin>>a>>b;
        add(a),add(b);
        cout<<L.top()<<endl;
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
    solve();
    return 0;
}