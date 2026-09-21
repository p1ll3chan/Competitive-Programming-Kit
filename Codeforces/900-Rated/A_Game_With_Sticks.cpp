#include <bits/stdc++.h>
using namespace std;
#define debug(x) cout<<(x)<<endl;
int main(){
        int A,B;cin>>A>>B;
        if(min(A,B)%2==0) cout<<"Malvika"<<endl;
        else cout<<"Akshat"<<endl;
    return 0;
}

/*
Each move removes one horizontal stick and one vertical stick, so exactly one row and one column disappear.
n × m intersection points

Move 1 → remove 1 horizontal + 1 vertical
Move 2 → remove 1 horizontal + 1 vertical
...

Maximum moves = min(n,m)
*/


