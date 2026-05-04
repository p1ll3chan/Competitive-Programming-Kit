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

void solve() {
    int h,w;cin>>h>>w;
    vector<string> s(h);
    for (int i = 0; i < h; i++)
    {
        cin>>s[i];
    }
    int cnt=0;
    
    
        for (int h1 = 0; h1 < h; h1++)
        {
            for (int h2 = h1; h2 < h; h2++)
            {
                for (int w1 = 0; w1 < w; w1++)
                {
                    for (int w2 = w1; w2 < w; w2++)
                    {
                        bool ok=true;
                        for (int i = h1; i <= h2; i++)
                                {
                            for (int j = w1; j <= w2; j++)
                                {
                                    if(s[i][j]!=s[h1+h2-i][w1+w2-j]){
                                        ok=false;
                                        break;
                                    }
                    }
                    
                }
                if(ok) cnt++;
                
            }
            
        }
    }
        
    }
    cout<<cnt<<endl;
    
    
    
    //printVec(s);
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