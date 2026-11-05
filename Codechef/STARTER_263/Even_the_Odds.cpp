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

My Intuition:

Approach 1:

Why Failed:

Approach 2:

Example Process:

Final Learning:

------
*/

void solve() {
    int n;
    cin >> n;
    vi v(n);
    readVec(v, n);
    vector<int> first(2, -2); // {ON,ON} -> Switch { []|[] }

    first[0] = -1; // {OFF,ON} -> Switch { [0]|[1] }
    int parity = 0;
    int ans = 0;

    for (int i = 0; i < n; i++) {
        parity ^= (v[i] % 2 != 0); // If Odd -> 1 && Even -> 0, XOR Operator act as "Swtich-to-Flip"

        if (first[parity] != -2) { //Flipped switch is checked
            ans = max(ans, i - first[parity]); //max(Difference btw First flip and the curr flip occured)
        } 
        else {
            first[parity] = i; //indexed by the parity state (0 = OFF, 1 = ON),
                                // and i is the position in the array where you first arrived at that state
        }
    }
    cout << ans << endl;
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