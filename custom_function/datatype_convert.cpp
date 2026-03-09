// Convert integer to vector of digits
vector<int> intToVector(int num) {
    vector<int> v;                          // stores digits of the number
    while (num > 0) {                       // loop until all digits processed
        v.push_back(num % 10);              // extract last digit and store
        num /= 10;                          // remove last digit
    }
    reverse(v.begin(), v.end());            // reverse to maintain original order
    return v;                               // return vector of digits
}

// Convert vector of digits to integer
int vectorToInt(const vector<int>& v) {
    int result = 0;                         // final integer result
    for (int i = 0; i < (int)v.size(); i++) { // iterate over each digit
        result = result * 10 + v[i];        // shift left (×10) and add digit
    }
    return result;                          // return the integer formed
}
