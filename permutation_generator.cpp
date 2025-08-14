// Generate all permutations of a given string
void permute(int index, string &s, vector<string> &ans) {
    if (index == (int)s.size()) {           // base case: reached end of string
        ans.push_back(s);                   // store the current permutation
        return;                             
    }
    for (int i = index; i < (int)s.size(); i++) { // iterate over remaining chars
        swap(s[index], s[i]);               // swap current index with i
        permute(index + 1, s, ans);          // recurse for next index
        swap(s[index], s[i]);               // backtrack (restore original order)
    }
}

// Generate all unique permutations of given integers
void permute(int index, vector<int> &nums, vector<vector<int>> &ans) {
    if (index == (int)nums.size()) {        // base case: reached end of vector
        ans.push_back(nums);                // store the current permutation
        return;
    }

    for (int i = index; i < (int)nums.size(); ++i) { // iterate over remaining numbers
        // Check for duplicates at this recursion level
        bool shouldSwap = true;             
        for (int j = index; j < i; ++j) {   // scan between 'index' and 'i'
            if (nums[j] == nums[i]) {       // duplicate found
                shouldSwap = false;         // skip swapping this duplicate
                break;
            }
        }
        if (!shouldSwap) continue;          // move to next candidate

        swap(nums[index], nums[i]);         // swap current index with i
        permute(index + 1, nums, ans);      // recurse for next index
        swap(nums[index], nums[i]);         // backtrack to restore order
    }
}
