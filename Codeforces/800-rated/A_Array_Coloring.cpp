#include <bits/stdc++.h>

using namespace std;
// problem asked for a parity check of sum between grouping of two coloring sub arrays Red and Blue
// That means the both the sum if added up will be a Parity if else that is a Even number this possible in Whole Number case.
// So check if the Sum is even or not
int main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        int sum=0;
        vector<int> arr(N);
        for (int i = 0; i < N; i++)
        {
            cin>>arr[i];
            sum+=arr[i];
        }
        
        if(sum%2==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}