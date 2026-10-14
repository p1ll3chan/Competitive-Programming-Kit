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

void kS_Val(vector<pair<int,int>> arr,int W){
    vector<int> knap_s(W+1,0);
    for (int i = 0; i < sz(arr); i++)
    {
        for (int j = W; j >= arr[i].second; j--)
        {
            knap_s[j]=max(knap_s[j],knap_s[j-arr[i].second]+arr[i].first);
        }
    }
    

    // int ans=0;
    // for (int i = 0; i < sz(knap_s); i++)
    // {
    //     if(knap_s[i]>ans) ans=knap_s[i];
    // }
    
    cout<<knap_s[W]<<endl;
}

void solve_1() {
    int N,W;cin>>N>>W;
    vector<pair<int,int>> plates(N);

    for (int i = 0; i < N; i++)
    {
        cin>>plates[i].first>>plates[i].second;
    }
    // sort(plates.rbegin(),plates.rend(),[](const pair<int,int> &a,const pair<int,int> &b){
    //     return a.first < b.first;
    // });
    kS_Val(plates,W);
    
    // Your logic here
}

void solve() {
    int N,W;cin>>N>>W;
    vi A(N),B(N);
    for (int i = 0; i < N; i++)
    {
        cin>>A[i]>>B[i];
    }
    
    int ans=0;
    for (int x = 0; x < (1LL<<N); x++)
    {
        int Val=0,Vol=0;
        for (int i = 0; i < N; i++)
        {
            if(x&(1LL<<i)){
                Val+=A[i];
                Vol+=B[i];
            }
        }
        if(Vol<=W) ans=max(ans,Val);
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