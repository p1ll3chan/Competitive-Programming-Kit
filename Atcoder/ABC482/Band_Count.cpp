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
    int h,w,n,q;cin>>h>>w>>n>>q;
    //vector<vector<int>> matrx(h,vector<int> (w),0);

    map<int,int> row, col;

    //vector<pair<int,int>> grid;
    for (int i = 0; i < n; i++)
    {
        int r,c;cin>>r>>c;
        row[r]++;
        col[c]++;
    }
    

    vi R, RP;
    vi C, CP;

    int sum = 0;
    for(auto [x, cnt] : row) {
        R.push_back(x);
        sum += cnt;
        RP.push_back(sum);
    }
    sum = 0;
    for(auto [x, cnt] : col) {
        C.push_back(x);
        sum += cnt;
        CP.push_back(sum);
    }

    for (int i = 0; i < q; i++)
    {
        int x;cin>>x;
        if(x==1){
            int u,d;cin>>u>>d;
            int one=lower_bound(R.begin(),R.end(),u)-R.begin();
            int sec=upper_bound(R.begin(),R.end(),d)-R.begin();
            //cout<<matrx[u][d]<<endl;
            //cout<<prefrow[d]-prefrow[u-1]<<endl;

            int sum=0;
            if(one>0) sum-=RP[one-1];
            if(sec>0) sum+=RP[sec-1];

            cout<<sum<<endl;
       }else{
            int l,r;cin>>l>>r;
            //cout<<matrx[l][r]<<endl;
            //cout<<prefcol[r]-prefcol[l-1]<<endl;
            int one=lower_bound(C.begin(),C.end(),l)-C.begin();
            int sec=upper_bound(C.begin(),C.end(),r)-C.begin();
            //cout<<matrx[u][d]<<endl;
            //cout<<prefrow[d]-prefrow[u-1]<<endl;

            int sum=0;
            if(one>0) sum-=CP[one-1];
            if(sec>0) sum+=CP[sec-1];

            cout<<sum<<endl;
        }

    }
    
}

void pre_solve(){
    int h,w,n,q;cin>>h>>w>>n>>q;
    //vector<vector<int>> matrx(h,vector<int> (w),0);
    vector<int> row(h+1,0);
    vector<int> col(w+1,0);


    //vector<pair<int,int>> grid;
    for (int i = 0; i < n; i++)
    {
        int r,c;cin>>r>>c;
        row[r]++;
        col[c]++;
    }

    vector<int> prefrow(h+1,0);
    vector<int> prefcol(w+1,0);
    
    // for(auto &[x,y] : grid){
    //     matrx[x][y]++;
    // }

    for (int i = 1; i <= h; i++)
    {
        prefrow[i]=prefrow[i-1]+row[i];
    }

    for (int i = 1; i <= w; i++)
    {
        prefcol[i]=prefcol[i-1]+col[i];
    }
    

    for (int i = 0; i < q; i++)
    {
        int x;cin>>x;
        if(x==1){
            int u,d;cin>>u>>d;
            //cout<<matrx[u][d]<<endl;
            cout<<prefrow[d]-prefrow[u-1]<<endl;
        }else{
            int l,r;cin>>l>>r;
            //cout<<matrx[l][r]<<endl;
            cout<<prefcol[r]-prefcol[l-1]<<endl;
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