#include <bits/stdc++.h>
using namespace std;

// Macros
#define int long long
#define all(x) (x).begin(), (x).end()
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int, int>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define YES cout << "YES" << endl
#define NO cout << "NO" << endl
#define YESNO(x) cout << ((x) ? "YES" : "NO") << endl

// Debugging
#define debug(x) cerr << #x << " = " << (x) << endl;
#define debugArr(arr) for (auto v : arr) cerr << v << " "; cerr << endl;

// Input macros
#define readVec(v, n) for (int i = 0; i < n; ++i) cin >> v[i];
#define readMatrix(mat, n, m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mat[i][j];

// Output macros
#define printVec(v) for (auto x : v) cout << x << " "; cout << endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }

// Matrix Macros
#define create2D(v, n, m) vector<vector<int>> v(n, vector<int>(m))
#define create3D(v, n, m, k) vector<vector<vector<int>>> v(n, vector<vector<int>>(m, vector<int>(k)))

/*
max_block = 0
current_block = 0

for char in s:
    if char != c:
        current_block++
    else:
        max_block = max(max_block, current_block)
        current_block = 0

max_block = max(max_block, current_block)
answer = min(answer, max_block)

*/


/*
Points to not

Whenever you count continuous segments, always remember:

process segment when it ends
+
process last segment after loop

"This is the reason why we consider max_b=max(max_b,crr_b) inside and outside the loop twice"


*/
// Solve function
void solve() {
    string s;cin>>s;
    int ans=s.size();
    for (char i = 'a'; i <= 'z'; i++)
    {
        int max_b=0;
        int crr_b=0;
        for(char x:s){    // in this part we are going to take the count of non-'that char' element between 'that char' for each a->z
            if(x!=i){
                crr_b++;
            }else{
                max_b=max(max_b,crr_b); // storing that count 
                crr_b=0;
            }  
        }   // Then we are going to take the minimum operation needed to achieve that count
        max_b=max(max_b,crr_b); //still storing that count
        ans=min(ans,max_b);
    }
    cout<<ans<<endl;
}

// Testcase function
void test() {
    int t;
    cin >> t;
    while (t--) solve();
}

// Main function
int32_t main() {
    fastio();
    // test();
    solve();
    return 0;
}