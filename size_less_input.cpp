// Convert integer to vector of its digits (no need to know size beforehand)
vector<int> getDigits(int n) {
    vector<int> digits;                     // store digits of the number
    string s = to_string(n);                // convert integer to string
    for (char c : s) {                      // iterate over each character
        digits.push_back(c - '0');          // convert char to int and store
    }
    return digits;                          // return vector of digits
}

// Convert string to vector of single-character strings
vector<string> getStrings(const string& v) {
    vector<string> result;                  // store single-character strings
    for (int i = 0; i < (int)v.size(); ++i) { // iterate over each character
        result.push_back(string(1, v[i]));  // convert char to string and store
    }
    return result;                          // return vector of strings
}
