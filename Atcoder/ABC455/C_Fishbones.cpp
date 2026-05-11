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
#define YESNO(x) cout << ((x) ? "Yes" : "No") << endl
#define debug(x) cerr << #x << " = " << (x) << endl;
#define debugArr(arr) for (auto v : arr) cerr << v << " "; cerr << endl;
#define readVec(v, n) for (int i = 0; i < n; ++i) cin >> v[i];
#define readMatrix(mat, n, m) for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> mat[i][j];
#define printVec(v) for (auto x : v) cout << x << " "; cout << endl;
#define printMatrix(mat) for (auto r : mat) { printVec(r); }
#define fp(i, a, b) for (int i = (a); i < (b); ++i)

/*
Problem:

You have:

one spine string of length N
    for each position i:
    choose some string with:
    length = A[i]
    character at position B[i]
and that character must equal spine[i]

That’s all.

like for the exmaple

55 35 24 15 13 28retrochrisitchytunacrabrockcodash

Extract which all words from Ai & Bi where 0<=i<=n

5 3 -> t,r,c
5 2 -> e,h,t
4 1 -> t,c,r
5 1 -> r,c,i
3 2 -> o,s

Check which all words from m words can formed by each arrangment given in order as abovelike ,

    chris 			5 3
     retro			5 2
      tuna			4 1
      retro			5 1
     cod			3 2

for 'retro' and

itchy			5 3
 chris			5 2
  rock			4 1
  itchy			5 1
 ash			3 2

for 'chris'.

check inorder Yes/NO

*/



bool rightone(string s,vector<int>& v){
    //map<char,int> mp;
    vector<int> make(26,0);
    //for(auto c : v) mp[c]++;
    // for(auto c : s){
    //     if(mp[c]==0) return false;
    //     mp[c]--;
    // }
    for(auto c : s)make[c-'a']++;
    for (int i = 0; i < 26; i++)
    {
        if(make[i] > v[i]) return false;
    }
    
    return true;
}

void initial_solve() {
    int n;
    cin >> n;
    vector<pair<int,int>> freq;
    for (int i = 0; i < n; i++)
    {
        int a,b;cin>>a>>b;
        freq.pb({a,b});
    }
    int m;cin>>m;
    vector<string> v;
    for (int i = 0; i < m; i++)
    {
        string s;cin>>s;
        v.pb(s);
    }
    //vector<char> take;
    vector<int> take(26,0);
    for (int i = 0; i < freq.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if(v[j].size()==freq[i].first && freq[i].second - 1 < v[j].size()){
                //take.pb(v[j][freq[i].second-1]);
                char x=v[j][freq[i].second-1];
                take[x-'a']++;
            }
        }
    }
    //printVec(take);
    for (int i = 0; i < m; i++)
    {
        if(rightone(v[i],take))YES;
        else NO;
    }

}

/*
4️⃣ My mistake analysis (from my code)

Your main mistake was misidentifying the invariant.

❌ Core logical deviation

You reduced the problem into:

Can the word be formed from collected characters?

using:

map<char,int>

That converts the problem into frequency matching.

But the actual condition is:

position i of spine
↔
specific rib constraint (Ai, Bi)

You completely lost:

positional dependency,
length dependency,
per-index checking.

❌ Major implementation bug

You declared:

vector<pair<int,int>> freq(n);

Then later:

freq.pb({a,b});

This doubles the size accidentally.

You already initialized size n.

So:

first n entries are garbage/default,
next n entries are actual input.

Classic vector misuse.

❌ Another conceptual issue

This function:

bool rightone(string s, vector<char>& v)

checks whether characters exist globally.

But suppose:

Position 1 requires:
(length=5, pos=3)

and only 't' is possible there.

Your code allows any 't' anywhere in the word.

That ignores:

index,
rib relation,
ordering.
Category of mistakes

Mainly:

Logical modeling mistake
Some implementation carelessness
Mild overthinking

Not an edge-case issue.
*/
// --------------------------------------------

/*
The Correct Approch

The BIG lesson you should learn

Your original intuition focused on:

“How do I form the whole word?”

But stronger contestants ask:

“What exact condition does ONE position need?”

This shift:

from global construction
→ local feasibility

is one of the biggest jumps from beginner → Pupil.

Contest heuristic to remember

When you see:

repeated existence checks
small alphabets
independent positions

immediately think:

Precompute feasibility table
*/

int length=10;
int alpha=26;

int n;
vi a,b;
int m;
vector<string> s;



void solve(){
    int catcher[length+1][length][alpha];
    for (int i = 0; i <= length; i++)
    {
        for (int j = 0; j < length; j++)
        {
            for (int k = 0; k < alpha; k++)
            {
                catcher[i][j][k]=0;
            }
            
        }
        
    }

    for (int i = 0; i < m; i++)
    {
        int nextt=s[i].size();
        for (int j = 0; j < nextt; j++)
        {
            catcher[nextt][j][s[i][j]-'a']=1;
        }
        
    }
    
    vi box(m,0);

    for (int i = 0; i < m; i++)
    {
        int sz=s[i].size();
        if(sz!=n){
            continue;
        }
        bool skibidi=true;
        for (int j = 0; j < n; j++)
        {
            if( catcher[a[j]][b[j]-1][s[i][j]-'a']==0) skibidi=false;
        }
        if(skibidi) box[i]=1;
        
    }
    
    for (int i = 0; i < m; i++)
    {
        YESNO(box[i]);
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
    cin>>n;
    a.resize(n),b.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin>>a[i]>>b[i];

    }
    cin>>m;
    s.resize(m);
    for (int i = 0; i < m; i++)
    {
        cin>>s[i];
    }
    
    
    solve();
    return 0;
}