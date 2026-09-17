#include <bits/stdc++.h>
using namespace std;

int main(){
    int T;cin>>T;
    while(T--){
        int A,B,X,Y;cin>>A>>B>>X>>Y;
        int ans=0;
        if(A==B){
            ans=0;
        }
        else if(A<B){
            
                int d=B-A;
                if(A%2==0){
                    ans=((d+1)/2)*min(X,Y) +(d/2)*X;
                }else{
                    ans=(d/2)*min(X,Y) + ((d+1)/2)*X;
                }
            
        }else{ // done 1
            if(A%2==1 && B==A-1){
                ans=Y;
            }else{
                ans=-1;
            }
        }
        cout<<ans<<endl;
    }
}