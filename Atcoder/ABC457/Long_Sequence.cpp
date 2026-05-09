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
    int n,m;cin>>n>>m;
    vii arr(n);
    vi make(n);
    for (int i = 0; i < n; i++)
    {
        cin>>make[i];
        
        arr[i].resize(make[i]);
        for (int j = 0; j < make[i]; j++)
        {
            cin>>arr[i][j];
        }
        
    }

    //vii ans;
    // for (int i = 0; i < n; i++)
    // {
    //     int chk;cin>>chk;
    //     vi box;
    //     for (int k = 0; k < chk; k++)
    //         {
    //     for (int j = 0; j < arr[i].size(); j++)
    //     {
            
    //             //box.pb(arr[i][j]);
    //             cout<<arr[m]<<endl;
    //         }
            
    //     }
    //     ans.pb(box);
    // }
    //printMatrix(ans);


    vi boxx(n);
    for (int i = 0; i < n; i++) {
        cin>>boxx[i];
    }
    for (int i = 0; i < n; i++) {

        int total = make[i] * boxx[i];
        if(m>total) {
            m-=total;
        }else{
            int an =(m-1)%make[i];
            cout<<arr[i][an]<<endl;
            return;
        }

    }

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