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
    int n;
    cin >> n;
    vi v(n);
    readVec(v, n);
    for (int i = 0; i < n; i++)
    {
        int N=v[i];
        while(N>1){
            int ans=0;
            while(N>0){
                int cnt=N%10;
                ans+=cnt*cnt;
                N/=10;
            }
            cout<<ans<<" ";
            N=ans;
        }
    }
    cout<<endl;
    // Your logic here
}

int NextVal(int N){
    int ans=0;
            while(N>0){
                int cnt=N%10;
                ans+=cnt*cnt;
                N/=10;
            }
    return ans;
}

void solve() {
    int n;
    cin >> n;
    vi v(n);
    readVec(v, n);

    map<int,int> hash;

    for(auto x : v){
        // 9^2 * 10 = 810
        for (int s = 0; s < 810; s++)
        {
            x=NextVal(x);
        }
        hash[x]++;
    }
    
    int ans=0;
    for(auto [x,y] : hash){
        ans+=y*(y-1)/2;
    }
    cout<<ans<<endl;    
    
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