#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl;
int main(){
    int B,K;cin>>B>>K;
    string SS;
    vector<int> V;
    cin.ignore();
    getline(cin,SS);
    stringstream ss(SS);
    int num;
    while(ss>>num){ V.push_back(num);}
    int sum=0;
    for (int i = 0; i < K; i++)
    {
        sum+=V[i];
    }
    
    if(B%2==0){
        if(V[V.size()-1]%2==0) cout<<"even"<<endl;     
        else cout<<"odd"<<endl;

    }else{
        if(sum%2==0) cout<<"even"<<endl;
        else cout<<"odd"<<endl;

    }
    
    return 0;
}

/*
Here the B determines the partity of the order in summation
WE know ;
N = B^K * ((a1 / B^1) + (a2 / B^2) +....+ (a k-1/ B^(k-1)) + (ak / bk)) in this form

This shows, Then split based on whether B is even or odd.

we need to think of the situation what happend when odd/even * odd/even

If B is even, we know if ai*ai+1 is always even, value becomes odd is even*odd, that is case if the last value is odd, if between it get even eventually
If B is odd, we know if the sum of (a0..ak) gives odd, we get odd, else even*odd is even

that all
*/