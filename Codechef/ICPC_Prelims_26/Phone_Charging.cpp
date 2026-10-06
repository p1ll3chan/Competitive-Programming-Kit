#include <bits/stdc++.h>
using namespace std;
/*
Problem:A
You want to charge your phone. Its current battery level is 
x percent.

If the current battery level is less than 
80 percent, increasing it by 
1 percent takes 
a seconds.

If the current battery level is at least 
80 percent, increasing it by 
1 percent takes 
b seconds.

Find the total number of seconds needed for the battery level to reach 100 percent.

Input Format
*/

int main() {
	// your code goes here
    int T;cin>>T;
    while(T--){
        int X,A,B;cin>>X>>A>>B;
        if(X<80) cout<<(80-X)*A + 20*B<<endl;
        else cout<<(100-X)*B<<endl;
    }
}
