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
    Problem Statement: To find the count of numbers from 1 to n that has exactly 2 prime factor

    Solution Approch : Bruteforce + Prime factorization count/freq.


*/
void solve() {
    int n;
    cin >> n;
    int ans=0;
    for (int i = 1; i <= n; i++)
    {
        int x=i;
        int cnt=0;
        for (int d = 2; d <= x; d++)
        {
            if(x%d==0){        // Basic prime Factorization initaltive  [Finding the distict prime]
                cnt++;
                while(x%d==0){   // Basic prime Factorization initaltive    [Remove all occurance]
                    x/=d;
                }
            }
        }
        if(cnt==2) ans++;       // count of the occurrance
    }
    cout<<ans<<endl;
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