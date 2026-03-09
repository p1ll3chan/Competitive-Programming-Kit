#include <bits/stdc++.h>
using namespace std;

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define sz(x) (int)((x).size())
#define f first
#define s second
#define pb push_back
#define vi vector<string>
#define rall(c) c.rbegin(),c.rend()
#define vii vector<vector<string>>
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

// Logic:
/*
    Contest Muscle Memory

    int dx[4] = {-1,0,1,0};
    int dy[4] = {0,1,0,-1};

    0 → up
    1 → right
    2 → down
    3 → left

    right turn : dir = (dir + 1) % 4 , for clockwise
    left turn  : dir = (dir + 3) % 4 , for anti-clockwise
*/


int dx[]={-1,0,1,0};int dy[]={0,1,0,-1};

void solve() {
    int h,w,n;cin>>h>>w>>n;
    vii v(h,vi(w,"."));
    int x=0,y=0,m=0;
    for (int _ = 0; _ < n; _++)
    {
        if(v[x][y]=="."){
            v[x][y]="#";
            m++;
        }else{
            v[x][y]=".";
            m+=3;
        }
        m%=4;
        x+=dx[m];y+=dy[m];
        if(x<h) x+=h;
        if(x>=h) x-=h;
        if(y<w) y+=w;
        if(y>=w) y-=w;
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout<<v[i][j];
        }
        cout<<endl;
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