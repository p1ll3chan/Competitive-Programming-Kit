#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int> V(N);
        int n_one_cnt=0,sum=0;
        for (int i = 0; i < N; i++)
        {
            int x;cin>>x;
            sum+=x;
            if(x==-1) n_one_cnt++;
        }

        if(N%2==0 && n_one_cnt%2==(N/2)%2) cout<<"YES"<<endl;
        //if(abs(sum)%4==0)cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;
}