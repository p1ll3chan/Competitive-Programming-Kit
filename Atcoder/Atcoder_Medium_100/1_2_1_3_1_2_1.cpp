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
    We are given the task of gereating a sequence for F(n)
    the operation calls like
    * F[1] = {1}
    * F[n] = generate the sequence of concatenating Sn−1, n, Sn−1 in this order
    
    Now we need to generate entire sequence

My Intuition:
    Use Recurssive DP here but i caught up with the issue on how to store the sequence

Approach 1:
    Use Recurssive DP
    
    we can create a array builder using recurssion, 

    our formula is ,

    DP[n] = solve(n-1) + n + solve(n-1)

    so we can create the recurssive array and process the subproblem within a new array 'ans'.

    we use forloop for each subproblem like the line ,

    vi prev=dp_rec(n-1);
    vi ans;
    for(auto x : prev) ans.pb(x);
    ans.pb(n);
    for(auto x : prev) ans.pb(x);

    is just like,

    smaller answer already exists
    copy it
    add n
    copy it again

Why Failed:

Approach 2:
    DP Recurssion + Memoisation

    we used map<int,vi> and store the already counted value to the array and rest if same as 
    the ordinary recurssion.

    we call the globally called 'map' by modifing/updating it with the local array 'ans'

Example Process:

Final Learning: 
    How to use DP calls in a data structure manner

    Solving the smallest prob with array building and assigning it the construction of final array
    according to the formula

    Learned DP Recurssion + Memoisation in application level
    
------
*/

vector<int> dp_rec(int n){
    if(n==1) return {1};
    vi prev=dp_rec(n-1);
    vi ans;
    for(auto x : prev) ans.pb(x);
    ans.pb(n);
    for(auto x : prev) ans.pb(x);
    return ans; // we could just call it as it is,
}

map<int,vi> memo;

vi dp_mom(int n){
    if(n==1) return {1};
    if(memo.count(n)) return memo[n];
     
    vi prev=dp_mom(n-1);
    vi ans;
    for(auto x : prev) ans.pb(x);
    ans.pb(n);
    for(auto x : prev) ans.pb(x);
    return memo[n]=ans;
}


void solve() {
    int n;
    cin >> n;
    //printVec(dp_rec(n));
    printVec(dp_mom(n));
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