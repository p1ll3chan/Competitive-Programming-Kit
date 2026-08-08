#include <bits/stdc++.h>
using namespace std;

bool cnt_check(int n){
    if(n<2) return true;
    else return false;
}

int main(){
    int n,m;cin>>n>>m;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin>>v[i];
    }

    for (int i = 0; i < v.size()-1; i++){
        if(v[i]==v[i+1]) v.erase(v.begin()+i);
    }
    //cout<<v.size();
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<" ";
    // }


    for (int i = 0; i < m; i++)
    {
        int cnt=0;

        int l,r;cin>>l>>r;
        for (int j = l; j <=r  && j+2 < v.size(); j++)
        {
            if(v[j]<v[j+1] && v[j+1]>v[j+2]) cnt++;

            if(v[j]>v[j+1] && v[j+1]<v[j+2]) {
                cout<<"NO"<<endl;
                return 0;
            }
        }

        if(cnt_check(cnt) && cnt==0) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        

    }
    
    
    return 0;
}