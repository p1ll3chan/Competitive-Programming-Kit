#include <bits/stdc++.h>
#define debug(x) cout<<(x)<<endl;
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int A,B;cin>>A>>B;
        if(A%2!=0){
            cout<<"NO"<<endl;
        }
        else if(A==0 && B%2!=0){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
}