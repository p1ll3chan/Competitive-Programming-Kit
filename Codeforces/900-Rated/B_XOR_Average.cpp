#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl;
int main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        if(N%2==0){
            if(N==2){
                cout<<1<<" "<<3<<endl;
            }else{
                cout<<1<<" "<<3;
                for (int i = 0; i < N-2; i++)
                {
                    cout<<" "<<2;
                }
                cout<<endl;
            }
        }else{
            cout<<1;
            for (int i = 0; i < N-1; i++)
            {
                cout<<" "<<1;
            }
            cout<<endl;
        }
    }
    return 0;
}

/*
The solution path was stories

First, see the pattern with first n number, (1,2,3)
you the condition works for 1,3 and think about this, it is not nessassary to output distint number right.

so next is the cheap trick , we found 2^2 =0 (^ is XOR)

so for N=even;
    XOR_sum(1,3,(count of 2)*N-2) = (1+3+[2*(N-2)])/N

for N=odd;
    XOR_sum((count of 1)*N) = (1*N)/Ns
*/

