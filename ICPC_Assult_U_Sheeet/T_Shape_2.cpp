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
    THe goal of making, in the given 1 to j space,  we need to arrange 2 chars '*' and ' ';

    Inside the nested for loop ;
    the first for loop will arrange the spaces need to produce.
    
    Here we have an observation, 
    when loop STOP is only n, the space will be constant till a space n from the origin and when we implemenent the stars we will get a Right-Triangle of Stars
    like this
        *
        ***
        *****
        *******

    While loop STOP is n-i, Each space will grow from n-1 to 1, where space will decrase in each iteration.
    and when we implement the star at an order of odd numbers in increasing order.
    This is what we get,
           *
          ***
         *****
        ******* 


*/

void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout<<" ";
        }
        for (int k = 1; k <= (2*i)-1; k++)
            {
                cout<<"*";
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