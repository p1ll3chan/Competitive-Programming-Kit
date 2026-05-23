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
    for (int i = 0; i < n; i++)
    {
        string s;cin>>s;
        if(s[0]=='a' || s[0]=='b' || s[0]=='c') cout << 2;
        if(s[0]=='d' || s[0]=='e' || s[0]=='f') cout << 3;
        if(s[0]=='g' || s[0]=='h' || s[0]=='i') cout << 4;
        if(s[0]=='j' || s[0]=='k' || s[0]=='l') cout << 5;
        if(s[0]=='m' || s[0]=='n' || s[0]=='o') cout << 6;
        if(s[0]=='p' || s[0]=='q' || s[0]=='r' || s[0]=='s') cout << 7;
        if(s[0]=='t' || s[0]=='u' || s[0]=='v') cout << 8;
        if(s[0]=='w' || s[0]=='x' || s[0]=='y' || s[0]=='z') cout << 9;
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