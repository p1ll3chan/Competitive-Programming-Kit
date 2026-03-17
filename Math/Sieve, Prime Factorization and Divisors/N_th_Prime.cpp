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
    Problem Statement : print the n-th prime number.

    Solution : Sieve of Eratosthenes list generation 
*/


void solve(){
    int n;cin>>n;
    int limit = 8000000;  // when n =  5x10^5 there are 41500 prime value so for safe check in large n = 8000000,
                          // because primte value count will to upto 56,0000
    vector<bool> prime(limit+1,true);
    prime[0]=prime[1]=false;

    for (int i = 2; i*i <= limit; i++)
    {
        if(prime[i]){
            for (int j = i*i; j <= limit; j+=i)
            {
                prime[j]=false;             // This is the the "Prime Excecution Method" we are intially giving 'true' to all then for all the multiples of i except i will be 'false'.
                                            // this why we can generate the prime count of the number under O(sqrt(n))
            }
        }
    }

    vi v;
    for (int i = 2; i <= limit; i++)
    {
        if(prime[i]) v.pb(i);
    }
    
    cout<<v[n-1]<<endl;
    
    
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