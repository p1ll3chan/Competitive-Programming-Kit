#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
using namespace std;

#define int long long int
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

// keyword for Knowledge : Order-independent recursive decomposition

/*
Problem  : You have n as input, follow an operation will there are no value greater than 2 in the array.
           Operation to follow : 
           * take value n and replace it will ceil(n/2) & floor(n/2).
           * Continue till there no value to process further.
        
           Contraint goes till 10^17
*/

/*
Example Process
Let’s trace f(5) VERY slowly
First call
        f(5)
Operation on 5:
        5 -> 2, 3
Cost paid NOW:
        +5
So:

                        f(5)=5+f(2)+f(3)
Now solve f(2)  Operation:
        2 -> 1,1
Cost paid: +2
So:                     f(2)=2+f(1)+f(1)
But: f(1)=0

because no operation is possible on 1.
Therefore:

                        f(2)=2
Now solve f(3) Operation:
    3 -> 1,2
Cost paid: +3

So:                     f(3)=3+f(1)+f(2)
We already know:
                        f(1)=0
and
                        f(2)=2
Therefore:
                        f(3)=3+0+2=5
Now return to f(5)
                        f(5)=5+f(2)+f(3)
Substitute values:
                        f(5)=5+2+5  -> Final answer:  12
*/


/*
Why is n added every time? -> f(n)=n+f(⌊n/2⌋)+f(⌈n/2⌉)
When you choose a number x:

    You pay x yen

    Then x splits into: ceil(x/2) & floor(x/2)

    So if:                  f(n)=total cost starting from n

then the total cost has 3 parts:

the cost paid now → n
the future cost from left child
the future cost from right child

*/
map<int,int> dp;
int solve(int n) {
    if(n==1)return 0;
    // Memoization Part
    if(dp.count(n)) return dp[n]; // This is to avoid Recompution,if during the precess we 
                                  // came across the same value,[to reduce the opertion count]
                                  // “Solve once, store forever, reuse later.”
                                  // This one calls the previous stored value back and applies instead if one more recurrsion
    int flr=(n+1)/2,cel=n/2;
    //the DP Part
    return dp[n]=n+solve(flr)+solve(cel); // we solve this end of the dp[0] and 
                                          // we take up the solved values to the previously unsolved part to get the final value
                                          // the solving if happing deep down.

}

// void test() {
//     int t;
//     cin >> t;
//     while (t--) solve();
// }

int32_t main() {
    fastio();
    // test();
    int n;cin>>n;
    cout<<solve(n)<<endl;
    return 0;
}