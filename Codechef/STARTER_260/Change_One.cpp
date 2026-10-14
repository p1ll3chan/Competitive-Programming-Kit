#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int> V(N);
        for(int i=0;i<N;i++) cin>>V[i];
        if(N==2){
            cout<<0<<endl;
        }else{
            int min_val=100;
            for (int i = 0; i < N-1; i++)
            {
                if(abs(V[i]-V[i+1])<min_val) min_val=abs(V[i]-V[i+1]);
            }
            cout<<min_val<<endl;
        }
    }
}