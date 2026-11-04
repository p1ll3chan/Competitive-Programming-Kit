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

void solve1() {
    int N,M;cin>>N>>M;
    vector<string> grid(N, string(M, ' '));
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin>>grid[i][j];
        }
        
    }
    int minRow=31,maxRow=31,minCol=31,maxCol=31;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if(grid[i][j]=='1') minRow=i,minCol=j;
        }
        
    }

    for (int i = N; i >= 0; i--)
    {
        for (int j = M; j >= 0; j--)
        {
            if(grid[i][j]=='1') maxRow=i,maxCol=j;
        }
        
    }
    
    int ans=(maxRow-minRow+1)*(maxCol-minCol+1);
    cout<<ans<<endl;
    // for(auto x : grid){
    //     for(auto i : x){
    //         cout<<i<<" ";
    //     }
    //     cout<<endl;
    // }

    
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<string> grid(N);
    for (int i = 0; i < N; i++) {
        cin >> grid[i];
    }

    int minRow = N, maxRow = -1;
    int minCol = M, maxCol = -1;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == '1') {
                minRow = min(minRow, i);
                maxRow = max(maxRow, i);

                minCol = min(minCol, j);
                maxCol = max(maxCol, j);
            }
        }
    }

    int ans =(maxRow - minRow + 1)*(maxCol - minCol + 1);

    cout<<ans<<endl;
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