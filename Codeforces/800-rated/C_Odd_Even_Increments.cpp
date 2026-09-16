#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl;
int main(){
    int T;cin>>T;
    while(T--){
        int N;cin>>N;
        vector<int> V(N);
        for (int i = 0; i < N; i++)
        {
            cin>>V[i];
        }
        bool chek=true;
        for (int i = 0; i < N-2; i++)
        {
            if(V[i]%2!=V[i+2]%2) chek=false;
        }
        if(chek) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        
    }
    return 0;

}

/*


Observation :
The YES Statement idea; [Too Complex]

if x is Even ; x++ => Odd
and visa versa

if all value in even index is Even and odd index is Even -> OK

if all value in even index is Odd and odd index is Odd
-> OK

if all value in even index is Even and odd index is Odd
-> OK

if all value in even index is Odd and odd index is Even
-> OK

The No Statment Idea : [Easier]

If V[i] and V[i+2] are having Opposite Parity -> No
Else OK

Bool Check  [V[i]%2 != V[i+2]%2] Yes/No 
*/