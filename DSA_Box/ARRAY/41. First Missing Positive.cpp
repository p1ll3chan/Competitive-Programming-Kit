#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_set<int> seen;
    for (int num : nums)
        if (num >= 0) seen.insert(num);
    int mex = 1;
    while (seen.count(mex)) ++mex;
    return mex;
    }
};

/*
seen.count(mex) — returns 1 if mex is in the set, 0 otherwise:
- count == 1 → the number is present, so it's not missing → ++mex and check the next.
- count == 0 → the number is absent → loop stops, mex is the smallest missing positive.
*/

int firstMissingPositive_1(vector<int>& nums) {
        int n = nums.size();

        // Place each value i at index i-1 using cyclic sort
        for (int i = 0; i < n; i++) {
            while (nums[i] >= 1 && nums[i] <= n && nums[nums[i] - 1] != nums[i]) {
                // Swap nums[i] to its correct position
                swap(nums[i], nums[nums[i] - 1]);
            }
        }

        // Find the first position where the value doesn't match
        for (int i = 0; i < n; i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }

        // All values 1..n are present
        return n + 1;
    }
// Alternative Logic -> In-place Algorithum check
/*
The input array can serve as its own hash map. Since the answer is in [1, n+1], we only need to know which values from 1 to n are present, and the array has exactly n slots to record that.

Place each value v in [1, n] at index v-1: value 1 goes to index 0, value 2 to index 1, and so on. After this rearrangement, the answer is a single scan away: the first index i where nums[i] != i + 1 means i + 1 is missing.

The rearrangement is done with cyclic sort. For each index, repeatedly swap the current element toward its correct index, stopping when the element is out of range (negative, zero, or greater than n), already in its correct index, or its target index already holds the same value (a duplicate).

Algorithm:
For each index i from 0 to n-1:
    While nums[i] is in range [1, n] and nums[i] is not in its correct position:
        Swap nums[i] with nums[nums[i] - 1] (put it where it belongs).
Scan the array: return the first i + 1 where nums[i] != i + 1.
If all positions are correct, return n + 1.

*/


int main(){
    string s;
    getline(cin,s);
    stringstream ss(s);
    vector<int> v;
    while(ss>>s){
        v.push_back(stoi(s));
    }
    Solution Sol;
    cout<<Sol.firstMissingPositive(v)<<endl;
    return 0;
}