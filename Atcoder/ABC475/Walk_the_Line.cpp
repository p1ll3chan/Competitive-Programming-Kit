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

Approach 1: Greedy + Prefix Sum + Two pointer [S->L->R && S->R->L]

Why Failed:

Approach 2:

Example Process:

Final Learning:

------
*/

void solve() {
    int n,s,L;
    cin >> n >> s >> L;
    s--;
    vi v(n-1);
    readVec(v, n-1);
    
    vector<long long> pref(n,0);
    //pref[0]=v[0];
    for (int i = 0; i < n-1; i++)
    {
        pref[i+1]=pref[i]+v[i];
    }
// For S -> L -> R
    int r=s,ans=1;
    for (int  l = 0; l <= s; l++)
    {
        while(r+1<n){
            int cost = 2*(pref[s] - pref[l])+(pref[r+1] - pref[s]);
            if(cost>L) break;
            else r++;
        }
        int cost = 2*(pref[s] - pref[l])+(pref[r] - pref[s]);
        //if(r<s) break;
        if(cost<=L) ans=max(ans,r-l+1);
    }
// For S -> R -> L
    int l=0;
    for (int  r = s; r < n; r++)
    {
        while(l<=s){
            int cost = (pref[s] - pref[l])+2*(pref[r] - pref[s]);
            if(cost<=L) break;
            else l++;
        }
        if(l>s) break;
        ans=max(ans,r-l+1);
    }

    cout<<ans;
    // Your logic here
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