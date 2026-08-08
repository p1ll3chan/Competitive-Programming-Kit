/*
Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].

The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.

You must write an algorithm that runs in O(n) time and without using the division operation.

*/

// Contraint
/*
2 <= nums.length <= 105
-30 <= nums[i] <= 30
The input is generated such that answer[i] is guaranteed to fit in a 32-bit integer.
*/

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
#define rep(i, a, b) for (int i = (a); i < (b); ++i)
#define rrep(i, a, b) for (int i = (a); i >= (b); --i)

/*
----
Problem:

My Intuition:   The only solution in get is a O(n^2) one,
                Do a nested loop, where for each iteration we take the total_production except the when
                Iteration index [i] and Loop index [j] is might which is none other than the value 
                said in the condition. [We skip the process].

Approach 1:   
            The key idea: each prefix/suffix array deliberately excludes the current index, because the final answer for index i is:

            answer[i] = leftPref[i] * rightPref[i];

Why Failed:

Approach 2:

Example Process:

Final Learning:

------
*/

void solve() {
    vi v;
    int x;
    while(cin>>x){
        v.pb(x);
    }
    int n=v.size();
    vi rightPref(n);
    vi leftPref(n);

    rightPref[0]=1;
    rep(i,1,n){
        rightPref[i]=rightPref[i-1]*v[i-1]; // We're storing the product after i, so we include the next element, not the current one.
    }

    leftPref[n-1]=1;
    rrep(i,n-2,0){
        leftPref[i]=leftPref[i+1]*v[i+1]; // To compute the product before index i, take the product before i-1 and multiply by the previous element
    }
    vi ans(n);
    rep(i,0,n){
        ans[i]=rightPref[i]*leftPref[i];
    }
    printVec(ans);
    //printVec(v);
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