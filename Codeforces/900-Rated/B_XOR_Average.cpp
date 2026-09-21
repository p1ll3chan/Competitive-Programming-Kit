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

