#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int> V(N);
        int Even_cnt=0,Odd_cnt=0;
        for (int i = 0; i < N; i++)
        {
            cin>>V[i];
        }

        vector<int> V_sort=V;
        sort(V.begin(),V.end());
        int N0_check=0;
        for (int i = 0; i < N; i++)
        {
            if((V[i]%2==0 && V_sort[i]%2!=0) || (V_sort[i]%2==0 && V[i]%2!=0)) N0_check++;
        }
        if(N0_check!=0) cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
        
        
    }
    return 0;
}