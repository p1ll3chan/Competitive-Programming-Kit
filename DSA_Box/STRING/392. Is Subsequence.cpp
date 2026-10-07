#include <bits/stdc++.h>
using namespace std;

// Two pointer Approach
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int i=0;
        for (int j = 0; j < t.size(); j++)
        {
            if(i == s.length()) return true;

            else if(s[i]==t[j]){
                i++;
            }
        }
            return i==s.length();
    }
};

class Solution {
public:
    bool isSubsequence(string s, string t) {
        
    }
};

int main(){
    string s,t;cin>>s>>t;
    Solution sol;
    cout<<sol.isSubsequence(s,t);
    return 0;
}