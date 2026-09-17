#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int> V(N);
        for (int i = 0; i < N; i++)
        {
            cin>>V[i];
        }
        int two_cnt=0;
        int left_cnt=0;
        for (int i = 0; i < N; i++)
        {
            if(V[i]==2) two_cnt++;
        }
        int ans=-1;
        for (int i = 0; i < N; i++)
        {
            if(V[i]==2){
                left_cnt++;
                
            }
            if(left_cnt == two_cnt - left_cnt){
                    ans=i+1;
                    break;
            }
        }
        cout<<ans<<endl;
        //}
    }
}