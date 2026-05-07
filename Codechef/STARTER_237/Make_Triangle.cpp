#include <bits/stdc++.h>
using namespace std;

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
Problem : 
We were given the side length of a triangle A,B,C, and we are allowed to increment only 1 to each of the sides at a time.
What is the minimum number of moves required so that A,B,C can be the side lengths of a non-degenerate triangle.

Note: Non-degenrate triangle happens when a+b > c, b+c > a & a+c > b .
*/

/*
Solution Discussion : 

Clearly we need the number of moves to make that happen then why don't we observe the base condition here

a + b > c .

We can refram this as " a + b + moves > c". Since the difference between the arthmetic is the number of moves needed that itself
is the minimum. 

so,

moves => c - (a + b) + 1

so this is the final fromual to output.
*/

void solve() {
        vi v(3);

        cin >> v[0] >> v[1] >> v[2];
        sort(v.begin(), v.end());
        int a = v[0];
        int b = v[1];
        int c = v[2];

        int ans = max(0LL, c - (a + b) + 1);

        cout <<ans <<endl;
}

void test() {
    int t;
    cin >> t;
    while (t--) solve();
}

int32_t main() {
    fastio();
    test();
    //solve();
    return 0;
}