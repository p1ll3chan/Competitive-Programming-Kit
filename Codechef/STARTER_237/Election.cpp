#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int hi = ((n / 2) + 1) - k;
    if(hi > 0)
        cout << hi << endl;
    else 
        cout<< 0 <<endl;
}