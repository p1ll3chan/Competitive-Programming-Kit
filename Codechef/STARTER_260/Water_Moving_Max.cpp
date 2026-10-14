#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int N,K;cin>>N>>K;
        vector<int> V(N);
        for(int i=0;i<N;i++) cin>>V[i];
        sort(V.rbegin(),V.rend());
        if(K>N) K=N-1;
        //cout<<K<<" "<<N<<endl;
        int max_val=0;
        for (int i = 0; i <= K; i++)
        {
            max_val+=V[i];
        }
        
        cout<<max_val<<endl;
    }
}