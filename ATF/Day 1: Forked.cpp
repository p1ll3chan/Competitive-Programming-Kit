#include <bits/stdc++.h>

using namespace std;
// Question link : https://www.algopath.ai/problems/forked
vector<pair<int,int>> generate_moves(int a,int b){
    vector<pair<int,int>> moves={{a,b},{a,-b},{-a,b},{-a,-b},
                                {b,a},{b,-a},{-b,a},{-b,-a}};
    return moves;
}

int main() {
    int t;cin>>t;
    while(t--){
        int a,b,kx,ky,qx,qy;
        cin>>a>>b;
        cin>>kx>>ky;
        cin>>qx>>qy;

        set<pair<int,int>> king_s,queen_s;
        vector<pair<int,int>> moves = generate_moves(a,b);

        for(auto move:moves){
            int  dx=move.first;
            int dy=move.second;
            king_s.insert({kx+dx,ky+dy});
        }

        for(auto move:moves){
            int  dx=move.first;
            int dy=move.second;
            queen_s.insert({qx+dx,qy+dy});
        }
        int cnt=0;
        for(auto &pos : king_s){
            if(queen_s.count(pos)) cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}