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
    Idogiology of the problem

    -> There will be a matrix of char contain '#' and '.' & a string containing the Direction R,L,U,D . We have a grid pointer [robot] that will take the grid containing '#' to '.' .
     So the goal is to count the '#' that are not taken.

    Intution of the problem

    -> Easiest Logic is  ( Total '#' count - Taken count of '# )
    -> So we have to count the '#' according to Directional Strings.

    ->  If 'U' (-1,0) 
        If 'D' (1,0)
        If 'R' (0,+1)
        If 'L' (0,-1)

    WE have to provide after the 
    -> Boundary Condition [out-of-bound error]
    -> Update the grid + count
    
    Note: Here for simulate in O(n), we need a starter  so we check the first grid point then we will loop through the entire grid according to the firect.
            So we will be looping thought the string are ke yfor the simulation.

*/

void solve(){
    int h,w,n;cin>>h>>w>>n;
    vector<string>v(h);
    int tot=0;
    for (int i = 0; i < h; i++)
    {
        cin>>v[i];
        tot+=count(v[i].begin(),v[i].end(),'#');
    }
    int coll=0;
    string s1;cin>>s1;
    int r=0,u=0;
    if(v[r][u]=='#'){
            v[r][u]='.';
            coll++;
        }
    
    for(char x:s1){
        int nr=r,mr=u;
        if(x=='U') nr--;
        if(x=='D') nr++;
        if(x=='R') mr++;
        if(x=='L') mr--;

        if(0<=nr && nr<h && 0<=mr && mr<w){
            r=nr;
            u=mr;
        }
        if(v[r][u]=='#'){
            v[r][u]='.';
            coll++;
        }
    }

    cout<<tot-coll<<endl;
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