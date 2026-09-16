#include <bits/stdc++.h>
#define debug(x) cout<<(x)<<endl;
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int> V;
        int cnt_0=0,cnt_1=0,cnt_2=0,cnt_3=0;
        for (int i = 0; i < N; i++)
        {
            int red=i%4;
            if(red==0) cnt_0++;
            if(red==1) cnt_1++;
            if(red==2) cnt_2++;
            if(red==3) cnt_3++;
        }
// The only residue to satisfy (x+y)%4==3 is 0,1,2,3
// just check the cnt adding possiblity up to 4 here and if evenly found Bob else Alice
        if((cnt_0 == cnt_3) && (cnt_1 == cnt_2)) cout<<"Bob"<<endl;
        else cout<<"Alice"<<endl;
        
    }
    return 0;
}

        
/*
The relation comes from writing

$$ N = 4q + r,\qquad 0\le r<4. $$

The numbers on the board are

$$ 0,1,2,\dots,N-1. $$

Every complete block of four consecutive numbers,

$$ 4k,\ 4k+1,\ 4k+2,\ 4k+3, $$

has residues

$$ 0,1,2,3 \pmod 4 $$

exactly once each.

So if \(N=4q+r\), the first \(4q\) numbers give exactly \(q\) elements in every residue class. Then the remaining \(r\) numbers are:

$$ 4q,\ 4q+1,\ 4q+2 $$

as far as needed, whose residues are

0, 1, 2.
*/