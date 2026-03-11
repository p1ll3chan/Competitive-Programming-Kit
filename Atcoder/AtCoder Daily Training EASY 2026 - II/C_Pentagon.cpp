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


/* A-> D,C
   B-> D,E
   C-> A,E
   D-> A,B
   E-> B,C

   A,B,C,D,E
*/

//link to better solution : https://atcoder.jp/contests/adt_easy_20260310_1/editorial/7978

string ssp[10]={"AB","BC","CD","DE","EA","BA","CB","DC","ED","AE"};
string spp[10]={"AD","AC","BD","BE","CA","CE","DA","DB","EB","EC"};
void solve(){
    string s;cin>>s;
    string s1;cin>>s1;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            if(s==ssp[i] && s1==ssp[j]){
                YES;
                return;
            }
            if(s==spp[i] && s1==spp[j]){
                YES;
                return;
            }
            
        }
        
    }
    NO;
    
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