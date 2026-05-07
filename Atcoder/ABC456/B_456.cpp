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
Problem :
You have 3 dice, which gives you 6 faces each and each face come up number from 1 to 6 
with a probabiltiy of 1/6. When these dice are rolled simultaneously, find the probability that the values 
4,5,6 each appear exactly once.
*/

/*

My Initial Intution:

After making the 2D container, i started counting the 4,5,6 occurance for each 3 dices
and stored that to find the average cnt of each 4,5,6. [ I thought in this way 
i could take the approx count to the favour of probablity of each dices]
, then i took the product of the average and divided with 36.

I failed at testcase 4 to last testcases....

*/

void inital_solve(){
    vii v(3,vi(6));
    readMatrix(v,3,6);
    
    int avg_4=0;
    int avg_5=0;
    int avg_6=0;
    for (int i = 0; i < 3; i++)
    {
        int cnt_4=0;
        int cnt_5=0;
        int cnt_6=0;
        for (int j = 0; j < 6; j++)
        {
            if(v[i][j]==4) cnt_4++;
            if(v[i][j]==5) cnt_5++;
            if(v[i][j]==6) cnt_6++;
            
        }
        avg_4+=cnt_4;
        avg_5+=cnt_5;
        avg_6+=cnt_6;
        
    }
    // avg_4/3;
    // avg_5/3;
    // avg_6/3;
    double ans=avg_4/3*avg_5/3*avg_6/3;
    //debug(ans);
    cout<<fixed<<setprecision(10)<<ans/36<<endl;
    
    // cout<<avg_4/3<<endl;
    // cout<<avg_5/3<<endl;
    // cout<<avg_6/3<<endl;
    //printMatrix(v)
}

/*
The editorial solution:

## 1️⃣ Problem classification (1–2 lines)

**Type:** Probability + Brute Force Enumeration (Counting)

**Why it matters:**
When constraints are tiny (here: (6^3 = 216)), *counting outcomes directly* is almost always safer than trying to derive probability formulas.

---

## 2️⃣ Contest-time thinking (VERY IMPORTANT)

### What a 1200-rated player should notice in 5 minutes:

* Each die has only **6 faces → total outcomes = 6 × 6 × 6 = 216**
* That’s **small enough to brute force ALL outcomes**
* The condition is simple: **values {4,5,6} appear exactly once**

👉 Immediate thought:

> “Just iterate all triples and count valid ones.”

---

### What a sub-900 player (your path) does:

* Starts thinking in terms of **averages / probabilities per die**
* Tries to **combine probabilities multiplicatively**
* Assumes independence incorrectly

👉 This leads to:

* Mixing expectation with probability
* Losing the “exactly once” constraint
* Ignoring permutations (very important here)

---

## 3️⃣ Core idea distilled (≤3 bullet points)

* Treat each roll as **one outcome in 216 equally likely cases**
* Count how many outcomes contain **exactly one 4, one 5, one 6**
* Divide by total outcomes

👉 Mental sentence:

> “When outcomes are small, count favorable cases directly instead of approximating probability.”

---

## 4️⃣ My mistake analysis (from my code)

### ❌ Main issue: **Conceptual / Logical mistake**

You did:

```cpp
avg_4/3 * avg_5/3 * avg_6/3
```

This assumes:

* Independence between dice ✔️ (partially true)
* BUT also assumes:

  * Events “getting 4”, “getting 5”, “getting 6” are independent **across dice positions** ❌
  * Ignores that **each must appear exactly once**

---

### ❌ Deeper mistake: **Expectation ≠ Probability**

You computed:

* Average count of 4,5,6 across dice

But:

* That gives expected frequency, not probability of a **specific configuration**

👉 Example flaw:
You are not ensuring:

* One die gives 4
* Another gives 5
* Another gives 6

Instead, you allow:

* Same die contributing multiple counts in expectation

---

### ❌ Missing permutations insight

Valid cases include:

* (4,5,6), (4,6,5), (5,4,6), ...

You didn’t account for:
👉 **6 permutations of (4,5,6)**

---

### Verdict:

* ❌ Logical mistake
* ❌ Overthinking
* ❌ Wrong modeling of probability

---

## 5️⃣ How a Pupil should improve (actionable)

### Rule 1:

> When total outcomes ≤ (10^6), ALWAYS consider brute force counting first.

---

### Rule 2:

> In probability problems, NEVER mix “average/expectation” with “exact event probability”.

---

### Rule 3:

> If the problem says “exactly once”, think:

* permutations
* assignments
* not independent multiplication

---

## 6️⃣ Pattern memory tag

**Pattern name:**
👉 *“Small-state probability enumeration”*

**When to recall:**

* Dice / cards / small ranges
* Total outcomes ≤ few million
* “Exactly k times” conditions

---

## 7️⃣ Final takeaway (1 line)

> When the sample space is small, count exact valid outcomes instead of trying to approximate probability using averages.

*/

void solve() {
    vii v(3,vi(6));
    readMatrix(v,3,6);
    double cnt=0;
    for (int i = 0; i < 6; i++)
    {
        for (int j = 0; j < 6; j++)
        {
            for (int k = 0; k < 6; k++)
            {
                if((v[0][i]==4 && v[1][j]==5 && v[2][k]==6)
                 ||(v[0][i]==6 && v[1][j]==5 && v[2][k]==4)
                 ||(v[0][i]==4 && v[1][j]==6 && v[2][k]==5)
                 ||(v[0][i]==5 && v[1][j]==4 && v[2][k]==6)
                 ||(v[0][i]==6 && v[1][j]==4 && v[2][k]==5)
                 ||(v[0][i]==5 && v[1][j]==6 && v[2][k]==4)){
                    cnt++;
                 }
            }
            }
            
        }
        
    cout<<fixed<<setprecision(10)<<cnt/216<<endl;
    
}

void test() {
    int t;
    cin >> t;
    while (t--) solve();
}

int32_t main() {
    fastio();
    // test();
    //inital_solve()
    solve();
    return 0;
}