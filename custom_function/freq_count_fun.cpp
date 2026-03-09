#include <bits/stdc++.h>
using namespace std;

// Count frequency of digits in an integer (0-9)
array<int, 10> digitFrequency(long long n) {
    array<int, 10> count{};                // stores count of digits 0-9
    while (n > 0) {                        // loop until all digits processed
        int digit = n % 10;                // extract last digit
        count[digit]++;                    // increment frequency of this digit
        n /= 10;                           // remove last digit
    }
    return count;                          // return digit frequencies
}

// Count frequency of each integer in an array
vector<int> integerFrequency(const vector<int>& v, int maxValue) {
    vector<int> freq(maxValue + 1, 0);     // initialize frequency array
    for (int num : v) {                    // loop through all elements
        if (num <= maxValue) freq[num]++;  // increment freq for valid numbers
    }
    return freq;                           // return frequency array
}

// Count number of pairs for each value (freq / 2)
int countPairsFromFrequency(const vector<int>& freq) {
    int pairs = 0;
    for (int f : freq) {                   // loop through each frequency
        pairs += f / 2;                    // add number of pairs from freq
    }
    return pairs;                          // return total pairs
}

// Count occurrences of a number using binary search (sorted array)
int countOccurrencesSorted(const vector<int>& v, int x) {
    return upper_bound(v.begin(), v.end(), x) // first element greater than x
         - lower_bound(v.begin(), v.end(), x); // first element equal to x
}

// Most frequent integer in array
int mostFrequentElement(const vector<int>& v) {
    unordered_map<int, int> freq;          // map to store freq of each int
    for (int num : v) freq[num]++;         // count frequency of each integer
    
    int maxCount = 0, mostFrequent = v[0];
    for (auto& [num, count] : freq) {      // iterate over all map entries
        if (count > maxCount) {            // check if higher freq found
            maxCount = count;              // update max frequency
            mostFrequent = num;            // update most frequent number
        }
    }
    return mostFrequent;                   // return most frequent integer
}

// Most frequent string in array
string mostFrequentString(const vector<string>& v) {
    unordered_map<string, int> freq;       // map to store freq of each string
    for (auto& s : v) freq[s]++;           // count frequency of each string
    
    int maxCount = 0;
    string mostFrequent;
    for (auto& [str, count] : freq) {      // iterate over all map entries
        if (count > maxCount) {            // check if higher freq found
            maxCount = count;              // update max frequency
            mostFrequent = str;            // update most frequent string
        }
    }
    return mostFrequent;                   // return most frequent string
}

