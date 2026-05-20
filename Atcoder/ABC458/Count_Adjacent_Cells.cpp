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
    Make a N x M square where each cell should count how many immediate neighbors it has.

My Intuition:
    We know by default there 4 neighbors and the only place where that count get reduce is the side and the corners to 3 and 2 respectively

Approach 1:
    Create a nested matrix loop and make 4 as the default cell notations.
    we know common thing about the edges is that either i or j is same across the dimension
    
    and for corners i and n,m are related by index.

    So just output the 4 condtion by reducing the edges by 1 and corner by 2, in each opeartion

Why Failed:

Approach 2:

Example Process:

Final Learning:
    Output Generation on implementation Trick by index

------
*/

void solve() {
    int n,m;cin>>n>>m;
    //vector<string> s;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            int cnt=4;
            if (i==1) cnt--;
            if (i==n) cnt--;
            if (j==1) cnt--;
            if (j==m) cnt--;
            cout<<cnt<<" ";
        }
        cout<<endl;
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