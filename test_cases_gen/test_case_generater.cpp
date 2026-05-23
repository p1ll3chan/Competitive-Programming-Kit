#include <bits/stdc++.h>
using namespace std;

int main() {

    int N = 300000;
    int Q = 300000;

    cout << N << " " << Q << "\n";

    // First half: updates
    for(int i = 1; i <= 150000; i++) {
        cout << 1 << " " << ((i % N) + 1) << "\n";
    }

    // Second half: queries
    for(int i = 1; i <= 150000; i++) {
        cout << 2 << " " << (i % 300000 + 1) << "\n";
    }

    return 0;
}
