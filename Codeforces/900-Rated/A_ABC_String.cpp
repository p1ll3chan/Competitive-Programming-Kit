#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while(T--) {
        string S;
        cin >> S;

        bool possible = false;

        // 0 = '('
        // 1 = ')'
        //
        // a,b,c represent the mapping of A,B,C.
        for(int a = 0; a <= 1; a++) {
            for(int b = 0; b <= 1; b++) {
                for(int c = 0; c <= 1; c++) {

                    // The first character must become '('
                    if(S[0] == 'A' && a != 0) continue;
                    if(S[0] == 'B' && b != 0) continue;
                    if(S[0] == 'C' && c != 0) continue;

                    int bal = 0;
                    bool valid = true;

                    for(char ch : S) {

                        int mapping;

                        if(ch == 'A') mapping = a;
                        else if(ch == 'B') mapping = b;
                        else mapping = c;

                        if(mapping == 0)
                            bal++;
                        else
                            bal--;

                        if(bal < 0) {
                            valid = false;
                            break;
                        }
                    }

                    if(valid && bal == 0) {
                        possible = true;
                        break;
                    }
                }

                if(possible) break;
            }

            if(possible) break;
        }

        cout << (possible ? "YES" : "NO") << '\n';
    }

    return 0;
}