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
    vector<pair<int,int>> blocks;
    int cnt=1;
    for (int i = 0; i < n-1; i++)
    {
        if(v[i]==v[i+1])cnt++;
        else{
            blocks.emplace_back(v[i],cnt);
            cnt=1;
        }
    }
    blocks.emplace_back(v[n-1],cnt);
    int m=blocks.size();

    bool m2=false,m3=false;
    for (int i = 0; i < m-1; i++)
    {
         if(blocks[i].second>1 && blocks[i+1].second>1) m3=true;
    }

    for (int i = 0; i < m; i++)
    {
        if(i<m-1 && blocks[i].second>1 && 
            (i+2>=m || blocks[i].first!=blocks[i+2].first)) m2=true;

        if(i>0 && blocks[i].second>1 && 
            (i-2 < 0 || blocks[i].first!=blocks[i-2].first)) m2=true;
    }
    
    if(m3) cout << m+2 << endl;
    else if(m2) cout << m+1 << endl;
    else cout << m << endl;

    // Your logic here
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