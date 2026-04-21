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

What is the problem saying?
* There are N boxes for sale and each boxes has from 1 to N has a price of Ai and there Ai piece of candy inside. [C.T = Thus each candy cost 1/cc]
* Guy will buy only M Boxes out of N [ M < N ], for M number of people.
* Condition is that each person of M will gives boxes of atleast Bi piece of candy.
* If it possible to buy M boxes , then what is the minimum cost needed to pay for the guy.

What is my intution to say?
Try 1: I see we need do determine if it is possible to buy M boxes then what we can do is that,
        and the Ai >= Bi, to do so, if is possible to use the minimum cost box to buy if the Ai corresponding to the Bi is lesser.
        Found that in the third sample testcase. So 
    * I will needed to sort the array, espacially the N-sized [A].
    * summation the value of the Ai>=Bi ,if on of the boxes if against the condition then summation the next lastest value of it to cover the box price.
    * 
*/

void solve1() {
    int n,m;
    cin >> n >> m;
    vi A(n),B(m);
    readVec(A, n);
    readVec(B, m);
    sort(all(A));
    int H=0,W=n;
    int i=0;
    queue<int> q;
    for (int i = 0; i < m; i++)
    {
        q.push(B[i]);
    }
    int sum=0;
    
    while(!q.empty()){
        for (int i = 0; i < n; i++)
        {
            if(q.front()<=A[i]){
                q.pop();
                sum+=A[i];
            }
            if(i==n-1) break;
        }
    }
    cout<<sum<<endl;
    // printVec(A);
    // printVec(B);
    // Your logic here
}

void solve(){
    int n,m;
    cin >> n >> m;
    vi A(n),B(m);
    readVec(A, n);
    readVec(B, m);
    sort(all(A));
    sort(all(B));
    int i=0,j=0;
    int sum=0;
    while(i<n && j<m){
        if(A[i]>=B[j]){
            sum+=A[i];
            i++;
            j++;
        }else{
            i++;
        }
    }
    if(j<m) cout<<-1<<endl;
    else cout<<sum<<endl;
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