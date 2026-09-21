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
    string s;cin>>s;
    if(s[0]=='1'){
        int zeroleft=0;
        for (int i = 1; i < n; i++)
        {
            if(s[i]=='0') zeroleft++;
        }
        cout<<zeroleft<<endl;
        return;
        
    }

    int firstone=-1;
    for (int i = 0; i < n; i++)
    {
        if(s[i]=='1'){
            firstone=i;
            break;
        }
    }

    if(firstone==-1){
        cout<<0<<endl;
        return;
    }
    
    int firstoneall=0,lastzeroall=0;
    for (int i = firstone; i < n; i++)
    {
        if(s[i]=='0') lastzeroall++;
    }
    int ans=lastzeroall;
    for (int i = firstone; i < n; i++)
    {
        if(s[i]=='1') firstoneall++;
        else lastzeroall--;
        int cost=firstoneall+lastzeroall;
        ans=min(ans,cost);
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
    test();
    //solve();
    return 0;
}