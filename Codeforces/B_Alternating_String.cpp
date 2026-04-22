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
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define YESNO(x) cout << ((x) ? "YES" : "NO") << endl
#define debug(x) cerr << #x << " = " << (x) << endl;
#define debugArr(arr) for (auto v : arr) cerr << v << " "; cerr << endl;
#define readVec(v, n) for (int i = 0; i < n; ++i) cin >> v[i];
#define readMatrix(mat, n, m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mat[i][j];
#define printVec(v) for (auto x : v) cout << x << " "; cout << endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }
#define fp(i, a, b) for (int i = (a); i < (b); ++i)
/*
Point to catch
-> If max_freq of a/b is less than 3 = PASS
-> if substring "aabbaa" or "bbaabb" => No
-> if there is more than one "aa" or "bb" => No
*/
bool check(string s) {
    int faults = 0;
    int n = s.size();

    // Count every time two adjacent characters are the same
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i+1]) {
            faults++;
        }
    }

    // If there are 2 or fewer faults, it's always fixable.
    // If there are 3 or more, one operation is never enough.
    return faults <= 2;
}

bool checkk(string s) {
    int n = s.size();

    int cntA = 0, cntB = 0;
    for (char c : s) {
        if (c == 'a') cntA++;
        else cntB++;
    }

    if (cntA == 0 || cntB == 0 && n==3) return true;

    if (max(cntA, cntB) < 3) return true;

    if (s.find("aabbaa") != string::npos) return false;
    if (s.find("bbaabb") != string::npos) return false;

    int aa = 0, bb = 0;
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == 'a' && s[i+1] == 'a') aa++;
        if (s[i] == 'b' && s[i+1] == 'b') bb++;
    }

    if (aa > 1 || bb > 1) return false;

    return true;
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;cin>>s;
        if(check(s)) YES;
        else NO;
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