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
    Solution Logic

    if S[i]=='U'

    then
    
     * j>i 1 steps;
       j<i 2 steps {Go to the Top then Come Down}

    if S[i]=='D'

    then
    
       j<i 1 steps
       i<j 2 steps {Go to the Bottom then Come Up}

       Since the contraint Clearly says S[0]=U and S[n-1]=D


       So teh condition formula will be 
       if S[i]=='U'
            (N-i) * 1 + (i-1) * 2
        else [for 'D']
            (N-i) * 2 + (i-1) * 1

        ** Solution os the summation of the step in over all Sum ** 
        


*/
void solve() {
    string s;cin>>s;
    int ans=0;
    for (int i = 0; i < s.size(); i++)
    {
        int above=s.size()-i-1;
        int below=i;
        if(s[i]=='U'){
            ans+=above*1;
            ans+=below*2;
        }else{
            ans+=below*1;
            ans+=above*2;
        }
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