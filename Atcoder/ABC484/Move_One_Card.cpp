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
#define YESNO(x) cout << ((x) ? "Yes" : "No") << endl
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

void solve1() {
    int n;
    cin >> n;
    vi a(n),b(n);
    readVec(a, n);
    readVec(b, n);

    sort(all(a));
    sort(all(b));

    // printVec(a);
    // printVec(b);
    for (int i = 0; i < n; i++)
    {
        if(a[i]!=b[i]){
            cout<<"No"<<endl;
            return;
        }
    }
    cout<<"Yes"<<endl;

    // Your logic here
}

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    readVec(a, n); 
    readVec(b, n);

    int l = 0;
    while (l < n && a[l] == b[l]) l++;
    if (l == n) { 
        YES; 
        return; 
    }
    int r = n - 1;
    while (a[r] == b[r]) r--;



    bool ok1 = (a[l] == b[r]);
    for (int i = l; i < r && ok1; i++){
        if (a[i + 1] != b[i]) ok1 = false;
    }

    bool ok2 = (a[r] == b[l]);
    for (int i = l; i < r && ok2; i++){
        if (a[i] != b[i + 1]) ok2 = false;
    }

    YESNO(ok1 || ok2);
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