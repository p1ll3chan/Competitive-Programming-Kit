#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define ll long long
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define vi vector<ll>
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
    You are given a set of nuber in an array and you are given the task to find abs(subarraySum_max - subarraySum_min)
    Problem expects a Complexity less than O(n).

My Intuition:
    Use the Prefix Sum Idea here.

Approach 1:
    I would use the base Prefix Sum function and find the subarray of the consicutive order by by "pref(r)-perf(l+1)".
    I this way i can get the sum of the selected array and find the ans.

Why Failed:
    Overcomplicating with prefix sum,while the question gave use disjoint segement. So a simple linear search was enough here.

Approach 2:

Example Process:

Final Learning:
    Preprocessed Prefix Sum

------
*/

//vi arr(100000);

// int pref(int n){
//     vi preff(100000+1);
//     preff[0]=arr[0];
//     for (int i = 0; i < n ; i++)
//     {
//         preff[i+1]=preff[i] + arr[i];
//     }
//     return preff[n];
// }

// void solve1() {
//     int n,m;cin>>n>>m;
//     vi arr(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin>>arr[i];
//     }
//     int min_val=INT_MAX,max_val=INT_MIN;
//     for (int i = 0; i < m; i++)
//     {
//         ll l,r;cin>>l>>r;
//         ll ans=pref(r)-pref(l-1);
//         //debug(ans)
//         if(min_val>ans) min_val=ans;
//         if(max_val<ans) max_val=ans;
//     }
//     // debug(min_val)
//     // debug(max_val)
//      cout<<abs(max_val-min_val)<<endl;
// }


void solve() {
    ll n,m;cin>>n>>m;
    vi arr(n);
    for (ll i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    ll min_val=1e8,max_val=0;
    for (ll i = 0; i < m; ++i)
    {
        ll l,r;cin>>l>>r;
        l--;
        ll sum=0;
        for (ll i = l; i < r; ++i)
        {
            sum+=arr[i];
        }
        
        //debug(ans)
        // if(min_val>ans) min_val=ans;
        // if(max_val<ans) max_val=ans;
        min_val = min(min_val, sum);
        max_val = max(max_val, sum);
    }
    // debug(min_val)
    // debug(max_val)
     cout<<max_val-min_val<<endl;
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