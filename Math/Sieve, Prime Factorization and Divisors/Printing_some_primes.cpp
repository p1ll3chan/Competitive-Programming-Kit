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
const int N = 100000000;

void solve_1() {
    vector<bool> is_prime(N+1,true);
    is_prime[0]=is_prime[1]=false;
    for (int i = 2; i*i <= N; i++)
    {
        if(is_prime[i]){
            for (int j = i*i; j <= N; j+=i)
            {
                is_prime[j]=false;
            }
        }
    }
    int cnt=0;
    for (int i = 2; i <= N; i++)
    {
        if(is_prime[i]){
            cnt++;
            if(cnt%100==1){
                cout<<i<<endl;
            }
        }
    }
    
}

// First Logic for TLE

void solve(){
    bitset<N+1> p;
    p.reset();   // Now function
    for (int i = 3; i <= N; i+=2)
    {
        p[i]=1;
    }
    p[2]=1;
    for (int i = 3; i*i <= N; i+=2)
    {
        if(p[i]){
            for (int j = i*i; j <= N; j+=i*2)
            {
                p[j]=0;
            }
            
        }
    }
    int cnt=1;
    cout << 2 << '\n';

    for (int i = 3; i <= N; i+=2)
    {
        if(p[i]){
            cnt++;
            if(cnt%100==1){
                cout<<i<<endl;
            }
        }
    }  
}
    /*
    Notes:
    The logic behind '%' is not only for divisibilty check.
    '%' check can also be used as a cycle sequence check 

    like in this case
    cnt%100==0,  this represent that a sequence of 100 numbers are maintained each time. like from 1 - 100 , 101 - 200 , 201 to 302

    % 100 creates repeating blocks, and == 1 selects the first element of each block of 100 primes
    */
    


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