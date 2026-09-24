#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int LCS(vector<int>& V){
        sort(V.begin(),V.end());
        int max_val=0;
        int cnt=0;
        for (int i = 0; i < V.size()-1; i++)
        {
            if(V[i+1]==V[i]) continue;
            if(V[i+1]==V[i]+1) cnt++;
            else cnt=0;

            max_val=max(max_val,cnt);
        }
        return max_val;
    }
};

int main(){
    //cin.ignore();
    string s;
    getline(cin,s);
    stringstream ss(s);
    vector<int> v;
    while(ss>>s){
        v.push_back(stoi(s));
    }
    

    Solution MySol;
    int ans=MySol.LCS(v);

    cout<<ans+1<<endl;


   
    return 0;
}