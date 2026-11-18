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
    int max_v=INT_MIN,min_v=INT_MAX;
    // Your logic here
    for (int i = 0; i < n; i++)
    {
        max_v=max(max_v,v[i]);
        min_v=min(min_v,v[i]);
    }

    if(max_v==min_v) cout<<max_v<<endl;
    else{
        cout<<(((1<<(32-__builtin_clz(max_v^min_v)))-1) | max_v)<<endl;
    }
    /*
    If msb(min(a))<b
        , then we can increase the minimum value to be 2^(b)−1
        by repeatedly incrementing some entry in the array that is adjacent to a larger entry and less than 2^(b)−1
        . This results in the answer being exactly 2^(b)+1−1
        .
    */


    /*
    the answer is max(a)OR(2k+1−1)
        where k=msb(max(a)XORmin(a))
        if max(a)≠min(a)
        , and simply max(a)
        otherwise.*/
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