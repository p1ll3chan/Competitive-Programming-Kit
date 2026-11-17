#include <bits/stdc++.h>
using namespace std;
#pragma GCC optimize("Ofast")

#define int long long
#define all(x) (x).begin(), (x).end()
#define endl "\n"
#define sz(x) (int)((x).size())
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
Problem: Give the YES/NO check if possible to generate exact K cells 
         with escape route and rest no route to exit.

My Intuition:   My concetration was on the boarder grid, thought that 
                only those are the enterence path. Mislead


Approach 1: Mislead idea; count of boarder enterence => [(n*n)-(n-2)*(n-2)], possible loop formation
            [R D] , [D L]
            [U L]   [R U]
Why Failed: Loop possitioning and assign U as the escape route.

Approach 2: Every cell is an starting cell, so assign U as first K cells, assign Bottom-Right as the R
            , assign S[N-1][i] to S[N-1][N-2] as R and rest cell as D

            Reason: We target the S[N-1][N-2] as the permanent loop closer directed by both R's,L and D's

Example Process:
YES
UUU
UUD
RRL

Final Learning: Always have open mind logic and one target closer for 1100 rated problem with construction type

------
*/

void solve() {
    int N,K;cin>>N>>K;
    if(N*N-1==K){
        cout<<"NO"<<endl;
    }else{
        cout<<"YES"<<endl;
        string s="";
        for (int i = 0; i < N; i++)
        {
            
            for (int j = 0; j < N; j++)
            {
                if(K>0){
                    s+='U';
                    K-=1;
                }else if(i==N-1 && j==N-1){
                    s+='L';
                }else if(i==N-1){
                    s+='R';
                }else{
                    s+='D';
                }
            }
            
        }
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                cout << s[i * N + j];
            }
            cout << endl;
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
    test();
    //solve();
    return 0;
}