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
        int avg=accumulate(V.begin(),V.end(),0)/N;
        int surplus=0;
        bool poss=true;
        for (int i = 0; i < N; i++)
        {
            surplus+=V[i]-avg;
            if(surplus<0){
                poss=false;
                break;
            }
        }
        
        if(poss) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}