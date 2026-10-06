#include <bits/stdc++.h>

using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        long long N;cin>>N;
        if(!((N&(N-1))==0)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        }
    return 0;
}

/*
To find the x that is odd and divisible to N, we know every even value can have a odd divisible to it, but not for 2^N guys
Those are the OG values in the field so check that
*/