#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define sz(x) (int)((x).size())
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
    vector<string> arr;
    for (int i = 0; i < 5; i++)
    {
        string s;cin>>s;
        arr.push_back(s);
    }
    int min_cnt=100;

    int dx[]={0,1,1,1};
    int dy[]={1,0,1,-1};

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int d = 0; d < 4; d++)
            {
                int cnt=0;
                bool valid=true;

                for (int tar = 0; tar < 5; tar++)
                {
                    int x = i + tar * dx[d];
                    int y = j + tar * dy[d];

                    if (x < 0 || x >= 5 ||
                        y < 0 || y >= 5) {

                        valid = false;
                        break;
                    }

                    if(arr[x][y]=='.') cnt++;


                }
                if(valid) min_cnt=min(min_cnt,cnt);

                
                
            }
            
        }
        
    }
    cout<<min_cnt<<endl;
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