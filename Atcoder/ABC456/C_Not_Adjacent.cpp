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
Problem Statement: 
You are given a string S consisting of a, b, c.

Find the number of non-empty substrings of 
S in which no two adjacent characters are the same, modulo 998244353.

Two substrings are considered distinct if they are taken from different positions, even if they are identical as strings.

*/

/*
Initail Intution:

I was blank actually, wasn't sure how to approch with the hidius contraint there. Thought of counting the the a,b,c then think about that later.
But Naaaaaah.

*/
void inital_solve() {
    string s;cin>>s;
    int cnt_a=0;
    int cnt_b=0;
    int cnt_c=0;
    for (int i = 0; i < s.size(); i++)
    {
        if(s[i]=='a') cnt_a++;
        if(s[i]=='b') cnt_b++;
        if(s[i]=='c') cnt_c++;
    }
    debug(cnt_a);
    debug(cnt_b);
    debug(cnt_c);
}

/*
Editorial Solution 1:

## 1️⃣ Problem classification (1–2 lines)

**Type:** Counting + Implementation

**Why it matters:**
In contests, substring counting problems often reduce to **counting valid segments instead of enumerating substrings**, which avoids (O(n^2)).

---

## 2️⃣ Contest-time thinking (VERY IMPORTANT)

### What a 1200-rated player should notice in 5 minutes:

* Total substrings = ( \frac{n(n+1)}{2} )
* Condition: **no two adjacent characters are equal**
* This is a **local constraint → only depends on adjacent pairs**

👉 Key realization:

> “Invalidity happens exactly at positions where (s[i] == s[i+1]).”

So instead of thinking about substrings:
👉 Think about **splitting the string at bad positions**

---

### What a sub-900 player is likely to do:

* Try to:

  * Generate all substrings (O(n²)) ❌
  * Check each substring for validity ❌
* Or try:

  * DP with states on substrings ❌ (overkill)
  * Sliding window with complicated resets ❌

👉 These approaches miss the core simplification:
You don’t need substrings — you need **continuous valid blocks**

---

## 3️⃣ Core idea distilled (≤3 bullet points)

* A substring is valid **iff it lies entirely inside a segment where all adjacent chars differ**
* Split the string at positions where (s[i] == s[i+1])
* For each segment of length (L), contribution = ( \frac{L(L+1)}{2} )

👉 Mental sentence:

> “Break at equal adjacents, count all substrings inside each clean segment.”

---

## 4️⃣ My mistake analysis (from my code)

You didn’t provide your code here, so I’ll infer the **likely mistakes based on this problem pattern**.

### Common mistakes (be honest if you did any):

---

### ❌ Mistake 1: Overthinking with substring generation

* Trying nested loops for substrings
* Checking each substring manually

👉 Type: **Overthinking + Inefficiency**

---

### ❌ Mistake 2: Using sliding window incorrectly

* Resetting window on equality
* But miscounting number of substrings

👉 Typical bug:
You count only window length, not total substrings inside it

---

### ❌ Mistake 3: Missing segmentation idea

* Treating whole string as one structure
* Not splitting at (s[i] == s[i+1])

👉 Type: **Logical gap**

---

### ❌ Mistake 4: Modulo misuse

* Applying modulo inside division incorrectly
* Or using int instead of long long

👉 Type: **Implementation detail**

---

If your code failed, it’s almost certainly because:

> You didn’t reduce the problem to **independent segments**

---

## 5️⃣ How a Pupil should improve (actionable)

### Rule 1:

> When a condition depends only on adjacent elements, always try **splitting the array/string into independent blocks**

---

### Rule 2:

> If counting substrings, first ask:
> “Can I count per segment instead of per substring?”

---

### Rule 3:

> Memorize this formula:
> Number of substrings in length (L) = ( \frac{L(L+1)}{2} )

You should instantly recognize when to use it.

---

## 6️⃣ Pattern memory tag

**Pattern name:**
👉 *“Segment split substring counting”*

**When to recall:**

* Problems with constraints like:

  * “no adjacent equal”
  * “strictly increasing”
  * “no duplicates in neighbors”
* Whenever validity is **locally broken**

---

## 7️⃣ Final takeaway (1 line)

> When substring validity breaks locally, split into valid segments and count each segment independently.


*/

/*
Core formula Used:

Segment length Calculation : (i - start_index + 1)
Counting substrings in a segment : ((len) * (len + 1)) / 2
*/

/*
Notes:

“I walk through the string, and every time I hit equal adjacent characters,
 I cut the segment and count all substrings inside the previous clean segment.”

*/

void solve1(){
    string s;cin>>s;
    int ans=0;
    int start_index=0;
    for (int i = 0; i < s.size(); i++)
    {
        if(i+1==s.size() || s[i]==s[i+1]){
            ans+=(int) ((i-start_index+1) * (i-start_index+2))/2;   // we are taking summation of integer count sum [(n*(n+1))/2] of each segment in the string accordingly.
            start_index = i + 1; // Here we going to the next segement to count the next substring.
        }
    }
    cout<<ans%998244353<<endl;
}

/*
Editorial Solution 2 :
This solution was implementationi smartness!!

Instead of manually scanning and splitting like your C++ code, it:

Inserts commas at every “bad position” (where adjacent chars are equal), then splits the string into valid segments.

After that:

Each segment is already valid
So we just apply L(L+1)/
*/

void solve2(){
    string s;cin>>s;
    string t="";
    for (int i = 0; i < s.size(); i++)
    {
        t+=s[i];
        if(i+1 < s.size() && s[i]==s[i+1]){ // According the condition we are adding the comma for indentifying the segemtn to break
            t+=',';
        }
    }
    
    vector<string> segments; // This is were we will input each segement to action up
    string cur = ""; 

    for (char c : t) {
        if (c == ',') {
            segments.push_back(cur);
            cur = "";
        } else {
            cur += c;
        }
    }

    if (!cur.empty()) segments.push_back(cur);
    // printVec(segments);
    // debug(cur);
    long long ans = 0;

    for (auto &seg : segments) {
        long long L = seg.size();
        ans += (L * (L + 1)) / 2;
    }

    cout << ans % 998244353 << endl;
    
    //cout<<t<<endl;


    
}

void test() {
    int t;
    cin >> t;
    while (t--) solve1();
}

int32_t main() 
{
    fastio();
    // test();
    //solve1();
    solve2();
    return 0;
}