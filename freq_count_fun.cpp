


// TO count the number of time an array
while (n > 0) {
    int digit = n % 10; // Get last digit
    count[digit]++; // Increment count for this digit
    n /= 10; // Remove last digit
}


// to count the count of unique values
solve(){
    vector<int> feq(n+1,0);
    for(int i=0;i<n;i++){
        feq[v[i]]++;
    }
    int x=0;
    for(int i=0;i<=n;i++){
        x+=feq[i]/2;
    }
   }

 //Count of a number in an array
    
 int count = upper_bound(v.begin(), v.end(), x) - lower_bound(v.begin(), v.end(), x);

//Gives out that element which give most number of frequency out of the vector<string> 
int mostFrequentElement(vector<int>& v) {
    unordered_map<int, int> freq;
    
    for (int num : v) {
        freq[num]++;
    }
    
    int maxCount = 0;
    int mostFrequent = v[0];
    
    for (const auto& entry : freq) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            mostFrequent = entry.first;
        }
    }
    
    return mostFrequent;
}

//Gives out that string which give most number of frequency out of the vector<string> 
string mostFrequentString(vector<string>& v) {
    unordered_map<string, int> freq;
    
    // *Count frequency of each string
    for (const string& s : v) {
        freq[s]++;
    }
    
    int maxCount = 0;
    string mostFrequent;
    
    // *Find the string with the highest frequency
    for (const auto& entry : freq) {
        if (entry.second > maxCount) {
            maxCount = entry.second;
            mostFrequent = entry.first;  // *Update with the string having the highest frequency
        }
    }
    
    return mostFrequent;
}
